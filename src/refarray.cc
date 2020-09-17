template<typename dtype>
RefArray<dtype>::RefArray() {
  if(DEBUG) printf("RefArray::RefArray()\n");
  this->length = 0;
  this->refs   = NULL;
}

template<typename dtype>
RefArray<dtype>::RefArray(const unsigned int n) {
  if(DEBUG) printf("RefArray::RefArray(const unsigned int n)\n");
  try {
  this->refs = new dtype*[n];
  } catch (std::bad_alloc&) {
    printf("\nUNABLE TO ALLOCATE MEMORY\n");
    abort();
  }
  this->length = n;
}

template<typename dtype>
RefArray<dtype>::~RefArray() {
  //https://stackoverflow.com/questions/8289222/delete-a-pointer-array-without-deleting-the-pointed-objects-in-memory
  if(DEBUG) printf("RefArray::~RefArray()\n");
  delete[] this->refs;
  this->refs   = NULL;
  this->length = 0;
}

template<typename dtype>
void RefArray<dtype>::operator= (const dtype v) {
  /*
  Assign a constant value to every element pointed to by the pointers in this->refs
  Called using:
    vec2[vec1] = v; where vec1 is a boolean or int array
  */
  if(DEBUG) printf("RefArray::operator= (const dtype v)\n");
  dtype** this_refs_ptr = this->refs;
  dtype** max_ptr       = this->refs + this->length;
  while(this_refs_ptr < max_ptr) **this_refs_ptr++ = v;
}
template<typename dtype>
void RefArray<dtype>::operator= (const Vine<dtype>& vec) {
  /*
  Copy all values of vec.values into this->values, resizing this->values if necessary
  Called using:
    vec2[vec1] = v; where vec1 is a boolean or int array
  */
  if(DEBUG) printf("RefArray::operator= (const Vine<dtype>& vec)\n");
  if(this->length != vec.length) if(DEBUG) printf("\tERROR: can not assign vine to ref array of mismatched length (%u vs. %u)\n", this->length, vec.length);
  dtype** max_ptr       = this->refs + this->length;
  dtype** this_refs_ptr = this->refs;
  dtype* vec_vals_ptr   = vec.values;
  while(this_refs_ptr < max_ptr) **this_refs_ptr++ = *vec_vals_ptr++;
}

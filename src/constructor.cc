template<typename dtype>
Vine<dtype>::Vine(){
  /*
  Default constructor
  Construct a Vine with NULL values pointer and 0 length
  Called using:
    Vine<dtype> vec;
    Vine<dtype> array[100];                //each element is initialized using default constructor
    Vine<dtype>* array = new[Vine<dtype>]; //each element is initialized using default constructor
    NOT: Vine<dtype> vec();                //interpreted as function declaration by compiler

  */
  if(DEBUG) printf("Vine::Vine()\n");
  this->values = NULL;
  this->length = 0;
}

template<typename dtype>
Vine<dtype>::Vine(const unsigned int n) {
  /*
  Construct a Vine with length n and a values array with n elements set to 0
  Called using:
    Vine<dtype> vec(n);
  */
  if(DEBUG) printf("Vine::Vine(const unsigned int n)\n");

  try { //only 5mic slower with try/catch block
  this->values = new dtype[n]; //140mic with (), 0.5 without
  } catch (std::bad_alloc&) {
    printf("\nUNABLE TO ALLOCATE MEMORY\n");
    abort();
  }
  this->length = n;
}

template<typename dtype>
Vine<dtype>::Vine(const dtype v, const unsigned int n) : Vine<dtype>::Vine(n) {
  /*
  Construct a Vine with length n and a values array with n elements set to v
  Called using:
    Vine<dtype> vec(v, n);
  */
  if(DEBUG) printf("Vine::Vine(const dtype v, const unsigned int n)\n");
  dtype* this_vals_ptr = this->values;
  dtype* const max_ptr = this->values + n;
  while(this_vals_ptr < max_ptr) *this_vals_ptr++ = v;
}

template<typename dtype>
Vine<dtype>::Vine(const Vine<dtype>& vec) : Vine<dtype>::Vine(vec.length) {
  /*
  Construct a Vine with length and values equal to vec (deep copy though, no memory is shared)
  Called using:
    Vine<dtype> vec2(vec1);
    Vine<dtype> vec2 = vec1;
    Vine<dtype> vec2 = vec1 + v; etc.
  */
  if(DEBUG) printf("Vine::Vine(const Vine<dtype>& vec)\n");
  memcpy(this->values, vec.values, vec.length*sizeof(dtype));
}

template<typename dtype>
Vine<dtype>::Vine(const RefArray<dtype>& refarr) : Vine<dtype>::Vine(refarr.length) {
  /*
  Construct a Vine with length and values equal to refarr (deep copy though, no memory is shared)
  Called using:
    Vine<dtype> vec3 = vec2[some_index_vec];
  */
  if(DEBUG) printf("Vine::Vine(const RefArray<dtype>& refarr)\n");
  dtype** const max_ptr = refarr.refs + refarr.length;
  dtype** refs_ptr      = refarr.refs;
  dtype* this_vals_ptr  = this->values;
  while(refs_ptr < max_ptr) *this_vals_ptr++ = **refs_ptr++;
}

template<typename dtype>
Vine<dtype>::Vine(std::initializer_list<dtype> values_list) : Vine<dtype>::Vine(values_list.size()) {
  /*
  Construct a Vine with length and values equal to the initializer list
  Called using:
    Vine<dtype> vec3 = {4, -5, 901}; etc.
  */
  dtype* this_vals_ptr       = this->values;
  const dtype* list_vals_ptr = values_list.begin();
  const dtype* const max_ptr = list_vals_ptr + values_list.size();
  while(list_vals_ptr < max_ptr) *this_vals_ptr++ = *list_vals_ptr++;
}

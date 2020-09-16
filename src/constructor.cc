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
  if(DEBUG) printf("Vine()\n");
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
  if(DEBUG) printf("Vine(const unsigned int n)\n");
  try {
  this->values = new dtype[n]();
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
  if(DEBUG) printf("Vine(const dtype v, const unsigned int n)\n");
  dtype* this_vals_ptr = this->values;
  dtype* max_ptr       = this->values + n;
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
  if(DEBUG) printf("Vine(const Vine<dtype>& vec)\n");
  memcpy(this->values, vec.values, vec.length*sizeof(dtype));
}

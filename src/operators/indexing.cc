template<typename dtype>
dtype Vine<dtype>::operator[] (const unsigned int i) const {
  /*
  Return the value at position i in this->values
  */
  //if(DEBUG) printf("Vine::operator[%u]\n", i);
  return this->values[i];
}
template<typename dtype>
dtype& Vine<dtype>::operator[] (const unsigned int i) {
  /*
  Return a reference to the value at position i in this->values
  */
  //if(DEBUG) printf("Vine::&operator[%u]\n", i);
  return this->values[i];
}


template<typename dtype>
RefArray<dtype> Vine<dtype>::operator[] (const Vine<unsigned int>& indexes) const {
  /*
  Return a RefArray containing pointers to the indexed values
  */
  if(DEBUG) printf("Vine::operator[const Vine<unsigned int>& indexes]\n");
  RefArray<dtype> refarr(indexes.length);
  dtype* this_vals_ptr = this->values;
  dtype* indexes_ptr   = indexes.values;
  dtype** refs_ptr     = refarr.refs;
  dtype* max_ptr       = this_vals_ptr + this->length;
  while(this_vals_ptr < max_ptr) *refs_ptr++ = this_vals_ptr + *indexes_ptr++;
  return refarr;
}

template<typename dtype>
RefArray<dtype> Vine<dtype>::operator[] (const Vine<bool>& indexes) const {
  /*
  Return a RefArray containing pointers to the indexed values
  */
  if(DEBUG) printf("Vine::operator[const Vine<unsigned int>& indexes]\n");
  RefArray<dtype> refarr(indexes.length);
  dtype** refs_ptr     = refarr.refs;
  dtype* this_vals_ptr = this->values;
  bool* indexes_ptr    = indexes.values;
  dtype* max_ptr       = this->values + this->length;
  while(this_vals_ptr < max_ptr) {
    if(*indexes_ptr++) {
      *refs_ptr++ = this_vals_ptr;
    } else {
      refarr.length--;
    }
    this_vals_ptr++;
  }
  return refarr;
}

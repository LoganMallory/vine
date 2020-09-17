template<typename dtype>
Vine<bool> Vine<dtype>::operator> (const dtype v) const {
  /*
  Compare every value in this->values to the constant v and store boolean result in a new array which is returned
  Called using:
    vec1 > v;
  */
  if(DEBUG) printf("Vine::operator> (const dtype v)\n");
  Vine<bool> newvec = (this->length);
  dtype* this_vals_ptr = this->values;
  bool* new_vals_ptr   = newvec.values;
  dtype* max_ptr       = this->values + this->length;
  while(this_vals_ptr < max_ptr) *new_vals_ptr++ = ((v - *this_vals_ptr++) >> 31) & 1;
  return newvec;
}

template<typename dtype>
Vine<bool> Vine<dtype>::operator> (const Vine<dtype>& vec) const {
  /*
  Compare every this->values to vec.values and store boolean result in a new array which is returned
  Called using:
    vec1 > vec2;
  */
  if(DEBUG) printf("Vine::operator> (const Vine<dtype>& vec)\n");
  Vine<bool> newvec(this->length);
  dtype* this_vals_ptr = this->values;
  dtype* vec_vals_ptr  = vec.values;
  bool* new_vals_ptr   = newvec.values;
  dtype* max_ptr       = this->values + this->length;
  while(this_vals_ptr < max_ptr) *new_vals_ptr++ = ((*vec_vals_ptr++ - *this_vals_ptr++) >> 31) & 1;
  return newvec;
}


template<typename dtype>
Vine<bool> Vine<dtype>::operator>= (const dtype v) const {
  /*
  Compare every value in this->values to the constant v and store boolean result in a new array which is returned
  Called using:
    vec1 >= v;
  */
  if(DEBUG) printf("Vine::operator>= (const dtype v)\n");
  Vine<bool> newvec(this->length);
  dtype* this_vals_ptr = this->values;
  bool* new_vals_ptr   = newvec.values;
  dtype* max_ptr       = this->values + this->length;
  while(this_vals_ptr < max_ptr) *new_vals_ptr++ = (((*this_vals_ptr++ - v) >> 31) & 1) ^ 1;
  return newvec;
}

template<typename dtype>
Vine<bool> Vine<dtype>::operator>= (const Vine<dtype>& vec) const {
  /*
  Compare every this->values to vec.values and store boolean result in a new array which is returned
  Called using:
    vec1 >= vec2;
  */
  if(DEBUG) printf("Vine::operator>= (const Vine<dtype>& vec\n");
  Vine<bool> newvec(this->length);
  dtype* this_vals_ptr = this->values;
  dtype* vec_vals_ptr  = vec.values;
  bool* new_vals_ptr   = newvec.values;
  dtype* max_ptr       = this->values + this->length;
  while(this_vals_ptr < max_ptr) *new_vals_ptr++ = (((*this_vals_ptr++ - *vec_vals_ptr++) >> 31) & 1) ^ 1;
  return newvec;
}

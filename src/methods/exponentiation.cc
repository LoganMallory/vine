template<typename dtype>
Vine<dtype>& Vine<dtype>::pow(const unsigned int p) const {
  if(DEBUG) printf("Vine::pow(const unsigned int p)\n");
  Vine<dtype> newvec(this->length);
  dtype* this_vals_ptr = this->values;
  dtype* max_ptr       = this_vals_ptr + this->length;
  dtype* new_vals_ptr  = newvec.values;

  while(this_vals_ptr < max_ptr) {
    dtype u = v = *this_vals_ptr++;
    for(unsigned int i=1; i < p; i++) u *= v;
    *new_vals_ptr++ = u;
  }
  return newvec;
}
template<typename dtype>
void Vine<dtype>::pow(const unsigned int p, bool inplace) const {
  if(DEBUG) printf("Vine::pow(const unsigned int p, bool inplace)\n");
  dtype* this_vals_ptr = this->values;
  dtype* const max_ptr = this_vals_ptr + this->length;

  while(this_vals_ptr < max_ptr) {
    dtype u = v = *this_vals_ptr;
    for(unsigned int i=1; i < p; i++) u *= v;
    *this_vals_ptr++ = u;
  }
}

template<typename dtype>
Vine<dtype>& Vine<unsigned int>::pow(const Vine<unsigned int>& vec) const {
  if(DEBUG) printf("Vine::pow(const Vine<unsigned int>& vec)\n");
  Vine<dtype> newvec(this->length);
  dtype* this_vals_ptr       = this->values;
  dtype* const max_ptr       = this_vals_ptr + this->length;
  unsigned int* vec_vals_ptr = vec.values;
  dtype* new_vals_ptr        = newvec.values;

  while(this_vals_ptr < max_ptr) {
    dtype u = v = *this_vals_ptr++;
    for(unsigned int i=1; i < *vec_vals_ptr++; i++) u *= v;
    *new_vals_ptr++ = u;
  }
  return newvec;
}
template<typename dtype>
void Vine<dtype>::pow(const Vine<unsigned int>& vec, bool inplace) const {
  if(DEBUG) printf("Vine::pow(const Vine<unsigned int>& vec, bool inplace)\n");
  dtype* this_vals_ptr       = this->values;
  dtype* max_ptr             = this_vals_ptr + this->length;
  unsigned int* vec_vals_ptr = vec.values;

  while(this_vals_ptr < max_ptr) {
    dtype u = v = *this_vals_ptr;
    for(unsigned int i=1; i < *vec_vals_ptr++; i++) u *= v;
    *this_vals_ptr++ = u;
  }
}

Vine<dtype> Vine<dtype>::operator% (const dtype v) const {
  /*
  Compute values modulo v for every value in this->values and return results in new Vine
  */
  if(DEBUG) printf("Vine::operator% (const dtype v)\n");
  Vine<dtype> newvec(this->length);
  dtype* this_vals_ptr  = this->values;
  dtype* new_vals_ptr   = newvec.values;
  dtype* const max_ptr  = this_vals_ptr + this->length;
  while(this_vals_ptr < max_ptr) *new_vals_ptr++ = *this_vals_ptr++ % v;
  return newvec;
}
Vine<dtype> Vine<dtype>::operator% (const Vine<dtype>& vec) const {
  /*
  Compute values modulo vec.values for every value in this->values and return results in new Vine
  */
  if(DEBUG) printf("Vine::operator% (const Vine<dtype>& vec)\n");
  Vine<dtype> newvec(this->length);
  dtype* this_vals_ptr  = this->values;
  dtype* vec_vals_ptr   = vec.values;
  dtype* new_vals_ptr   = newvec.values;
  dtype* const max_ptr  = this_vals_ptr + this->length;
  while(this_vals_ptr < max_ptr) *new_vals_ptr++ = *this_vals_ptr++ % *vec_vals_ptr++;
  return newvec;
}
void Vine<dtype>::operator%= (const dtype v) const {
  /*
  Compute values modulo v for every value in this->values, inplace
  */
  if(DEBUG) printf("Vine::operator%= (const dtype v)\n");
  dtype* this_vals_ptr  = this->values;
  dtype* const max_ptr  = this_vals_ptr + this->length;
  while(this_vals_ptr < max_ptr) *this_vals_ptr++ %= v;
}
void Vine<dtype>::operator%= (const Vine<dtype>& vec) const {
  /*
  Compute values modulo vec.values for every value in this->values, inplace
  */
  if(DEBUG) printf("Vine::operator%= (const dtype v)\n");
  dtype* this_vals_ptr  = this->values;
  dtype* vec_vals_ptr   = vec.values;
  dtype* const max_ptr  = this_vals_ptr + this->length;
  while(this_vals_ptr < max_ptr) *this_vals_ptr++ %= *vec_vals_ptr++;
}

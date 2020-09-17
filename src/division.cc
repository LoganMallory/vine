template<typename dtype>
Vine<dtype> Vine<dtype>::operator/ (const dtype v) const {
  if(DEBUG) printf("Vine::operator/ (const dtype v)\n");
  Vine<dtype> newvec(this->length);
  dtype* this_vals_ptr  = this->values;
  dtype* new_vals_ptr   = newvec.values;
  dtype* max_ptr        = this_vals_ptr + this->length;
  while(this_vals_ptr < max_ptr) *new_vals_ptr++ = *this_vals_ptr++ / v;
  return newvec;
}
template<typename dtype>
Vine<dtype> Vine<dtype>::operator/ (const Vine<dtype>& vec) const {
  if(DEBUG) printf("Vine::operator/ (const Vine<dtype>& vec)\n");
  Vine<dtype> newvec(this->length);
  dtype* this_vals_ptr  = this->values;
  dtype* vec_vals_ptr   = vec.values;
  dtype* new_vals_ptr   = newvec.values;
  dtype* max_ptr        = this->values + this->length;
  while(this_vals_ptr < max_ptr) *new_vals_ptr++ = *this_vals_ptr++ / *vec_vals_ptr++;
  return newvec;
}
template<typename dtype>
void Vine<dtype>::operator/= (const dtype v) {
  if(DEBUG) printf("Vine::operator*= (const dtype v)\n");
  dtype* this_vals_ptr = this->values;
  dtype* max_ptr       = this->values + this->length;
  while(this_vals_ptr < max_ptr) *this_vals_ptr++ /= v;
}
template<typename dtype>
void Vine<dtype>::operator/= (const Vine<dtype>& vec) {
  if(DEBUG) printf("Vine::operator/= (const Vine<dtype>& vec)\n");
  dtype* this_vals_ptr  = this->values;
  dtype* vec_vals_ptr   = vec.values;
  dtype* max_ptr = this->values + this->length;
  while(this_vals_ptr < max_ptr) *this_vals_ptr++ /= *vec_vals_ptr++;
}

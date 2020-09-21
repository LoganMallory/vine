template<typename dtype>
void Vine<dtype>::operator= (const dtype v) const {
  /*
  Assign a constant value to every element of this->values
  Called using:
    vec = v;
  */
  if(DEBUG) printf("Vine::operator= (const dtype v)\n");
  dtype* this_vals_ptr = this->values;
  dtype* const max_ptr = this_vals_ptr + this->length;
  while(this_vals_ptr < max_ptr) *this_vals_ptr++ = v;
}
template<typename dtype>
void Vine<dtype>::operator= (const Vine<dtype>& vec) const {
  /*
  Copy all values of vec.values into this->values, resizing this->values if necessary
  Called using:
    vec2 = vec1;
    NOT: Vine<int> vec2 = vec1; (copy constructor called instead)
  */
  if(DEBUG) printf("Vine::operator= (const Vine<dtype>& vec)\n");
  dtype* this_vals_ptr = this->values;
  dtype* vec_vals_ptr  = vec.values;
  dtype* const max_ptr = this_vals_ptr + this->length;
  while(this_vals_ptr < max_ptr) *this_vals_ptr++ = *vec_vals_ptr++;
}

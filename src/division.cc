template<typename dtype>
Vine<dtype>& Vine<dtype>::operator/ (const dtype v) const {
  if(DEBUG) printf("Vine::operator/ (const dtype v)\n");
  Vine<dtype>* newvec = new Vine<dtype>(this->length);
  dtype* this_vals_ptr;
  dtype* new_vals_ptr;
  switch (OPT_LVL) {
    case 0:
      for(unsigned int i=0; i < this->length; i++) newvec->values[i] = this->values[i] / v;
      break;
    case 1:
      this_vals_ptr = this->values;
      new_vals_ptr  = newvec->values;
      for(unsigned int i=0; i < this->length; i++) *new_vals_ptr++ = *this_vals_ptr++ / v;
      break;
    case 2:
      this_vals_ptr  = this->values;
      new_vals_ptr   = newvec->values;
      dtype* max_ptr = this_vals_ptr + this->length;
      while(this_vals_ptr < max_ptr) *new_vals_ptr++ = *this_vals_ptr++ / v;
      break;
  }
  return *newvec;
}
template<typename dtype>
Vine<dtype>& Vine<dtype>::operator/ (const Vine<dtype>& vec) const {
  if(DEBUG) printf("Vine::operator/ (const Vine<dtype>& vec)\n");
  Vine<dtype>* newvec = new Vine<dtype>(this->length);
  dtype* this_vals_ptr;
  dtype* vec_vals_ptr;
  dtype* new_vals_ptr;
  switch (OPT_LVL) {
    case 0:
      for(unsigned int i=0; i < this->length; i++) newvec->values[i] = this->values[i] / vec.values[i];
      break;
    case 1:
      this_vals_ptr = this->values;
      vec_vals_ptr  = vec.values;
      new_vals_ptr  = newvec->values;
      for(unsigned int i=0; i < this->length; i++) *new_vals_ptr++ = *this_vals_ptr++ / *vec_vals_ptr++;
      break;
    case 2:
      this_vals_ptr  = this->values;
      vec_vals_ptr   = vec.values;
      new_vals_ptr   = newvec->values;
      dtype* max_ptr = this->values + this->length;
      while(this_vals_ptr < max_ptr) *new_vals_ptr++ = *this_vals_ptr++ / *vec_vals_ptr++;
      break;
  }
  return *newvec;
}
template<typename dtype>
void Vine<dtype>::operator/= (const dtype v) {
  if(DEBUG) printf("Vine::operator*= (const dtype v)\n");
  dtype* this_vals_ptr;
  switch (OPT_LVL) {
    case 0:
      for(unsigned int i=0; i < this->length; i++) this->values[i] /= v;
      break;
      case 1:
        this_vals_ptr = this->values;
        for(unsigned int i=0; i < this->length; i++) *this_vals_ptr++ /= v;
        break;
      case 2:
        this_vals_ptr = this->values;
        dtype* max_ptr       = this->values + this->length;
        while(this_vals_ptr < max_ptr) *this_vals_ptr++ /= v;
        break;
  }
}
template<typename dtype>
void Vine<dtype>::operator/= (const Vine<dtype>& vec) {
  if(DEBUG) printf("Vine::operator/= (const Vine<dtype>& vec)\n");
  dtype* this_vals_ptr;
  dtype* vec_vals_ptr;
  switch (OPT_LVL) {
    case 0:
      for(unsigned int i=0; i < this->length; i++) this->values[i] /= vec.values[i];
      break;
    case 1:
      this_vals_ptr = this->values;
      vec_vals_ptr  = vec.values;
      for(unsigned int i=0; i < this->length; i++) *this_vals_ptr++ /= *vec_vals_ptr++;
      break;
    case 2:
      this_vals_ptr  = this->values;
      vec_vals_ptr   = vec.values;
      dtype* max_ptr = this->values + this->length;
      while(this_vals_ptr < max_ptr) *this_vals_ptr++ /= *vec_vals_ptr++;
      break;
    }
}

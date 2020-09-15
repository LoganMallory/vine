template<typename dtype>
void Vine<dtype>::operator= (const dtype v) {
  /*
  Assign a constant value to every element of this->values
  Called using:
    vec = v;
  */
  if(DEBUG) printf("Vine::operator= (const dtype v)\n");
  switch (OPT_LVL) {
    case 0:
      //150mic -O3
      for(unsigned int i=0; i < this->length; i++) this->values[i] = v;
      break;
    case 1:
      //50mic -O3
      std::fill(this->values, this->values+this->length, v);
      break;
    case 2:
      //50mic -O3
      dtype* this_vals_ptr = this->values;
      dtype* max_ptr       = this->values + this->length;
      while(this_vals_ptr < max_ptr) *this_vals_ptr++ = v;
      break;
  }
}
template<typename dtype>
Vine<dtype>& Vine<dtype>::operator= (const Vine<dtype>& vec) {
  /*
  Copy all values of vec.values into this->values, resizing this->values if necessary
  Called using:
    vec2 = vec1;
    NOT: Vine<int> vec2 = vec1; (conversion constructor called instead)
  */
  if(DEBUG) printf("Vine::operator= (const Vine<dtype>& vec)\n");
  //lengths don't match, so reallocate memory to match (values will be copied over by switch statement logic)
  if(this->length != vec.length){
    if(DEBUG) printf("\tResizing :this: to match vec\n");
    this->values = static_cast<dtype*>(realloc(this->values, sizeof(dtype)*vec.length));
    this->length = vec.length;
  }
  switch (OPT_LVL) {
    case 0:
      //360mic -O3
      for(unsigned int i=0; i < this->length; i++) this->values[i] = vec.values[i];
      break;
    case 1:
      //75mic -O3
      memcpy(this->values, vec.values, this->length*sizeof(dtype));
      break;
    case 2:
      //85mic -O3
      dtype* max_ptr       = this->values + this->length;
      dtype* this_vals_ptr = this->values;
      dtype* vec_vals_ptr  = vec.values;
      while(this_vals_ptr < max_ptr) *this_vals_ptr++ = *vec_vals_ptr++;
      break;
  }
  return *this;
}

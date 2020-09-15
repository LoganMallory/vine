template<typename dtype>
Vine<bool>& Vine<dtype>::operator== (const dtype v) const {
  /*
  Compare every value in this->values to the constant v and store boolean result in a new array which is returned
  Called using:
    vec1 == v;
  */
  if(DEBUG) printf("Vine::operator== (const dtype v)\n");
  Vine<bool>* newvec = new Vine<bool>(this->length);
  switch (OPT_LVL) {
    case 0:
      //
      for(unsigned int i=0; i < this->length; i++) if(this->values[i] == v) newvec->values[i] = true;
      break;
    case 1:
      //
      for(unsigned int i=0; i < this->length; i++) newvec->values[i] = this->values[i] == v;
      break;
    case 2:
      //
      dtype* this_vals_ptr = this->values;
      bool* new_vals_ptr   = newvec->values;
      for(unsigned int i=0; i < this->length; i++) *new_vals_ptr++ = *this_vals_ptr++ == v;
      break;
  }
  return *newvec;
}

template<typename dtype>
Vine<bool>& Vine<dtype>::operator== (const Vine<dtype>& vec) const {
  /*
  Compare every this->values to vec.values and store boolean result in a new array which is returned
  Called using:
    vec1 == vec2;
  */
  if(DEBUG) printf("Vine::operator== (const Vine<dtype>& vec)\n");
  if(this->length != vec.length) printf("\tERROR: Should not compare Vines of different length (%u vs. %u) -- comparing values up to this->length\n", this->length, vec.length);
  Vine<bool>* newvec = new Vine<bool>(this->length);
  switch (OPT_LVL) {
    case 0:
      //
      for(unsigned int i=0; i < this->length; i++) if(this->values[i] == vec.values[i]) newvec->values[i] = true;
      break;
    case 1:
      //
      for(unsigned int i=0; i < this->length; i++) newvec->values[i] = this->values[i] == vec.values[i];
      break;
    case 2:
      //
      dtype* this_vals_ptr = this->values;
      dtype* vec_vals_ptr  = vec.values;
      bool* new_vals_ptr   = newvec->values;
      for(unsigned int i=0; i < this->length; i++) *new_vals_ptr++ = *this_vals_ptr++ == *vec_vals_ptr++;
      break;
  }
  return *newvec;
}

template<typename dtype>
Vine<bool>& Vine<dtype>::operator!= (const dtype v) const {
  /*
  Compare every value in this->values to the constant v and store boolean result in a new array which is returned
  Called using:
    vec != v;
  */
  if(DEBUG) printf("Vine::operator!= (const dtype v)\n");
  Vine<bool>* newvec = new Vine<bool>(this->length);
  switch (OPT_LVL) {
    case 0:
      //
      for(unsigned int i=0; i < this->length; i++) if(this->values[i] != v) newvec->values[i] = true;
      break;
    case 1:
      //
      for(unsigned int i=0; i < this->length; i++) newvec->values[i] = this->values[i] != v;
      break;
    case 2:
      //
      dtype* this_vals_ptr = this->values;
      bool* new_vals_ptr   = newvec->values;
      for(unsigned int i=0; i < this->length; i++) *new_vals_ptr++ = *this_vals_ptr++ != v;
      break;
  }
  return *newvec;
}

template<typename dtype>
Vine<bool>& Vine<dtype>::operator!= (const Vine<dtype>& vec) const {
  /*
  Compare every this->values to vec.values and store boolean result in a new array which is returned
  Called using:
    vec1 != vec2;
  */
  if(DEBUG) printf("Vine::operator!= (const Vine<dtype>& vec)\n");
  if(this->length != vec.length) printf("\tERROR: Should not compare Vines of different length (%u vs. %u) -- comparing values up to this->length\n", this->length, vec.length);
  Vine<bool>* newvec = new Vine<bool>(this->length);
  switch (OPT_LVL) {
    case 0:
      //
      for(unsigned int i=0; i < this->length; i++) if(this->values[i] != vec.values[i]) newvec->values[i] = true;
      break;
    case 1:
      //
      for(unsigned int i=0; i < this->length; i++) newvec->values[i] = this->values[i] != vec.values[i];
      break;
    case 2:
      //
      dtype* this_vals_ptr = this->values;
      dtype* vec_vals_ptr  = vec.values;
      bool* new_vals_ptr   = newvec->values;
      for(unsigned int i=0; i < this->length; i++) *new_vals_ptr++ = *this_vals_ptr++ != *vec_vals_ptr++;
      break;
  }
  return *newvec;
}

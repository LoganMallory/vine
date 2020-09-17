template<typename dtype>
Vine<bool> Vine<dtype>::operator> (const dtype v) const {
  /*
  Compare every value in this->values to the constant v and store boolean result in a new array which is returned
  Called using:
    vec1 > v;
  */
  if(DEBUG) printf("Vine::operator> (const dtype v)\n");
  Vine<bool> newvec = (this->length);
  for(unsigned int i=0; i < this->length; i++) newvec.values[i] = (v - this->values[i]) >> 31;
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
  for(unsigned int i=0; i < this->length; i++) newvec.values[i] = (vec.values[i] - this->values[i]) >> 31;
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
  for(unsigned int i=0; i < this->length; i++) newvec.values[i] = ((this->values[i] - v) >> 31) ^ 1;
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
  for(unsigned int i=0; i < this->length; i++) newvec.values[i] = ((this->values[i] - vec.values[i]) >> 31) ^ 1;
  return newvec;
}

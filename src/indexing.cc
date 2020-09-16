template<typename dtype>
dtype Vine<dtype>::operator[] (const unsigned int i) const {
  /*
  Return the value at position i in this->values
  */
  //if(DEBUG) printf("Vine::operator[%u]\n", i);
  switch (OPT_LVL) {
    case 0:
      return this->values[i];
      break;
    case 1:
      return *(this->values+i);
      break;
    case 2:
      return *(this->values+i);
      break;
  }
  return 0;
}
template<typename dtype>
dtype& Vine<dtype>::operator[] (const unsigned int i) {
  /*
  Return a reference to the value at position i in this->values
  */
  //if(DEBUG) printf("Vine::&operator[%u]\n", i);
  switch (OPT_LVL) {
    case 0:
      return this->values[i];
      break;
    case 1:
      return *(this->values+i);
      break;
    case 2:
      return *(this->values+i);
      break;
  }
  return this->values[0];
}

template<typename dtype>
Vine<dtype> operator[] (const Vine<unsigned int>& indexes) const {
  
}

template<typename dtype>
Vine<dtype> operator[] (const Vine<unsigned int>& indexes);       //setting

template<typename dtype>
Vine<dtype> operator[] (const Vine<bool>& indexes) const;         //getting

template<typename dtype>
Vine<dtype> operator[] (const Vine<bool>& indexes);               //setting

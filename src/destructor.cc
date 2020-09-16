template<typename dtype>
Vine<dtype>::~Vine(){
  /*
  Destruct a Vine object
  Called using:
    Vine.~Vine();
    Vine->~Vine();
    Automatically when a Vine object goes out of scope
  */
  if(DEBUG) printf("Vine::~Vine()\n");
  delete[] this->values;
  this->length = 0;
  this->values = NULL;
}

template<typename dtype>
void Vine<dtype>::print() {
  printf("[ ");
  for(unsigned int i=0; i < this->length; i++) printf(print_fmt, this->values[i]);
  printf("]\n");
}

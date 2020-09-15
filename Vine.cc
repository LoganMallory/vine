template<> const char* Vine<int>::read_fmt           = "%d,";
template<> const char* Vine<unsigned int>::read_fmt  = "%u,";
template<> const char* Vine<long>::read_fmt          = "%ld,";
template<> const char* Vine<unsigned long>::read_fmt = "%lu,";
template<> const char* Vine<float>::read_fmt         = "%f,";
template<> const char* Vine<double>::read_fmt        = "%lf,";

template<> const char* Vine<int>::print_fmt           = "%-4d";
template<> const char* Vine<unsigned int>::print_fmt  = "%-4u";
template<> const char* Vine<long>::print_fmt          = "%-4ld";
template<> const char* Vine<unsigned long>::print_fmt = "%-4lu";
template<> const char* Vine<float>::print_fmt         = "%-6.2f";
template<> const char* Vine<double>::print_fmt        = "%-6.2lf";

#include "src/vine/constructor.cc"
#include "src/vine/destructor.cc"
#include "src/vine/assignment.cc"
#include "src/vine/indexing.cc"
#include "src/vine/equality.cc"
#include "src/vine/greaterthan.cc"
#include "src/vine/lessthan.cc"
#include "src/vine/addition.cc"
#include "src/vine/subtraction.cc"
#include "src/vine/multiplication.cc"
#include "src/vine/division.cc"





//exponentiation TODO: make this XOR (>> will be exponentiation, << will be log)
template<typename dtype>
Vine<dtype>& Vine<dtype>::operator^ (const dtype v) const {
  if(DEBUG) printf("Vine::operator^ (const dtype v)\n");
  Vine<dtype>* newvec = new Vine<dtype>(this->length);
  for(unsigned int i=0; i < this->length; i++){
    newvec->values[i] = this->values[i];
    for(unsigned int j=0; j < v-1; j++) newvec->values[i] *= this->values[i];
  }
  return *newvec;
}
template<typename dtype>
Vine<dtype>& Vine<dtype>::operator^ (const Vine<dtype>& vec) const {
  if(DEBUG) printf("Vine::operator^ (const Vine<dtype>& vec)\n");
  Vine<dtype>* newvec = new Vine<dtype>(this->length);
  for(unsigned int i=0; i < this->length; i++){
    newvec->values[i] = this->values[i];
    for(unsigned int j=0; j<vec.values[i]-1; j++) newvec->values[i] *= this->values[i];
  }
  return newvec;
}
template<typename dtype>
void Vine<dtype>::operator^= (const dtype v) {
  if(DEBUG) printf("Vine::operator^= (const dtype v)\n");
  for(unsigned int i=0; i < this->length; i++){
    dtype base = this->values[i];
    for(unsigned int j=0; j < v-1; j++) this->values[i] *= base;
  }
}
template<typename dtype>
void Vine<dtype>::operator^= (const Vine<dtype>& vec) {
  if(DEBUG) printf("Vine::operator^= (const Vine<dtype>& vec)\n");
  for(unsigned int i=0; i<this->length; i++){
    dtype base = this->values[i];
    for(unsigned int j=0; j < vec.values[i]-1; j++) this->values[i] *= base;
  }
}


//methods
template<typename dtype>
void Vine<dtype>::print() {
  printf("[ ");
  for(unsigned int i=0; i < this->length; i++) printf(print_fmt, this->values[i]);
  printf("]");
}

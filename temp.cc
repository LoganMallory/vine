const int DEBUG   = 1;
const OPT_LVL = 0;
#include "Vine.h"

Vine<int> make_vine() {
  Vine<int> vec(5, 10); //value 5, length 10
  printf("vec.length = %u\nvec.values[0] = %d\n", vec.length, vec.values[0]);
  return vec;
}

void make_edit(Vine<int>& vec) {
  vec[0] = 91;
}

int main() {
  Vine<int> myvine = make_vine();
  printf("myvine.values[0] = %d\n", myvine.values[0]);
  make_edit(myvine);
  printf("myvine.values[0] = %d\n", myvine.values[0]);
  return 0;
}
/*
A common flow is:
  Vine<int> vec2 = vec1 + v;
  vec1+v invokes operator+
  operator+ creates new Vine newvec*, returns dereferenced obejct (*newvec)
  conversion constructor for vec2 is called (with newvec as arg)
  values from newvec are copied into vec2.values

  the question: is newvec and newvec.values ever deleted (and memory freed)?
  if not, then vine conversion constructor would have to consume and destroy vine arg

TODO: Vine<int> vec2 = vec1   should become    Vine<int> vec2 = vec1[];                                                 //Vine(const Vine<dtype>& vec)

TODO: vec2 = vec1 + 9         should become    now consume newvec (point to its values, set its values pointer to null) //operator=
TODO: make Vine(unsigned int/int) explicit so that Vine<int> vec = 5 is a compiler error

TODO: it is illegal to use realloc on an array created by new
*/

const int DEBUG   = 1;
const int OPT_LVL = 0;
#include "Vine.h"

int main() {
  Vine<int> vec1(5, 10);
  vec1.print();

  Vine<int> vec2 = vec1 + 1;
  vec2.print();

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

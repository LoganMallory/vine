const int DEBUG   = 1;
const int OPT_LVL = 0;
#include "../Vine.h"

//this program shows how the copy constructor is not called, which means the compiler is using RVO
int main() {
  Vine<int> vec1(5, 10);
  vec1.print();

  Vine<int> vec2 = vec1 + 1;
  vec2.print();

  return 0;
}
/*
TODO:
  Vine<int> vec2 = vec1 + v;
  returns newvec using return value optimization (RVO - avoids copy constuctor, does work at address of vec2)
  this is compiler dependent however, and in the case that the compiler decides not to use RVO,
  newvec will be copied and then destructed upon return, thus deleting the values array that vec2 thinks still exists.
  How can this be addressed?

TODO: make Vine(unsigned int/int) explicit so that Vine<int> vec = 5 is a compiler error

TODO: list initializer (https://stackoverflow.com/questions/26391745/custom-array-class-constructor-for-initialization-of-list)
*/

#include <stdio.h>
const int DEBUG = 1;
#include "../Vine.h"

//shows that the program won't compile if trying to compare Vines of different types
int main() {
  Vine<int> vec1(5, 10);
  vec1.print();

  Vine<unsigned int> vec2(5, 10);
  vec2.print();

  Vine<bool> vec3 = vec1 == vec2; //error: invalid operands to binary expression ('Vine<int>' and 'Vine<unsigned int>')
  vec3.print();
  return 0;
}

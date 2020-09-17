const int DEBUG = 1;
#include "../Vine.h"

int main() {
  Vine<int> vec1(5, 10);
  for(int i=0; i < vec1.length; i++) vec1[i] = i;

  int a = 1;
  printf("vec1[%d] = %d\n", a, vec1[a]);

  float b = 2.8;
  printf("vec1[%2.f] = %d\n", b, vec1[b]); //vec1[ 3] = 2 (note the mismatch - float 2.8 is truncated to 2 when passed to operator[], but rounded to 3 by printf)

  size_t c = 4;
  printf("vec1[%lu] = %d\n", c, vec1[c]);

  unsigned long d = 2;
  printf("vec1[%lu] = %d\n", d, vec1[d]);

  return 0;
}

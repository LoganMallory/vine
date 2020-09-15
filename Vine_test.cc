const int OPT_LVL    = 0;
const int TEST_DEBUG = 1;
#include "Vine.h"
#include <assert.h>
#include "tests/vine/constructor.cc"  //done
#include "tests/vine/destructor.cc"   //done
#include "tests/vine/assignment.cc"   //done
#include "tests/vine/indexing.cc"     //done
#include "tests/vine/equality.cc"     //done
#include "tests/vine/greaterthan.cc"  //done
#include "tests/vine/lessthan.cc"     //done
#include "tests/vine/addition.cc"     //done
#include "tests/vine/subtraction.cc"
#include "tests/vine/multiplication.cc"
#include "tests/vine/division.cc"

//TODO: check that address of this->values changes when new object is returned in some operators
//TODO: assert that errors are thrown when doing math on two Vines of different dimensions

//handle overflow -- only called if compiled using -ftrapv
void overflow_handler(int sig) {
  printf("Overflow detected\n");
  //abort the entire program
  abort();
}
int main(){
  signal(SIGILL, &overflow_handler);
  unsigned int size = 1000; //size >= 2

  test_constructor(size);
  test_destructor(size);
  test_assignment(size);
  test_indexing(size);
  test_greater_than(size);
  test_less_than(size);
  test_addition(size);
  test_subtraction(size);
  test_multiplication(size);
  test_division(size);
  test_equality(size);


  return 0;
}

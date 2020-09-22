const int DEBUG      = 1;
const int OPT_LVL    = 0;
const int TEST_DEBUG = 1;
#include "Vine.h"
#include <assert.h>
#include "tests/constructor.cc"
#include "tests/destructor.cc"
#include "tests/assignment.cc"
#include "tests/indexing.cc"
#include "tests/equality.cc"
#include "tests/greaterthan.cc"
#include "tests/lessthan.cc"
#include "tests/addition.cc"
#include "tests/subtraction.cc"
#include "tests/multiplication.cc"
#include "tests/division.cc"
#include "tests/power.cc"


//handle overflow -- only called if compiled using -ftrapv
void overflow_handler(int sig) {
  printf("Overflow detected\n");
  //abort the entire program
  abort();
}


int main(){
  signal(SIGILL, &overflow_handler);
  unsigned int size = 1000; //size >= 10

  test_constructor(size);
  test_destructor(size);
  test_assignment(size);
  test_indexing(size);
  test_equality(size);
  test_greater_than(size);
  test_less_than(size);
  test_addition(size);
  test_subtraction(size);
  test_multiplication(size);
  test_division(size);
  test_power(size);


  return 0;
}

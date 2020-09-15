int OPT_LVL;
#include "Vine.h"
#include <cstdlib>
#include <chrono>
const int MIN = -10000000;
const int MAX = 10000000;
const unsigned int SIZE       = 500000;
const unsigned int ITERATIONS = 1000;
#include "benchmarks/assignment.cc"
#include "benchmarks/indexing.cc"
#include "benchmarks/equality.cc"
#include "benchmarks/greaterthan.cc"
#include "benchmarks/lessthan.cc"
#include "benchmarks/addition.cc"

void benchmark(double (*func)()) {
  for(int i=0; i < 3; i++) {
    OPT_LVL = i;
    printf("\tOPT_LVL %d: %-8.2lf\n", OPT_LVL, func());
  }
}

int main() {
  srand(time(NULL));

  //assignment
  printf("Vine = constant\n");
  benchmark(benchmark_assignment_to_constant);

  printf("Vine = Vine\n");
  benchmark(benchmark_assignment_to_vine);

  //indexing
  printf("constant = Vine[i]\n");
  benchmark(benchmark_index_get);

  printf("Vine[i] = constant\n");
  benchmark(benchmark_index_set);

  //equality
  printf("Vine == constant\n");
  benchmark(benchmark_equal_to_constant);

  printf("Vine == Vine\n");
  benchmark(benchmark_equal_to_vine);

  printf("Vine != constant\n");
  benchmark(benchmark_not_equal_to_constant);

  printf("Vine != Vine\n");
  benchmark(benchmark_not_equal_to_vine);

  //greater than
  printf("Vine > constant\n");
  benchmark(benchmark_greater_than_constant);

  printf("Vine > Vine\n");
  benchmark(benchmark_greater_than_vine);

  printf("Vine >= constant\n");
  benchmark(benchmark_greater_than_equal_to_constant);

  printf("Vine >= Vine\n");
  benchmark(benchmark_greater_than_equal_to_vine);

  //less than
  printf("Vine < constant\n");
  benchmark(benchmark_less_than_constant);

  printf("Vine < Vine\n");
  benchmark(benchmark_less_than_vine);

  printf("Vine <= constant\n");
  benchmark(benchmark_less_than_equal_to_constant);

  printf("Vine <= Vine\n");
  benchmark(benchmark_less_than_equal_to_vine);

  //addition
  printf("Vine + constant\n");
  benchmark(benchmark_add_constant);

  printf("Vine + Vine\n");
  benchmark(benchmark_add_vine);

  printf("Vine += constant\n");
  benchmark(benchmark_add_constant_inplace);

  printf("Vine += Vine\n");
  benchmark(benchmark_add_vine_inplace);
  return 0;
}

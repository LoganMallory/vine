const int DEBUG      = 0;
const int ITERATIONS = 100;
const int MIN        = -1000000;
const int MAX        =  1000000;
#include "Vine.h"
#include <chrono>

void randomize_values(const Vine<int>& vec1, const Vine<int>& vec2, int& v) {
  for(unsigned int i=0; i < vec1.length; i++) {
    vec1.values[i] = MIN + (rand() % (MAX - MIN + 1));
    vec2.values[i] = MIN + (rand() % (MAX - MIN + 1));
  }
  v = MIN + (rand() % (MAX - MIN + 1));
}

Vine<int> add(const Vine<int>& vec1, const Vine<int>& vec2, int& v) {
  return vec1 + v;
}

double benchmark(Vine<int> (*func)(const Vine<int>&, const Vine<int>&, int&), unsigned int size) {
  //data
  Vine<int> vec1(size);
  Vine<int> vec2(size);
  int v;

  //measurements
  double avg_duration = 0;
  long n              = 0;
  long elapsed;

  for(int i=0; i < ITERATIONS; i++) {
    printf("i: %d\n", i);
    //randomize values
    randomize_values(vec1, vec2, v);

    //start timer
    std::chrono::time_point< std::chrono::system_clock > start = std::chrono::system_clock::now();

    //do work (avoid copying overhead by using RVO)
    Vine<int> vec3 = func(vec1, vec2, v);

    //end timer
    std::chrono::time_point< std::chrono::system_clock > end = std::chrono::system_clock::now();
    //calculate time elapsed
    elapsed = (std::chrono::duration_cast<std::chrono::microseconds>(end - start)).count();
    //update average
    avg_duration = ((avg_duration * n) + elapsed) / (n+1);
    n           += 1;

    //write some data to disk so work isn't optimized out
  }
  return avg_duration;
}

double benchmark(void (*func)(const Vine<int>&, const Vine<int>&, int&), unsigned int size) {
  //data
  Vine<int> vec1(size);
  Vine<int> vec2(size);
  int v;

  //measurements
  double avg_duration = 0;
  long n              = 0;
  long elapsed;

  for(int i=0; i < ITERATIONS; i++) {
    printf("i: %d\n", i);
    //randomize values
    randomize_values(vec1, vec2, v);

    //start timer
    std::chrono::time_point< std::chrono::system_clock > start = std::chrono::system_clock::now();

    //do work (avoid copying overhead by using RVO)
    func(vec1, vec2, v);

    //end timer
    std::chrono::time_point< std::chrono::system_clock > end = std::chrono::system_clock::now();
    //calculate time elapsed
    elapsed = (std::chrono::duration_cast<std::chrono::microseconds>(end - start)).count();
    //update average
    avg_duration = ((avg_duration * n) + elapsed) / (n+1);
    n           += 1;

    //write some data to disk so work isn't optimized out
  }
  return avg_duration;
}

int main() {
  unsigned int size = 500000; //5M
  printf("microseconds: %lf\n", benchmark(add, size));

  return 0;
}

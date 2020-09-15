double benchmark_less_than_constant() {
  Vine<int> vec1(SIZE);
  for(unsigned int i=0; i < vec1.length; i++) vec1[i] = MIN + (rand() % static_cast<int>(MAX - MIN + 1));
  int mid = MIN + (rand() % static_cast<int>(MAX - MIN + 1));
  double avg_duration = 0;
  double n = 0;
  long elapsed;

  for(unsigned int i = 0; i < ITERATIONS; i++) {
    //start benchmark
    std::chrono::time_point< std::chrono::system_clock > start = std::chrono::system_clock::now();

    //do work
    Vine<bool> vec2 = vec1 > mid;

    //end benchmark
    std::chrono::time_point< std::chrono::system_clock > end = std::chrono::system_clock::now();

    //calculate time elapsed
    elapsed = (std::chrono::duration_cast<std::chrono::microseconds>(end - start)).count();

    //update average
    avg_duration = ((avg_duration * n) + elapsed) / (n+1);
    n           += 1;
  }
  return avg_duration;
}
double benchmark_less_than_vine() {
  Vine<int> vec1(SIZE);
  Vine<int> vec2(SIZE);
  for(unsigned int i=0; i < vec1.length; i++) {
    vec1[i] = MIN + (rand() % static_cast<int>(MAX - MIN + 1));
    vec2[i] = MIN + (rand() % static_cast<int>(MAX - MIN + 1));
  }
  double avg_duration = 0;
  double n = 0;
  long elapsed;

  for(unsigned int i = 0; i < ITERATIONS; i++) {
    //start benchmark
    std::chrono::time_point< std::chrono::system_clock > start = std::chrono::system_clock::now();

    //do work
    Vine<bool> vec3 = vec1 > vec2;

    //end benchmark
    std::chrono::time_point< std::chrono::system_clock > end = std::chrono::system_clock::now();

    //calculate time elapsed
    elapsed = (std::chrono::duration_cast<std::chrono::microseconds>(end - start)).count();

    //update average
    avg_duration = ((avg_duration * n) + elapsed) / (n+1);
    n           += 1;
  }
  return avg_duration;
}


double benchmark_less_than_equal_to_constant() {
  Vine<int> vec1(SIZE);
  for(unsigned int i=0; i < vec1.length; i++) vec1[i] = MIN + (rand() % static_cast<int>(MAX - MIN + 1));
  int mid = MIN + (rand() % static_cast<int>(MAX - MIN + 1));
  double avg_duration = 0;
  double n = 0;
  long elapsed;

  for(unsigned int i = 0; i < ITERATIONS; i++) {
    //start benchmark
    std::chrono::time_point< std::chrono::system_clock > start = std::chrono::system_clock::now();

    //do work
    Vine<bool> vec2 = vec1 >= mid;

    //end benchmark
    std::chrono::time_point< std::chrono::system_clock > end = std::chrono::system_clock::now();

    //calculate time elapsed
    elapsed = (std::chrono::duration_cast<std::chrono::microseconds>(end - start)).count();

    //update average
    avg_duration = ((avg_duration * n) + elapsed) / (n+1);
    n           += 1;
  }
  return avg_duration;
}
double benchmark_less_than_equal_to_vine() {
  Vine<int> vec1(SIZE);
  Vine<int> vec2(SIZE);
  for(unsigned int i=0; i < vec1.length; i++) {
    vec1[i] = MIN + (rand() % static_cast<int>(MAX - MIN + 1));
    vec2[i] = MIN + (rand() % static_cast<int>(MAX - MIN + 1));
  }
  double avg_duration = 0;
  double n = 0;
  long elapsed;

  for(unsigned int i = 0; i < ITERATIONS; i++) {
    //start benchmark
    std::chrono::time_point< std::chrono::system_clock > start = std::chrono::system_clock::now();

    //do work
    Vine<bool> vec3 = vec1 >= vec2;

    //end benchmark
    std::chrono::time_point< std::chrono::system_clock > end = std::chrono::system_clock::now();

    //calculate time elapsed
    elapsed = (std::chrono::duration_cast<std::chrono::microseconds>(end - start)).count();

    //update average
    avg_duration = ((avg_duration * n) + elapsed) / (n+1);
    n           += 1;
  }
  return avg_duration;
}

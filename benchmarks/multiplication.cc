double benchmark_multiply_constant() {
  Vine<int> vec1(SIZE);

  double avg_duration = 0;
  double n = 0;
  long elapsed;

  for(unsigned int i = 0; i < ITERATIONS; i++) {
    //initialize array to randomness
    for(unsigned int i=0; i < SIZE; i++) vec1[i] = MIN + (rand() % static_cast<int>(MAX - MIN + 1));

    //choose random constant
    int v = MIN + (rand() % static_cast<int>(MAX - MIN + 1));

    //start benchmark
    std::chrono::time_point< std::chrono::system_clock > start = std::chrono::system_clock::now();

    //do work
    Vine<int> vec2 = vec1 * v;

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
double benchmark_multiply_vine() {
  Vine<int> vec1(SIZE);
  Vine<int> vec2(SIZE);

  double avg_duration = 0;
  double n = 0;
  long elapsed;

  for(unsigned int i = 0; i < ITERATIONS; i++) {
    //initialize arrays to randomness
    for(unsigned int i=0; i < vec1.length; i++) {
      vec1[i] = MIN + (rand() % static_cast<int>(MAX - MIN + 1));
      vec2[i] = MIN + (rand() % static_cast<int>(MAX - MIN + 1));
    }

    //start benchmark
    std::chrono::time_point< std::chrono::system_clock > start = std::chrono::system_clock::now();

    //do work
    Vine<int> vec3 = vec1 * vec2;

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

double benchmark_multiply_constant_inplace() {
  Vine<int> vec1(SIZE);

  double avg_duration = 0;
  double n = 0;
  long elapsed;

  for(unsigned int i = 0; i < ITERATIONS; i++) {
    //initialize array to randomness
    for(unsigned int i=0; i < SIZE; i++) vec1[i] = MIN + (rand() % static_cast<int>(MAX - MIN + 1));

    //choose random constant
    int v = MIN + (rand() % static_cast<int>(MAX - MIN + 1));

    //start benchmark
    std::chrono::time_point< std::chrono::system_clock > start = std::chrono::system_clock::now();

    //do work
    vec1 *= v;

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
double benchmark_multiply_vine_inplace() {
  Vine<int> vec1(SIZE);
  Vine<int> vec2(SIZE);

  double avg_duration = 0;
  double n = 0;
  long elapsed;

  for(unsigned int i = 0; i < ITERATIONS; i++) {
    //initialize arrays to randomness
    for(unsigned int i=0; i < vec1.length; i++) {
      vec1[i] = MIN + (rand() % static_cast<int>(MAX - MIN + 1));
      vec2[i] = MIN + (rand() % static_cast<int>(MAX - MIN + 1));
    }

    //start benchmark
    std::chrono::time_point< std::chrono::system_clock > start = std::chrono::system_clock::now();

    //do work
    vec1 *= vec2;

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

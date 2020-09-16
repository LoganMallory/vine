double benchmark_default_constructor() {
  double avg_duration = 0;
  double n = 0;
  long elapsed;

  for(unsigned int i = 0; i < ITERATIONS; i++) {

    //start benchmark
    std::chrono::time_point< std::chrono::system_clock > start = std::chrono::system_clock::now();

    //do work
    Vine<int> vec1;

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

double benchmark_size_constructor() {
  double avg_duration = 0;
  double n = 0;
  long elapsed;

  for(unsigned int i = 0; i < ITERATIONS; i++) {

    //start benchmark
    std::chrono::time_point< std::chrono::system_clock > start = std::chrono::system_clock::now();

    //do work
    Vine<int> vec1(SIZE);

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

double benchmark_value_size_constructor() {
  double avg_duration = 0;
  double n = 0;
  long elapsed;

  for(unsigned int i = 0; i < ITERATIONS; i++) {
    //choose random value
    int v = MIN + (rand() % static_cast<int>(MAX - MIN + 1));

    //start benchmark
    std::chrono::time_point< std::chrono::system_clock > start = std::chrono::system_clock::now();

    //do work
    Vine<int> vec1(v, SIZE);

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

double benchmark_vine_copy_constructor() {
  Vine<int> vec1(SIZE);
  double avg_duration = 0;
  double n = 0;
  long elapsed;

  for(unsigned int i = 0; i < ITERATIONS; i++) {
    //initialize arrays to randomness
    for(unsigned int i=0; i < vec1.length; i++) vec1[i] = MIN + (rand() % static_cast<int>(MAX - MIN + 1));

    //start benchmark
    std::chrono::time_point< std::chrono::system_clock > start = std::chrono::system_clock::now();

    //do work
    Vine<int> vec2(vec1);

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

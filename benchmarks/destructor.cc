double benchmark_destructor() {
  double avg_duration = 0;
  double n = 0;
  long elapsed;

  for(unsigned int i = 0; i < ITERATIONS; i++) {
    //initialize random Vine
    int v =  MIN + (rand() % static_cast<int>(MAX - MIN + 1));
    Vine<int> vec1(v, SIZE);

    //start benchmark
    std::chrono::time_point< std::chrono::system_clock > start = std::chrono::system_clock::now();

    //do work
    vec1.~Vine();

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

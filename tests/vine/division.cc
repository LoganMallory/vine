//C and C++ division truncates fractions (rounds to zero)
void divide_constant_test(unsigned int size) {
  if(TEST_DEBUG) printf("\tdivide_constant_test()\n");
  Vine<int> vec1(size);
  Vine<int> vec2(size);
  Vine<int> vec3(size);
  vec1 = 32;
  vec1 = vec1 / 4;
  vec2 = vec1 / 9;
  vec3 = vec1 / -3;

  for(unsigned int i=0; i < vec1.length; i++) {
    assert(vec1[i] == 8);
    assert(vec2[i] == 0);
    assert(vec3[i] == -2);
  }
}

void divide_vine_test(unsigned int size) {
  if(TEST_DEBUG) printf("\tdivide_vine_test()\n");
  Vine<int> vec1(size);
  Vine<int> vec2(size);
  Vine<int> vec3(size);
  vec1 = 25921;
  vec1 = vec1 / 2;
  vec2 = vec1 / -10;
  vec3 = vec1 / -1 / vec2;

  for(unsigned int i=0; i < vec1.length; i++) {
    assert(vec1[i] == 12960);
    assert(vec2[i] == -1296);
    assert(vec3[i] == 10);
  }
}

void divide_constant_inplace_test(unsigned int size) {
  if(TEST_DEBUG) printf("\tdivide_constant_inplace_test()\n");
  Vine<int> vec(size);
  vec = 1153;
  vec /= 23;
  for(unsigned int i=0; i < vec.length; i++) assert(vec[i] == 50);

  vec /= -39;
  for(unsigned int i=0; i < vec.length; i++) assert(vec[i] == -1);
}

void divide_vine_inplace_test(unsigned int size) {
  if(TEST_DEBUG) printf("\tdivide_vine_inplace_test()\n");
  Vine<int> vec1(size);
  Vine<int> vec2(size);
  vec1  = 4712304;
  vec2  = -11032;
  vec1 /= 9;
  vec2 /= vec1 / -17 / vec2;
  for(unsigned int i=0; i < vec1.length; i++){
    assert(vec1[i] == 523589);
    assert(vec2[i] == -5516);
  }
}

void test_division(unsigned int size) {
  divide_constant_test(size);
  divide_vine_test(size);
  divide_constant_inplace_test(size);
  divide_vine_inplace_test(size);
}

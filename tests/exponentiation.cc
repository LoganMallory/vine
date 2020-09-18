void constant_exponentiation_test(unsigned int size) {
  if(TEST_DEBUG) printf("\tconstant_exponentiation_test()\n");
  Vine<int> vec1(3, size);
  Vine<int> vec2 = vec1.pow(0);
  assert(vec2.length == size);
  assert(vec2.values != NULL);
  for(unsigned int i = 0; i < vec2.length; i++) assert(vec2.values[i] == 1);

  vec2 = vec1.pow(1);
  assert(vec2.length == size);
  assert(vec2.values != NULL);
  for(unsigned int i = 0; i < vec2.length; i++) assert(vec2.values[i] == 3);

  vec2 = vec1.pow(3);
  assert(vec2.length == size);
  assert(vec2.values != NULL);
  for(unsigned int i = 0; i < vec2.length; i++) assert(vec2.values[i] == 27);
}
void constant_exponentiation_inplace_test(unsigned int size) {
  if(TEST_DEBUG) printf("\tconstant_exponentiation_inplace_test()\n");
  Vine<int> vec1(3, size);
  vec1.pow(0, true);
  for(unsigned int i = 0; i < vec1.length; i++) assert(vec1.values[i] == 1);

  vec1 = 3;
  vec1.pow(1, true);
  for(unsigned int i = 0; i < vec1.length; i++) assert(vec1.values[i] == 3);

  vec1 = 3;
  vec1.pow(3, true);
  for(unsigned int i = 0; i < vec1.length; i++) assert(vec1.values[i] == 27);
}

void vine_exponentiation_test() {
  if(TEST_DEBUG) printf("\tvine_exponentiation_test()\n");
  Vine<int> vec1          = {5, 9, 0, 2};
  Vine<unsigned int> vec2 = {0, 1, 2, 3};
  Vine<int> vec3 = vec1.pow(vec2);
  assert(vec3.length == 4);
  assert(vec3.values != NULL);
  assert(vec3.values[0] == 1);
  assert(vec3.values[1] == 9);
  assert(vec3.values[2] == 0);
  assert(vec3.values[3] == 8);
}


void vine_exponentiation_inplace_test(unsigned int size) {
  if(TEST_DEBUG) printf("\tvine_exponentiation_inplace_test()\n");
  Vine<int> vec1          = {5, 9, 0, 2};
  Vine<unsigned int> vec2 = {0, 1, 2, 3};
  vec1.pow(vec2, true);
  assert(vec1.length == 4);
  assert(vec1.values != NULL);
  assert(vec1.values[0] == 1);
  assert(vec1.values[1] == 9);
  assert(vec1.values[2] == 0);
  assert(vec1.values[3] == 8);
}

void test_exponentiation(unsigned int size) {
  constant_exponentiation_test(size);
  vine_exponentiation_test();
  constant_exponentiation_inplace_test(size);
  vine_exponentiation_inplace_test(size);
}

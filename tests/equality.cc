void equals_constant_test(unsigned int size) {
  if(TEST_DEBUG) printf("\tequals_constant_test()\n");
  Vine<int> vec1(size);
  Vine<bool> vec2 = vec1 == 0;
  for(unsigned int i=0; i < vec1.length; i++) assert(vec2[i] == true);
  vec2 = vec1 == 23;
  for(unsigned int i=0; i < vec1.length; i++) assert(vec2[i] == false);
  vec1[0] = -8;
  vec2 = vec1 == -8; 
  assert(vec2[0] == true);
  assert(vec2[1] == false);
}

void equals_vine_test(unsigned int size) {
  if(TEST_DEBUG) printf("\tequals_vine_test()\n");
  Vine<int> vec1(size);
  Vine<int> vec2(size);
  Vine<bool> vec3 = vec1 == vec2;
  for(unsigned int i = 0; i < vec1.length; i++) assert(vec3[i] == true);
  vec2[0] = 1;
  vec3 = vec1 == vec2;

  assert(vec3[0] == false);
  assert(vec3[1] == true);
}

void not_equals_constant_test(unsigned int size) {
  if(TEST_DEBUG) printf("\tnot_equals_constant_test()\n");
  Vine<int> vec1(size);
  Vine<bool> vec2 = vec1 != 0;
  for(unsigned int i=0; i < vec1.length; i++) assert(vec2[i] == false);
  vec2 = vec1 != 23;
  for(unsigned int i=0; i < vec1.length; i++) assert(vec2[i] == true);
  vec1[0] = -8;
  vec2 = vec1 != -8;
  assert(vec2[0] == false);
  assert(vec2[1] == true);
}

void not_equals_vine_test(unsigned int size) {
  if(TEST_DEBUG) printf("\tnot_equals_vine_test()\n");
  Vine<int> vec1(size);
  Vine<int> vec2(size);
  Vine<bool> vec3 = vec1 != vec2;
  for(unsigned int i = 0; i < vec1.length; i++) assert(vec3[i] == false);
  vec2[0] = 1;
  vec3 = vec1 != vec2;

  assert(vec3[0] == true);
  assert(vec3[1] == false);
}

void test_equality(unsigned int size) {
  equals_constant_test(size);
  equals_vine_test(size);
  not_equals_constant_test(size);
  not_equals_vine_test(size);
}

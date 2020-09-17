void greater_than_constant_test(unsigned int size) {
  //check for false
  Vine<int> vec1(189, size);
  Vine<bool> vec2 = vec1 > 9201;
  for(unsigned int i=0; i < vec2.length; i++) assert(vec2[i] == false);
  //check in case of equal values (false)
  vec1 = -82;
  vec2 = vec1 > -82;
  for(unsigned int i=0; i < vec2.length; i++) assert(vec2[i] == false);
  //check for true
  vec1[0] = 1084;
  vec2 = vec1 > 142;
  assert(vec2[0] = true);
  for(unsigned int i=1; i < vec2.length; i++) assert(vec2[i] == false);
}

void greater_than_vine_test(unsigned int size) {
  //check for false
  Vine<int> vec1(189, size);
  Vine<int> vec2(9201, size);
  Vine<bool> vec3 = vec1 > vec2;
  for(unsigned int i=0; i < vec3.length; i++) assert(vec3[i] == false);
  //check in case of equal values (false)
  vec1 = -82;
  vec2 = -82;
  vec3 = vec1 > vec2;
  for(unsigned int i=0; i < vec3.length; i++) assert(vec3[i] == false);
  //check for true
  vec1[0] = 1084;
  vec3 = vec1 > vec2;
  assert(vec3[0] = true);
  for(unsigned int i=1; i < vec3.length; i++) assert(vec3[i] == false);
}

void greater_than_equal_to_constant_test(unsigned int size) {
  //check for false
  Vine<int> vec1(189, size);
  Vine<bool> vec2 = vec1 >= 9201;

  for(unsigned int i=0; i < vec2.length; i++) assert(vec2[i] == false);
  //check in case of equal values (true)
  vec1 = -82;
  vec2 = vec1 >= -82;
  for(unsigned int i=0; i < vec2.length; i++) assert(vec2[i] == true);
  //check for true
  vec1[0] = 1084;
  vec2 = vec1 >= 142;
  assert(vec2[0] = true);
  for(unsigned int i=1; i < vec2.length; i++) assert(vec2[i] == false);
}

void greater_than_equal_to_vine_test(unsigned int size) {
  //check for false
  Vine<int> vec1(189, size);
  Vine<int> vec2(9201, size);
  Vine<bool> vec3 = vec1 >= vec2;
  for(unsigned int i=0; i < vec3.length; i++) assert(vec3[i] == false);
  //check in case of equal values (true)
  vec1 = -82;
  vec2 = -82;
  vec3 = vec1 >= vec2;
  for(unsigned int i=0; i < vec3.length; i++) assert(vec3[i] == true);
  //check for true
  vec1[0] = 1084;
  vec2    = 19;
  vec3 = vec1 >= vec2;
  assert(vec3[0] = true);
  for(unsigned int i=1; i < vec3.length; i++) assert(vec3[i] == false);
}

void test_greater_than(unsigned int size) {
  greater_than_constant_test(size);
  greater_than_vine_test(size);
  greater_than_equal_to_constant_test(size);
  greater_than_equal_to_vine_test(size);
}

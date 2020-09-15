void multiply_constant_test(unsigned int size) {
  if(TEST_DEBUG) printf("\tmultiply_constant_test()\n");
  Vine<int> vec1(size);
  Vine<int> vec2(size);
  Vine<int> vec3(size);
  vec1 = 3;
  vec1 = vec1 * 23;
  vec2 = vec1 * 11;
  vec3 = vec2 * -10;
  for(unsigned int i=0; i < vec1.length; i++) {
    assert(vec1[i] == 69);
    assert(vec2[i] == 759);
    assert(vec3[i] == -7590);
  }
}

void multiply_vine_test(unsigned int size) {
  if(TEST_DEBUG) printf("\tmultiply_vine_test()\n");
  Vine<int> vec1(size);
  Vine<int> vec2(size);
  Vine<int> vec3(size);
  vec1 = -5;
  vec1 = vec1 * 29;
  vec2 = vec1 * vec1 * 83;

  //vec3 = vec2 * -13 * vec1; test overflow
  vec3 = vec2 * -13 * (vec1 + 191);

  for(unsigned int i=0; i < vec1.length; i++) {
    assert(vec1[i] == -145);
    assert(vec2[i] == 1745075);
    assert(vec3[i] == -1043554850);
  }
}

void multiply_constant_inplace_test(unsigned int size) {
  if(TEST_DEBUG) printf("\tmultiply_constant_inplace_test()\n");
  Vine<int> vec(size);
  vec = 11;
  vec *= 87;
  for(unsigned int i=0; i < vec.length; i++) assert(vec[i] == 957);

  vec *= -39;
  for(unsigned int i=0; i < vec.length; i++) assert(vec[i] == -37323);
}

void multiply_vine_inplace_test(unsigned int size) {
  if(TEST_DEBUG) printf("\tmultiply_vine_inplace_test()\n");
  Vine<int> vec1(size);
  Vine<int> vec2(size);
  vec1 = 47;
  vec2 = -11;
  vec1 *= 211;
  vec2 *= vec1 * -17 * vec2;
  for(unsigned int i=0; i < vec1.length; i++){
    assert(vec1[i] == 9917);
    assert(vec2[i] == -20399269);
  }
}

void test_multiplication(unsigned int size) {
  multiply_constant_test(size);
  multiply_vine_test(size);
  multiply_constant_inplace_test(size);
  multiply_vine_inplace_test(size);
}

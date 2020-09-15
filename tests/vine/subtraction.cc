void subtract_constant_test(unsigned int size) {
  if(TEST_DEBUG) printf("\tsubtract_constant_test()\n");
  Vine<int> vec1(size);
  Vine<int> vec2(size);
  Vine<int> vec3(size);
  vec1 = vec1 - 23;
  vec2 = vec1 - 11;
  vec3 = vec2 - -10;
  for(unsigned int i=0; i < vec1.length; i++) {
    assert(vec1[i] == -23);
    assert(vec2[i] == -34);
    assert(vec3[i] == -24);
  }
}

void subtract_vine_test(unsigned int size) {
  if(TEST_DEBUG) printf("\tsubtract_vine_test()\n");
  Vine<int> vec1(size);
  Vine<int> vec2(size);
  Vine<int> vec3(size);
  vec1 = vec1 - 29;
  vec2 = vec1 - vec1 - 83;
  vec3 = vec2 - 13 - vec1;

  for(unsigned int i=0; i < vec1.length; i++) {
    assert(vec1[i] == -29);
    assert(vec2[i] == -83);
    assert(vec3[i] == -67);
  }
}

void subtract_constant_inplace_test(unsigned int size) {
  if(TEST_DEBUG) printf("\tsubtract_constant_inplace_test()\n");
  Vine<int> vec(size);
  vec -= 87;
  for(unsigned int i=0; i < vec.length; i++) assert(vec[i] == -87);

  vec -= -39;
  for(unsigned int i=0; i < vec.length; i++) assert(vec[i] == -48);
}

void subtract_vine_inplace_test(unsigned int size) {
  if(TEST_DEBUG) printf("\tsubtract_vine_inplace_test()\n");
  Vine<int> vec1(size);
  Vine<int> vec2(size);
  vec1 -= 47;
  vec2 -= -11;
  vec2 -= vec1 - 17 - vec2;
  for(unsigned int i=0; i < vec1.length; i++){
    assert(vec1[i] == -47);
    assert(vec2[i] == -64);
  }
}

void test_subtraction(unsigned int size) {
  subtract_constant_test(size);
  subtract_vine_test(size);
  subtract_constant_inplace_test(size);
  subtract_vine_inplace_test(size);
}

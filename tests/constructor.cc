void default_constructor_test() {
  if(TEST_DEBUG) printf("\tdefault_constructor_test()\n");
  Vine<int> vec1;
  assert(vec1.length == 0);
  assert(vec1.values == NULL);

  Vine<int> array1[3];
  Vine<int>* array2 = new Vine<int>[3];
  for(int i=0; i < 3; i++){
    assert(array1[i].length == 0);
    assert(array1[i].values == NULL);

    assert(array2[i].length == 0);
    assert(array2[i].values == NULL);
  }
  delete[] array2;
}

void size_constructor_test(unsigned int size) {
  if(TEST_DEBUG) printf("\tsize_constructor_test()\n");
  Vine<int> vec(size);
  assert(vec.length == size);
  assert(vec.values != NULL);
  for(unsigned int i=0; i < vec.length; i++) assert(vec.values[i] == 0);
}

void value_size_constructor_test(unsigned int size) {
  if(TEST_DEBUG) printf("\tvalue_size_constructor_test()\n");
  Vine<int> vec(19, size);
  assert(vec.length == size);
  assert(vec.values != NULL);
  for(unsigned int i=0; i < vec.length; i++) assert(vec.values[i] == 19);
}

void copy_constructor_test(unsigned int size) {
  if(TEST_DEBUG) printf("\tcopy_constructor_test()\n");
  Vine<int> vec1(-93, size);
  Vine<int> vec2(vec1);
  assert(vec2.length == vec1.length);
  assert(vec2.values != vec1.values);
  assert(vec2.values != NULL);
  for(unsigned int i=0; i < vec2.length; i++) assert(vec2.values[i] == -93);

  Vine<int> vec3 = vec2;
  assert(vec3.length == vec2.length);
  assert(vec3.values != vec2.values);
  assert(vec3.values != NULL);
  for(unsigned int i=0; i < vec3.length; i++) assert(vec3.values[i] == -93);
}

void from_initializer_list_test(size) {
  if(TEST_DEBUG) printf("\tfrom_initializer_list_test()\n");
  Vine<unsigned int> vec = {0, 1, 2, 3, 4, 5};
  assert(vec.length == 6);
  assert(vec.values != NULL);
  for(unsigned int i=0; i < vec.length; i++) assert(vec.values[i] == i);
}
void from_refarray_constructor_test(size) {
  if(TEST_DEBUG) printf("\tfrom_refarray_constructor_test()\n");
  Vine<int> vec1(9, size);
  Vine<int> indexes = {0, size-1};
  Vine<int> vec2 = vec1[indexes];
  assert(vec2.length == 2);
  for(unsigned int i=0; i < vec2.length; i++) assert(vec2.values[i] == 9);
}

refarray_default_constructor_test(size) {
  if(TEST_DEBUG) printf("\trefarray_default_constructor_test()\n");
  RefArray<int> rarr;
  assert(rarr.length == 0);
  assert(rarr.refs   == NULL);
}
refarray_size_constructor_test(size) {
  if(TEST_DEBUG) printf("\trefarray_size_constructor_test()\n");
  RefArray<int> rarr(size);
  assert(rarr.length == size);
  assert(rarr.refs != NULL);
  for(unsigned int i=0; i < rarr.length; i++) assert(rarr.refs[i] == NULL);
}

void test_constructor(unsigned int size) {
  default_constructor_test();
  size_constructor_test(size);
  value_size_constructor_test(size);
  copy_constructor_test(size);
  from_refarray_constructor_test(size);
  refarray_default_constructor_test(size);
  refarray_size_constructor_test(size);
}

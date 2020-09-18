void destructor_test(unsigned int size) {
  if(TEST_DEBUG) printf("\tdestructor_test()\n");
  Vine<int> vec(size);
  vec.~Vine();
  assert(vec.length == 0);
  assert(vec.values == NULL);
}

void refarray_destructor_test(unsigned int size) {
  if(TEST_DEBUG) printf("\trefarray_destructor_test()\n");
  RefArray<int> rarr(size);
  rarr.~Vine();
  assert(rarr.length == 0);
  assert(rarr.refs   == NULL);
}

void test_destructor(unsigned int size) {
  destructor_test(size);
  refarray_destructor_test(size);
}

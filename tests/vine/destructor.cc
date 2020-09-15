void destructor_test(unsigned int size) {
  if(TEST_DEBUG) printf("\tdestructor_test()\n");
  Vine<int>* vec = new Vine<int>(size);
  vec->~Vine();
  assert(vec->length == 0);
  assert(vec->values == NULL);
}

void test_destructor(unsigned int size) {
  destructor_test(size);
}

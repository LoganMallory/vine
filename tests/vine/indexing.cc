void index_getter_test(unsigned int size) {
  if(TEST_DEBUG) printf("\tindex_getter_test()\n");
  Vine<int> vec(size);
  for(int i=0; i < vec.length; i++) vec.values[i] = i;
  for(int i=0; i < vec.length; i++) assert(vec[i] == i);
}

void index_setter_test(unsigned int size) {
  if(TEST_DEBUG) printf("\tindex_setter_test()\n");
  Vine<int> vec(size);
  for(int i=0; i < vec.length; i++) vec[i] = i;
  for(int i=0; i < vec.length; i++) assert(vec[i] == i);
}

void test_indexing(unsigned int size) {
  index_getter_test(size);
  index_setter_test(size);
}

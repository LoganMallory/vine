Vine<bool> equal_to_constant(const Vine<int>& vec1, const Vine<int>& vec2, int& v) {
  return vec1 == v;
}

Vine<bool> equal_to_vine(const Vine<int>& vec1, const Vine<int>& vec2, int& v) {
  return vec1 == vec2;
}

Vine<bool> not_equal_to_constant(const Vine<int>& vec1, const Vine<int>& vec2, int& v) {
  return vec1 != v;
}

Vine<bool> not_equal_to_vine(const Vine<int>& vec1, const Vine<int>& vec2, int& v) {
  return vec1 != vec2;
}

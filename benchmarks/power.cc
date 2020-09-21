Vine<int> power_constant(const Vine<int>& vec1, const Vine<int>& vec2, int& v) {
  return vec1.pow(v);
}

Vine<int> power_vine(const Vine<int>& vec1, const Vine<int>& vec2, int& v) {
  return vec1.pow(vec2);
}

void power_constant_inplace(const Vine<int>& vec1, const Vine<int>& vec2, int& v) {
  vec1.pow(v, true);
}

void power_vine_inplace(const Vine<int>& vec1, const Vine<int>& vec2, int& v) {
  vec1.pow(vec2, true);
}

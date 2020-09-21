Vine<int> div_constant(const Vine<int>& vec1, const Vine<int>& vec2, int& v) {
  return vec1 / v;
}
Vine<int> div_vine(const Vine<int>& vec1, const Vine<int>& vec2, int& v) {
  return vec1 / vec2;
}
void div_constant_inplace(const Vine<int>& vec1, const Vine<int>& vec2, int& v) {
  vec1 /= v;
}
void div_vine_inplace(const Vine<int>& vec1, const Vine<int>& vec2, int& v) {
  vec1 /= vec2;
}

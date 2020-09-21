Vine<int> sub_constant(const Vine<int>& vec1, const Vine<int>& vec2, int& v) {
  return vec1 - v;
}
Vine<int> sub_vine(const Vine<int>& vec1, const Vine<int>& vec2, int& v) {
  return vec1 - vec2;
}
void sub_constant_inplace(const Vine<int>& vec1, const Vine<int>& vec2, int& v) {
  vec1 -= v;
}
void sub_vine_inplace(const Vine<int>& vec1, const Vine<int>& vec2, int& v) {
  vec1 -= vec2;
}

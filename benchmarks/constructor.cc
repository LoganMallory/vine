Vine<int> default_constructor(const Vine<int>& vec1, const Vine<int>& vec2, int& v) {
  Vine<int> vec3;
  return vec3;
}

Vine<int> size_constructor(const Vine<int>& vec1, const Vine<int>& vec2, int& v) {
  Vine<int> vec3(vec1.length);
  return vec3;
}

Vine<int> value_size_constructor(const Vine<int>& vec1, const Vine<int>& vec2, int& v) {
  Vine<int> vec3(v, vec1.length);
  return vec3;
}

Vine<int> copy_constructor(const Vine<int>& vec1, const Vine<int>& vec2, int& v) {
  Vine<int> vec3(vec1);
  return vec3;
}

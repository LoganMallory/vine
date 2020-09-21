void assignment_to_constant(const Vine<int>& vec1, const Vine<int>& vec2, int& v) {
  vec1 = v;
}

void  assignment_to_vine(const Vine<int>& vec1, const Vine<int>& vec2, int& v) {
  vec2 = vec1;
}

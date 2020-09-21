template<> const char* Vine<int>::read_fmt           = "%d,";
template<> const char* Vine<unsigned int>::read_fmt  = "%u,";
template<> const char* Vine<long>::read_fmt          = "%ld,";
template<> const char* Vine<unsigned long>::read_fmt = "%lu,";
template<> const char* Vine<float>::read_fmt         = "%f,";
template<> const char* Vine<double>::read_fmt        = "%lf,";

template<> const char* Vine<bool>::print_fmt          = "%-4d";
template<> const char* Vine<int>::print_fmt           = "%-4d";
template<> const char* Vine<unsigned int>::print_fmt  = "%-4u";
template<> const char* Vine<long>::print_fmt          = "%-4ld";
template<> const char* Vine<unsigned long>::print_fmt = "%-4lu";
template<> const char* Vine<float>::print_fmt         = "%-6.2f";
template<> const char* Vine<double>::print_fmt        = "%-6.2lf";

#include "src/constructor.cc"
#include "src/destructor.cc"
#include "src/refarray.cc"
#include "src/operators/assignment.cc"
#include "src/operators/indexing.cc"
#include "src/operators/equality.cc"
#include "src/operators/greaterthan.cc"
#include "src/operators/lessthan.cc"
#include "src/operators/addition.cc"
#include "src/operators/subtraction.cc"
#include "src/operators/multiplication.cc"
#include "src/operators/division.cc"
#include "src/methods/power.cc"
#include "src/methods/intlogs.cc"
#include "src/methods/display.cc"

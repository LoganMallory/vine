#ifndef Vine_H
#define Vine_H
#include <stdio.h>
#include <string>
/*
TODO:
  % %=    operator slow
  ^ ^=    operator
  & &= && operator (&& loses short circuit eval when overloaded, prob shouldn't implement)
  | |= || operator (|| loses short circuit eval when overloaded, prob shouldn't implement)
  ~       operator don't do this one
  !       operator only for boolean Vines
  >> >>=  operator
  << <<=  operator
  -- ++   operator

*/
template<typename dtype>
class Vine;

template<typename dtype>
class RefArray {
public:
  unsigned int length;
  dtype** refs;

  RefArray();
  RefArray(const unsigned int n);
  ~RefArray();

  void operator= (const dtype v);
  void operator= (const Vine<dtype>& vec);
};

template<typename dtype>
class Vine {
private:
  static const char* read_fmt;
  static const char* print_fmt;

public:
  unsigned int length;
  dtype* values;

  Vine();
  Vine(const unsigned int n);
  Vine(const dtype v, const unsigned int n);
  Vine(const Vine<dtype>& vec);
  ~Vine();

  //operators
    //assignment
  void operator= (const dtype v);
  void operator= (const Vine<dtype>& vec);
  //void operator= (const RefArray<dtype>& refarr); //deep copy

    //indexers
  dtype operator[] (const unsigned int i) const; //getting
  dtype& operator[] (const unsigned int i);      //setting
  RefArray<dtype> operator[] (const Vine<unsigned int>& indexes) const;
  RefArray<dtype> operator[] (const Vine<bool>& indexes) const;

    //comparisons
  Vine<bool> operator== (const dtype v) const;
  Vine<bool> operator== (const Vine<dtype>& vec) const;
  Vine<unsigned int> operator== (const dtype v) const;
  Vine<unsigned int> operator== (const Vine<dtype>& vec) const;

  Vine<bool> operator!= (const dtype v) const;
  Vine<bool> operator!= (const Vine<dtype>& vec) const;
  Vine<unsigned int> operator!= (const dtype v) const;
  Vine<unsigned int> operator!= (const Vine<dtype>& vec) const;

  Vine<bool> operator> (const dtype v) const;
  Vine<bool> operator> (const Vine<dtype>& vec) const;
  Vine<unsigned int> operator> (const dtype v) const;
  Vine<unsigned int> operator> (const Vine<dtype>& vec) const;

  Vine<bool> operator>= (const dtype v) const;
  Vine<bool> operator>= (const Vine<dtype>& vec) const;
  Vine<unsigned int> operator>= (const dtype v) const;
  Vine<unsigned int> operator>= (const Vine<dtype>& vec) const;

  Vine<bool> operator< (const dtype v) const;
  Vine<bool> operator< (const Vine<dtype>& vec) const;
  Vine<unsigned int> operator< (const dtype v) const;
  Vine<unsigned int> operator< (const Vine<dtype>& vec) const;

  Vine<bool> operator<= (const dtype v) const;
  Vine<bool> operator<= (const Vine<dtype>& vec) const;
  Vine<unsigned int> operator<= (const dtype v) const;
  Vine<unsigned int> operator<= (const Vine<dtype>& vec) const;

    //addition
  Vine<dtype> operator+ (const dtype v) const;
  Vine<dtype> operator+ (const Vine<dtype>& vec) const;
  void operator+= (const dtype v);
  void operator+= (const Vine<dtype>& vec);
    //subtraction
  Vine<dtype> operator- (const dtype v) const;
  Vine<dtype> operator- (const Vine<dtype>& vec) const;
  void operator-= (const dtype v);
  void operator-= (const Vine<dtype>& vec);
    //multiplication
  Vine<dtype> operator* (const dtype v) const;
  Vine<dtype> operator* (const Vine<dtype>& vec) const;
  void operator*= (const dtype v);
  void operator*= (const Vine<dtype>& vec);
    //division
  Vine<dtype> operator/ (const dtype v) const;
  Vine<dtype> operator/ (const Vine<dtype>& vec) const;
  void operator/= (const dtype v);
  void operator/= (const Vine<dtype>& vec);
    //xor
  Vine<dtype> operator^ (const dtype v) const;
  Vine<dtype> operator^ (const Vine<dtype>& vec) const;
  void operator^= (const dtype v);
  void operator^= (const Vine<dtype>& vec);


  //methods
  void print();
};
#include "Vine.cc"
#endif

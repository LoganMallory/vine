#ifndef Vine_H
#define Vine_H
#include <stdio.h>
#include <string> //weirdly includes a bunch of things like
#include <initializer_list>

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
  dtype** refs;        //TODO: see if this can be made constant (https://stackoverflow.com/questions/1143262/what-is-the-difference-between-const-int-const-int-const-and-int-const)

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
  explicit Vine(const unsigned int n);
  Vine(const dtype v, const unsigned int n);
  Vine(const Vine<dtype>& vec);
  Vine(std::initializer_list<dtype> values_list);
  Vine(const RefArray<dtype>& refarr);
  ~Vine();

  //operators
    //assignment
  void operator= (const dtype v) const;
  void operator= (const Vine<dtype>& vec) const;
  //void operator= (const RefArray<dtype>& refarr); //deep copy

    //indexers
  dtype operator[] (const unsigned int i) const; //getting
  dtype& operator[] (const unsigned int i);      //setting
  RefArray<dtype> operator[] (const Vine<unsigned int>& indexes) const;
  RefArray<dtype> operator[] (const Vine<bool>& indexes) const;

    //comparisons
  Vine<bool> operator== (const dtype v) const;
  Vine<bool> operator== (const Vine<dtype>& vec) const;

  Vine<bool> operator!= (const dtype v) const;
  Vine<bool> operator!= (const Vine<dtype>& vec) const;

  Vine<bool> operator> (const dtype v) const;
  Vine<bool> operator> (const Vine<dtype>& vec) const;

  Vine<bool> operator>= (const dtype v) const;
  Vine<bool> operator>= (const Vine<dtype>& vec) const;

  Vine<bool> operator< (const dtype v) const;
  Vine<bool> operator< (const Vine<dtype>& vec) const;

  Vine<bool> operator<= (const dtype v) const;
  Vine<bool> operator<= (const Vine<dtype>& vec) const;

    //addition
  Vine<dtype> operator+ (const dtype v) const;
  Vine<dtype> operator+ (const Vine<dtype>& vec) const;
  void operator+= (const dtype v) const;
  void operator+= (const Vine<dtype>& vec) const;
    //subtraction
  Vine<dtype> operator- (const dtype v) const;
  Vine<dtype> operator- (const Vine<dtype>& vec) const;
  void operator-= (const dtype v) const;
  void operator-= (const Vine<dtype>& vec) const;
    //multiplication
  Vine<dtype> operator* (const dtype v) const;
  Vine<dtype> operator* (const Vine<dtype>& vec) const;
  void operator*= (const dtype v) const;
  void operator*= (const Vine<dtype>& vec) const;
    //division
  Vine<dtype> operator/ (const dtype v) const;
  Vine<dtype> operator/ (const Vine<dtype>& vec) const;
  void operator/= (const dtype v) const;
  void operator/= (const Vine<dtype>& vec) const;

  //methods
    //power
  Vine<dtype> pow(const unsigned int p) const;
  void pow(const unsigned int p, bool inplace) const;
  Vine<dtype> pow(const Vine<unsigned int>& vec) const;
  void pow(const Vine<unsigned int>& vec, bool inplace) const;
    //int logs
  Vine<dtype> intlog2() const;
  void intlog2(bool inplace) const;
  Vine<dtype> intlog10() const;
  void intlog10(bool inplace) const;

    //display
  void print();
};
#include "Vine.cc"
#endif

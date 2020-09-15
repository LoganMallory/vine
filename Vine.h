#ifndef Vine_H
#define Vine_H
#include <stdio.h>
#include <string>

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
    //indexers
  dtype operator[] (const unsigned int i) const; //getting
  dtype& operator[] (const unsigned int i);      //setting
  Vine<dtype>& operator[] (const Vine<unsigned int>& indexes) const; //getting
  Vine<dtype>& operator[] (const Vine<unsigned int>& indexes);       //setting
  Vine<dtype>& operator[] (const Vine<bool>& indexes) const;         //getting
  Vine<dtype>& operator[] (const Vine<bool>& indexes);               //setting

    //comparisons
  Vine<bool>& operator== (const dtype v) const;
  Vine<bool>& operator== (const Vine<dtype>& vec) const;

  Vine<bool>& operator!= (const dtype v) const;
  Vine<bool>& operator!= (const Vine<dtype>& vec) const;

  Vine<bool>& operator> (const dtype v) const;
  Vine<bool>& operator> (const Vine<dtype>& vec) const;

  Vine<bool>& operator>= (const dtype v) const;
  Vine<bool>& operator>= (const Vine<dtype>& vec) const;

  Vine<bool>& operator< (const dtype v) const;
  Vine<bool>& operator< (const Vine<dtype>& vec) const;

  Vine<bool>& operator<= (const dtype v) const;
  Vine<bool>& operator<= (const Vine<dtype>& vec) const;

    //addition
  Vine<dtype>& operator+ (const dtype v) const;
  Vine<dtype>& operator+ (const Vine<dtype>& vec) const;
  void operator+= (const dtype v);
  void operator+= (const Vine<dtype>& vec);
    //subtraction
  Vine<dtype>& operator- (const dtype v) const;
  Vine<dtype>& operator- (const Vine<dtype>& vec) const;
  void operator-= (const dtype v);
  void operator-= (const Vine<dtype>& vec);
    //multiplication
  Vine<dtype>& operator* (const dtype v) const;
  Vine<dtype>& operator* (const Vine<dtype>& vec) const;
  void operator*= (const dtype v);
  void operator*= (const Vine<dtype>& vec);
    //division
  Vine<dtype>& operator/ (const dtype v) const;
  Vine<dtype>& operator/ (const Vine<dtype>& vec) const;
  void operator/= (const dtype v);
  void operator/= (const Vine<dtype>& vec);
    //xor
  Vine<dtype>& operator^ (const dtype v) const;
  Vine<dtype>& operator^ (const Vine<dtype>& vec) const;
  void operator^= (const dtype v);
  void operator^= (const Vine<dtype>& vec);


  //methods
  void print();
};
#include "Vine.cc"
#endif

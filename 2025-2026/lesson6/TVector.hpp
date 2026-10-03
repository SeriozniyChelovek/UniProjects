#ifndef __TVECTOR__HPP__
#define __TVECTOR__HPP__

#include <iostream>

using namespace std;

class TVector {

  double* arr;
  size_t arr_l;

public:
  
  TVector(size_t = 1);
  TVector(const TVector&);

  ~TVector();
  
  TVector& operator=(const TVector&);

  TVector operator+(const TVector&);
  TVector operator+(const double);
  TVector operator*(const double);
  double operator*(const TVector&);
  double& operator[](const size_t);
  bool operator==(const TVector&);
  TVector& operator++(); // префиксный
  TVector operator++(int); // постфиксный

  friend ostream& operator<<(ostream&, const TVector&);
  friend istream& operator>>(istream&, TVector&);
  
};

#endif

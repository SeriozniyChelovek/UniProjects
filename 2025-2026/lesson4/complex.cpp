#include <iostream>
#include <string>
#include <assert.h>
#include "complex.hpp"

using namespace std;

TComplex::TComplex(double _re, double _im) {
  re = _re;
  im = _im;
}

TComplex TComplex::operator!() {
  TComplex res;
  res.re = re;
  res.im = -im;
  return res;
}

TComplex TComplex::operator+(const TComplex& op) {
  return TComplex(re + op.re, im + op.im);
}

TComplex TComplex::operator-(const TComplex& op) {
  return TComplex(re - op.re, im - op.im);
}

TComplex TComplex::operator*(TComplex op) {
  TComplex res;
  res.re = ((re * op.re) - (im * op.im));
  res.im = ((re * op.im) + (im * op.re));
  return res;
}

TComplex TComplex::operator/(TComplex op) {
  TComplex res;
  
  if (op.im == 0) {
	assert(op.re != 0 && "Zero division");
	res.re = re / op.re;
	res.im = im / op.re;
  }
  else {
	res = (*this * (!op)) / (op * (!op));
  }
  
  return res;
}

ostream& operator<<(ostream& stream, const TComplex& cnum) {
  if ((cnum.re == 0) && (cnum.im == 0)) {
	cout << 0;
	return stream;
  }
  if (cnum.re != 0){
	stream << cnum.re;
	if ((cnum.im > 0) && (cnum.im != 0))
	  cout << '+';
  }
  if (cnum.im != 0) {
	if (cnum.im != 1)
	  stream << cnum.im;
	cout << 'i';
  }
  return stream;
}

istream& operator>>(istream& stream, TComplex& cnum) {
  double re, im;
  stream >> re >> im;
  cnum.re = re;
  cnum.im = im;
  return stream;
}

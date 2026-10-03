#ifndef __COMPLEX__HPP__
#define __COMPLEX__HPP__
using namespace std;

class TComplex {
  double re;
  double im;

public:
  TComplex(double _re = 0, double _im = 0);
  TComplex operator+(const TComplex& op);
  TComplex operator-(const TComplex& op);
  TComplex operator*(TComplex op);
  TComplex operator/(TComplex op);
  TComplex operator!(); // Сопряжённое
  friend ostream& operator<<(ostream& stream, const TComplex& cnum);
  friend istream& operator>>(istream& stream, TComplex& cnum);
};
#endif

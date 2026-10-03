#include <iostream>
#include "complex.hpp"

using namespace std;

int main() {

  TComplex a;
  TComplex b;
  TComplex c;

  char cmd;
  
  cout << "Введите комплексное число a: ";
  cin >> a;

  cout << "Введите действие (+ - * /): ";
  cin >> cmd;
  
  cout << "Введите комплексное число b: ";
  cin >> b;

  switch (cmd) {
  case '+':
	c = a + b;
	break;
  case '-':
	c = a - b;
	break;
  case '*':
	c = a * b;
	break;
  case '/':
	c = a / b;
	break;
  }
  
  cout << a << ' ' << cmd << ' ' << b << " = " << c << endl;

  return 0;
}

#include <iostream>

#include "TString.hpp"

int main() {

  TString snum1, snum2, sresult, output;
  double num1, num2, result;

  cout << "Введите два числа с плавающей точкой" << endl;
  cin >> snum1 >> snum2; // Вводятся как строки

  // Преобразование TString -> double
  num1 = (double)snum1;
  num2 = (double)snum2;

  result = num1 + num2;

  sresult = result; // double -> TString

  cout << "(double)" << num1 << " + " << "(double)" << num2 << " = " << "(TString)" << sresult << endl;
  
  return 0;
}

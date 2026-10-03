#include <iostream>

#include "TString.hpp"

int main() {

  TString a, b, c;
  double num;

  cout << "Введите строку1:" << endl;
  cin >> a;

  cout << "Введите строку2:" << endl;
  cin >> b;

  cout << "Первый сивол первой строки: " << a[0] << endl;

  c = a + b;
  cout << "c = a + b; c: " << c << endl;

  num = (double)a;

  cout << "(double)a: " << num << endl;

  num = a > b;
  
  cout << "a > b: " << num << endl;
  
  return 0;
}

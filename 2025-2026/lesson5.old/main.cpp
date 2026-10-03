#include <iostream>

#include "TString.hpp"

using namespace std;

int main() {

  TString a = "Hello";
  char b[] = " world!";

  TString c;

  c = a + b;
  
  cout << c << endl;
  
  return 0;
}

#include <iostream>

#include "TVector.hpp"

using namespace std;

int main() {

  TVector vec1{1}, vec2{1}, vec3{1};
  int num;
  
  cout << "Введите длину вектора 1 и его элементы: " << endl;
  cin >> vec1;

  cout << "Введите длину вектора 2 и его элементы: " << endl;
  cin >> vec2;

  cout << endl << "vec1:" << endl << vec1 << endl << endl << "vec2:" << endl << vec2 << endl << endl;
  
  vec3 = vec1 + vec2;
  cout << "v1 + v2 = " <<  vec3 << endl;

  vec3 = vec1 + 3.7;
  cout << "v1 + 3.7 = " << vec3 << endl;

  vec3 = vec1 * 3.7;
  cout << "v3 = v1 * 3.7 = " << vec3 << endl;

  vec3[0] = 5.5;
  
  cout << "v3[0] = " << vec3[0] << endl;

  num = vec1 == vec2;
  cout << "v1 == v2 = " << num << endl;

  cout << "v3++ = " << vec3++ << endl;
  cout << "++v3 = " << ++vec3 << endl;

  num = vec1 * vec2;
  cout << endl << "(v1, v2) = " << num << endl; 

  return 0;
}

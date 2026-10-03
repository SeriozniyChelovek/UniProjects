#include <iostream>
#include <cmath>

#include "TVector.hpp"

#define INPUT_BUFFER_SIZE 100

using namespace std;

TVector::TVector(size_t size) {
  if (size == 0) size = 1;
  arr_l = size;
  arr = new double[size];
  for (size_t i = 0; i < size; i++) arr[i] = 0;
}

TVector::TVector(const TVector& vec) {
  arr_l = vec.arr_l;
  arr = new double[arr_l];
  for (size_t i = 0; i < arr_l; i++) arr[i] = vec.arr[i];
}

TVector::~TVector() {
  delete[] arr;
}

TVector& TVector::operator=(const TVector& vec) {
  arr_l = vec.arr_l;
  delete[] arr;
  arr = new double[arr_l];
  for (size_t i = 0; i < arr_l; i++) arr[i] = vec.arr[i];
  return *this;
}

TVector TVector::operator+(const TVector& vec) {
  if (arr_l != vec.arr_l) return *this;
  TVector res{arr_l};
  for (size_t i = 0; i < arr_l; i++) res.arr[i] = arr[i] + vec.arr[i];
  return res;
}

TVector TVector::operator+(const double num) {
  TVector res{arr_l};
  for (size_t i = 0; i < arr_l; i++) res.arr[i] = arr[i] + num;
  return res;
}

TVector TVector::operator*(const double num) {
  TVector res{arr_l};
  for (size_t i = 0; i < arr_l; i++) res.arr[i] = arr[i] * num;
  return res;
}

double TVector::operator*(const TVector& vec) {
  double res = 0;
  if (arr_l != vec.arr_l) return NAN;
  for (size_t i = 0; i < arr_l; i++) {
	res += (arr[i] * vec.arr[i]);
  }
  return res;
}

double& TVector::operator[](const size_t index) {
  return arr[index % arr_l];
}

bool TVector::operator==(const TVector& vec) {
  if (arr_l != vec.arr_l) return false;
  for (size_t i = 0; i < arr_l; i++)
	if (arr[i] != vec.arr[i]) return false;
  return true;
}

TVector& TVector::operator++() { // префиксный
  for (size_t i = 0; i < arr_l; i++) arr[i]++;
  return *this;
}

TVector TVector::operator++(int) { // постфиксный
  TVector copy = *this;
  ++(*this);
  return copy;
}

ostream& operator<<(ostream& stream, const TVector& vec) {
  size_t i;
  stream << '(';
  for (i = 0; i < vec.arr_l - 1; i++) stream << vec.arr[i] << "; ";
  cout << vec.arr[i];
  stream << ')';
  return stream;
}

istream& operator>>(istream& stream, TVector& vec) {
  cin >> vec.arr_l;
  if (vec.arr_l == 0) vec.arr_l = 1;
  for (size_t i = 0; i < vec.arr_l; i++) cin >> vec.arr[i];
  return stream;
}


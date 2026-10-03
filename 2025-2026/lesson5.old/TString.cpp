#include <iostream>
#include <assert.h>
#include <cstring>
#include "TString.hpp"

#define CHUNK_SIZE 8

using namespace std;

TString::TString() {
  arr_l = 0;
  arr = nullptr;
}

TString::TString(const char* str) {
  arr_l = strlen(str) + 1;
  arr = new char[arr_l];
  assert(arr != nullptr && "Memory allocation error");
  strcpy(arr, str);
}

TString::TString(const TString& str) {
  arr_l = str.arr_l;
  arr = new char[arr_l];
  assert(arr != nullptr && "Memory allocation error");
  strcpy(arr, str.arr);
}

TString::~TString() {
  if (arr_l != 0)
	delete[] arr;
}

TString TString::operator+(const TString& str) {
  TString res;
  res.arr_l = arr_l + str.arr_l;
  res.arr = new char[res.arr_l];
  strcpy(res.arr, arr);
  strcpy(res.arr + arr_l, str.arr);
  return res;
}

TString TString::operator+(const char* str) {
  TString res;
  res.arr_l = arr_l + strlen(str);
  res.arr = new char[res.arr_l];
  strcpy(res.arr, arr);
  strcpy(res.arr + arr_l, str);
  return res;
}
/*
TString TString::operator==(const TString&);
TString TString::operator>(const TString&);
TString TString::operator<(const TString&);
*/
ostream& operator<<(ostream& stream, const TString& str) {
  if (str.arr_l != 0)
	stream << str.arr;
  return stream;
}

istream& operator>>(istream& stream, TString& str) {
  char chunk[CHUNK_SIZE];
  do {
	cin >> chunk;
	str = str + chunk;
  } while (chunk != "");
  return stream;
}

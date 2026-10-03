#ifndef __TSTRING__HPP__
#define __TSTRING__HPP__

#include <iostream>

using namespace std;

class TString {

  size_t length;
  size_t allocated;
  char* arr;

public:

  TString(size_t size = 0);
  TString(char* str);
  TString(const char* str);
  TString(const TString& str);
  ~TString();

  TString& operator=(char* str);
  TString& operator=(const TString& str);
  TString& operator=(double num);
  
  TString operator+(const TString& str);

  char& operator[](size_t index);

  operator double();
  
  friend bool operator>(const TString& str1, const TString& str2);
  
  friend istream& operator>>(istream& stream, TString& str);
  friend ostream& operator<<(ostream& stream, const TString& str);
};

#endif

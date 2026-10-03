#ifndef __TSTRING__HPP__
#define __TSTRING__HPP__

#include <iostream>

using namespace std;

class TString {
  char* arr;
  size_t arr_l;

public:

  TString();
  TString(const char*);
  TString(const TString&);
  ~TString();
  TString operator+(const TString&);
  TString operator+(const char*);
  TString operator==(const TString&);
  TString operator>(const TString&);
  TString operator<(const TString&);

  friend ostream& operator<<(ostream&, const TString&);
  friend istream& operator>>(istream&, TString&);
  
};

#endif

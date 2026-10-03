#include <iostream>
#include <cstring>
#include <cmath>

#include "TString.hpp"

#define MIN_SIZE 1
#define ALLOCATION_FACTOR 2
#define CONV_BUFFER_SIZE 1024

using namespace std;

TString::TString(size_t size) {
  if (size < MIN_SIZE) size = 1;
  allocated = size;
  length = 1;
  arr = new char[allocated];
  arr[0] = '\0';
}

TString::TString(char* str) {
  length = strlen(str);
  allocated = length + 1;
  arr = new char[allocated];
  for (size_t i = 0; i <= length; i++) arr[i] = str[i];
}

TString::TString(const char* str) {
  length = strlen(str);
  allocated = length + 1;
  arr = new char[allocated];
  for (size_t i = 0; i <= length; i++) arr[i] = str[i];
}

TString::TString(const TString& str) {
  length = str.length;
  allocated = str.allocated;
  arr = new char[allocated];
  for (size_t i = 0; i <= length; i++) arr[i] = str.arr[i];
}

TString::~TString() {
  if (allocated > 0)
	delete[] arr;
}

TString& TString::operator=(char* str) {
  length = strlen(str);
  allocated = length + 1;
  delete[] arr;
  arr = new char[allocated];
  for (size_t i = 0; i <= length; i++) arr[i] = str[i];

  return *this;
}

TString& TString::operator=(const TString& str) {
  length = str.length;
  allocated = str.allocated;
  delete[] arr;
  arr = new char[allocated];
  for (size_t i = 0; i <= length; i++) arr[i] = str.arr[i];

  return *this;
}

TString& TString::operator=(double num) {

  // Двигаем число влево, чтобы не было мантиссы для удобства работы
  // Но записываем длину мантиссы для восстановления

  unsigned int mant_len = 0;
  bool sign = 0;
  bool zero = 0;

  if (num < 0) {
	sign = 1;
	num *= -1;
  }

  if (num < 1) zero = 1;
  
  for (; num > (long int)num; ++mant_len, num *= 10);

  long int inum = (long int)num;
  char buffer[CONV_BUFFER_SIZE];
  size_t i;

  for (i = 0; ((i < CONV_BUFFER_SIZE - 2) && (inum > 0)); i++) {
	if ((i == mant_len) && (mant_len > 0)) {
	  buffer[i++] = '.';
	}
	  buffer[i] = (inum % 10) + 48;
	  inum /= 10;
  }
  if (zero) {buffer[i++] = '.'; buffer[i++] = '0';};
  if (sign) buffer[i++] = '-';
  buffer[i] = '\0';
  
  length = strlen(buffer);
  allocated = length + 1;
  delete[] arr;
  arr = new char[allocated];

  for (i = 0; i < length; i++) {
	arr[i] = buffer[length - i - 1];
  }
  arr[i] = '\0';

  return *this;
}

TString TString::operator+(const TString& str) {
  TString res(length + str.length + 1);
  res.length = res.allocated - 1;
  char* ptr = res.arr;
  for (size_t i = 0; i < length; i++) *ptr++ = arr[i];
  for (size_t i = 0; i <= str.length; i++) *ptr++ = str.arr[i];

  return res;
}

char& TString::operator[](size_t index) {
  return arr[index % length];
}

bool operator>(const TString& str1, const TString& str2) {
  size_t i;
  for (i = 0; (str1.arr[i] != '\0') && (str1.arr[i] == str2.arr[i]); i++);
  return str1.arr[i] > str2.arr[i];
}

TString::operator double() {
  double res = 0;
  bool sign = 0;
  char buf;
  char* ptr = arr;

  if (*ptr == '-') {
	sign = 1;
	ptr++;
  }
  
  for (; (48 <= *ptr) && (*ptr <= 57); ptr++) {
	res *= 10;
	res += (*ptr - 48);
  }
  
  if ((*ptr != '.') && (*ptr != ',')) return res;
  
  unsigned int dec_pow = 10;
  
  for (ptr++; (48 <= *ptr) && (*ptr <= 57); ptr++, dec_pow *= 10) {
	res += (double)(*ptr - 48) / dec_pow;
  }

  if (sign) res *= -1;
  
  return res;
}

istream& operator>>(istream& stream, TString& str) {
  char buffer[1024];
  stream >> buffer;
  str = buffer;
  return stream;
}

ostream& operator<<(ostream& stream, const TString& str) {
  stream << str.arr;
  return stream;
}

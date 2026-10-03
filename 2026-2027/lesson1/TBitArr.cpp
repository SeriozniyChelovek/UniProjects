#include <iostream>
#include "TBitArr.hpp"

using namespace std;

size_t TBitArr::ul2d32(size_t num) {
	return (num + 31) >> 5;
}

TBitArr::TBitArr(size_t in_size) {
	len = in_size;
	arr_l = ul2d32(len);
	arr = new unsigned int[arr_l];
}

TBitArr::TBitArr(string in_str) {
	len = in_str.size();
	arr_l = ul2d32(len);
	arr = new unsigned int[arr_l];

	for (size_t i = 0; in_str[i] == '0' || in_str[i] == '1'; i++) {
		if (in_str[i] == '1') set(i);
	}
}

TBitArr::~TBitArr() {
	delete[] arr;
}

unsigned int TBitArr::getLInd(unsigned int el_num) {
	return el_num & 31;
}
size_t TBitArr::getHInd(unsigned int el_num) {
	return el_num >> 5;
}

TBitArr& TBitArr::operator=(const TBitArr& op2) {
	len = op2.len;
	arr_l = op2.arr_l;
	delete[] arr;
	arr = new unsigned int[arr_l];
	for (size_t i = 0; i < arr_l; i++)
		arr[i] = op2.arr[i];
	return *this;
}

void TBitArr::set(unsigned int FInd) {
	if (FInd > len) return;

	unsigned int LInd;
	size_t HInd;

	LInd = getLInd(FInd);
	HInd = getHInd(FInd);
	
	//cout << "---\n" << LInd << '|' << HInd << "\n---\n";

	arr[HInd] = arr[HInd] | (1 << LInd);
}

void TBitArr::unset(unsigned int FInd) {
	if (FInd > len) return;

	unsigned int LInd;
	size_t HInd;

	LInd = getLInd(FInd);
	HInd = getHInd(FInd);

	arr[HInd] = arr[HInd] & ~(1 << LInd);
}

bool TBitArr::get(unsigned int FInd) {
	if (FInd > len) return 0;

	unsigned int LInd;
	size_t HInd;

	LInd = getLInd(FInd);
	HInd = getHInd(FInd);

	return (arr[HInd] & (1 << LInd)) != 0;
}


istream& operator>>(istream& stream, TBitArr& bitarr) {
	size_t ptr = 0;
	char in_ch;
	string in_str;
	stream >> in_str;
	
	while (ptr <= bitarr.len) {
		in_ch = in_str[ptr];
		if (in_ch == '1') bitarr.set(ptr++);
		else if (in_ch == '0') bitarr.unset(ptr++);
		else break;
	}
	return stream;
}

ostream& operator<<(ostream& stream, TBitArr& bitarr) {
	size_t el_amount = bitarr.len;
	for (size_t i = 0; i < el_amount; i++) {
		stream << bitarr.get(i);
	}
	return stream;
}

bool TBitArr::operator==(const TBitArr& op2) {
	if (len != op2.len) return false;
	for (size_t i = 0; i < arr_l; i++)
		if (arr[i] != op2.arr[i]) return false;
	return true;
}

TBitArr TBitArr::operator&(const TBitArr& op2) {
	size_t min_len = len;
	if (op2.len < min_len) min_len = op2.len;
	TBitArr res(min_len);
	for (size_t i = 0; i < res.arr_l; i++)
		res.arr[i] = arr[i] & op2.arr[i];
	return res;
}

TBitArr TBitArr::operator|(const TBitArr& op2) {
	size_t max_len = len;
	if (op2.len > max_len) max_len = op2.len;
	TBitArr res(max_len);
	for (size_t i = 0; i < arr_l; i++)
		res.arr[i] = arr[i];
	for (size_t i = 0; i < op2.arr_l; i++)
		res.arr[i] = res.arr[i] | op2.arr[i];
	return res;
}

TBitArr TBitArr::operator~() {
	TBitArr res(len);
	for (size_t i = 0; i < arr_l; i++)
		res.arr[i] = ~arr[i];
	return res;
}


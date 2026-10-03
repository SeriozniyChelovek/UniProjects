#ifndef __TBITARR__HPP__
#define __TBITARR__HPP__

#include <iostream>
#include <string>

using namespace std;

class TBitArr {
	size_t arr_l;
	size_t len;
	unsigned int* arr;

	unsigned int getLInd(unsigned int el_num);
	size_t getHInd(unsigned int el_num);

	size_t ul2d32(size_t);

	public:
	
	TBitArr(size_t in_size);
	TBitArr(string in_str);
	~TBitArr();

	TBitArr& operator=(const TBitArr&);

	void set(unsigned int);
	void unset(unsigned int);
	bool get(unsigned int);

	friend istream& operator>>(istream& stream, TBitArr&);
	friend ostream& operator<<(ostream& stream, TBitArr&);

	bool operator==(const TBitArr& op2);
	TBitArr operator&(const TBitArr& op2);
	TBitArr operator|(const TBitArr& op2);
	TBitArr operator~();
};

#endif

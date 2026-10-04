#ifndef __TSET__HPP__
#define __TSET__HPP__

#include "TBitArr.hpp"
#include <iostream>

using namespace std;

class TSet {
	size_t max_el;
	TBitArr bitarr;

	public:

	TSet(const size_t& in_max_el);
	TSet(TBitArr& in_bitarr);
	TSet(TSet& in_set);

	void add(size_t el);
	void del(size_t el);
	bool isIn(size_t el);
	size_t getMax() const;

	operator TBitArr();

	friend ostream& operator<<(ostream& stream, TSet&);

	bool operator==(const TSet& op2);
	TSet operator&(const TSet& op2);
	TSet operator|(const TSet& op2);
	TSet operator~();
};

#endif

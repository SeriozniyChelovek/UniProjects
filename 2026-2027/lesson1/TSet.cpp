#include <iostream>
#include "TSet.hpp"

using namespace std;

TSet::TSet(const size_t& in_max_el) : bitarr(in_max_el), max_el(in_max_el) {};
TSet::TSet(const TBitArr& in_bitarr) : bitarr(in_bitarr), max_el(in_bitarr.getLen()) {};
TSet::TSet(const TSet& in_set) : bitarr(in_set.bitarr), max_el(in_set.getMax()) {};
TSet::TSet(TSet&& moved) : bitarr(moved.bitarr), max_el(moved.getMax()) {};

TSet& TSet::operator=(const TSet& moved) {
    bitarr = moved.bitarr;
    max_el = moved.max_el;
    return *this;
}

void TSet::add(size_t el) {
    bitarr.set(el);
}

void TSet::del(size_t el) {
    bitarr.unset(el);
}

bool TSet::isIn(size_t el) {
    return bitarr.get(el);
}

size_t TSet::getMax() const {
    return max_el;
}

TSet::operator TBitArr() {
    TBitArr res = bitarr;
    res.purify();
    return res;
}

ostream& operator<<(ostream& stream, TSet& op_set) {
    stream << '{' << ' ';
    for (size_t i = 0; i < op_set.max_el; i++) {
        if (op_set.bitarr.get(i)) stream << i << ' ';
    }
    stream << '}';
    return stream;
}

bool TSet::operator==(const TSet& op2) {
    return bitarr == op2.bitarr;
}
TSet TSet::operator&(const TSet& op2) {
    TSet res = *this;
    res.bitarr = res.bitarr & op2.bitarr;
    return res;
}
TSet TSet::operator|(const TSet& op2) {
    TSet lop2 = op2;
    TBitArr b1(*this), b2(lop2);
    TBitArr bres = b1 | b2;
    TSet res(bres);
    return res;
}
TSet TSet::operator~() {
    TSet res(this->bitarr);
    TBitArr buf = res;
    res.bitarr = ~res.bitarr;
    return res;
}

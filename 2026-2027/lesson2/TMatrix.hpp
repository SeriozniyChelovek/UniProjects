#ifndef __TMATRIX__HPP__
#define __TMATRIX__HPP__

#include "TVector.hpp"
#include <iostream>
#include <string.h>

template <typename T>
class TMatrix : public TVector<TVector<T>> {

    size_t rows, cols;

    public:
        TMatrix(size_t o_rows, size_t o_cols) : TVector<TVector<T>>(o_rows, TVector<T>(o_cols)), rows(o_rows), cols(o_cols) {};

};

#endif

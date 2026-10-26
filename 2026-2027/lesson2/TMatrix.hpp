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
        TMatrix(const TMatrix& o_matr) : TVector<TVector<T>>(o_matr.rows, TVector<T>(o_matr.cols)), rows(o_matr.rows), cols(o_matr.cols) {
            for (size_t i = 0; i < rows; i++)
                for (size_t j = 0; j < cols; j++)
                    this->arr[i][j] = o_matr[i][j];
        };

        TMatrix(const TVector<TVector<T>>& o_v2) : TVector<TVector<T>>(o_v2.getLength(), TVector<T>(o_v2[0].getLength())), rows(o_v2.getLength()), cols(o_v2[0].getLength()) {
            for (size_t i = 0; i < rows; i++)
                for (size_t j = 0; j < cols; j++)
                    this->arr[i][j] = o_v2[i][j];
        };

        operator TVector<TVector<T>>() {
            TVector<TVector<T>> res(rows, TVector<T>(cols));
            for (size_t i = 0; i < rows; i++)
                for (size_t j = 0; j < cols; j++)
                    res[i][j] = this->arr[i][j];
            return res;
        };
};

#endif

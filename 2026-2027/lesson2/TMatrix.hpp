#ifndef __TMATRIX__HPP__
#define __TMATRIX__HPP__

#include "TVector.hpp"
#include <iostream>
#include <string.h>
#include <utility>

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

        TMatrix(TMatrix&& o_matr) : TVector<TVector<T>>(std::move(o_matr)), rows(o_matr.rows), cols(o_matr.cols) {
            o_matr.rows = 0;
            o_matr.cols = 0;
        };

        TMatrix(const TVector<TVector<T>>& o_v2) : TVector<TVector<T>>(o_v2.getLength(), TVector<T>(o_v2.getLength() ? o_v2[0].getLength() : 0)), rows(o_v2.getLength()), cols(o_v2.getLength() ? o_v2[0].getLength() : 0) {
            for (size_t i = 0; i < rows; i++)
                for (size_t j = 0; j < cols; j++)
                    this->arr[i][j] = o_v2[i][j];
        };

        operator TVector<TVector<T>>() const {
            TVector<TVector<T>> res(rows, TVector<T>(cols));
            for (size_t i = 0; i < rows; i++)
                for (size_t j = 0; j < cols; j++)
                    res[i][j] = this->arr[i][j];
            return res;
        };

        TMatrix<T>& operator=(const TMatrix<T>& o_matr) {
            if (this != &o_matr) {
                TVector<TVector<T>>::operator=(o_matr); // глубокое копирование строк
                rows = o_matr.rows;
                cols = o_matr.cols;
            }
            return *this;
        };

        TMatrix<T>& operator=(TMatrix<T>&& o_matr) {
            if (this != &o_matr) {
                TVector<TVector<T>>::operator=(std::move(o_matr));
                rows = o_matr.rows;
                cols = o_matr.cols;
                o_matr.rows = 0;
                o_matr.cols = 0;
            }
            return *this;
        };

        bool operator==(const TMatrix<T>& o_matr) const {
            if (rows != o_matr.rows || cols != o_matr.cols) return false;
            for (size_t i = 0; i < rows; i++)
                for (size_t j = 0; j < cols; j++)
                    if (!(this->arr[i][j] == o_matr.arr[i][j]))
                        return false;
            return true;
        };

        bool operator!=(const TMatrix<T>& o_matr) const {
            return !(*this == o_matr);
        };

        TMatrix<T> operator+(const TMatrix<T>& o_matr) const {
            if (rows != o_matr.rows || cols != o_matr.cols) {
                throw "Cannot sum up matrices with different sizes";
            }
            TMatrix<T> res(*this);
            for (size_t i = 0; i < rows; i++)
                for (size_t j = 0; j < cols; j++)
                    res.arr[i][j] = res.arr[i][j] + o_matr.arr[i][j];
            return res;
        };

        TMatrix<T> operator-(const TMatrix<T>& o_matr) const {
            if (rows != o_matr.rows || cols != o_matr.cols) {
                throw "Cannot subtract matrices with different sizes";
            }
            TMatrix<T> res(*this);
            for (size_t i = 0; i < rows; i++)
                for (size_t j = 0; j < cols; j++)
                    res.arr[i][j] = res.arr[i][j] - o_matr.arr[i][j];
            return res;
        };

        TMatrix<T> operator*(const TMatrix<T>& o_matr) const { // матричное умножение
            if (cols != o_matr.rows) {
                throw "Cannot multiply matrices with incompatible sizes";
            }
            TMatrix<T> res(rows, o_matr.cols);
            for (size_t i = 0; i < rows; i++)
                for (size_t j = 0; j < o_matr.cols; j++)
                    for (size_t k = 0; k < cols; k++)
                        res.arr[i][j] = res.arr[i][j] + this->arr[i][k] * o_matr.arr[k][j];
            return res;
        };

        TMatrix<T> operator*(T op2) const {
            TMatrix<T> res(*this);
            for (size_t i = 0; i < rows; i++)
                for (size_t j = 0; j < cols; j++)
                    res.arr[i][j] = res.arr[i][j] * op2;
            return res;
        };
};

#endif

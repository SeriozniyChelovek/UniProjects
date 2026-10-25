#ifndef __TVECTOR__HPP__
#define __TVECTOR__HPP__

#include <iostream>
#include <string.h>

using namespace std;

template <typename T>
class TVector {

    size_t length; // max_index = length - 1
    T* arr;

    public:
        TVector(size_t o_length = 1) : length(o_length) {
            arr = new T[length];
        };

        TVector(TVector<T> const &o_vec) : length(o_vec.length) {
            arr = new T[length];
            memcpy(arr, o_vec.arr, length * sizeof(T));
        };

        TVector(T* o_arr, size_t o_length) : length(o_length) {
            arr = new T[length];
            memcpy(arr, o_arr, length * sizeof(T));
        };

        ~TVector() {
            delete[] arr;
        };

        size_t getLength() const {
            return length;
        };

        T& operator[](size_t index) const {
            return arr[index];
        };

        TVector<T>& operator=(TVector<T>&& op2) {
            length = op2.length;
            delete[] arr;
            memcpy(arr, op2.arr, length * sizeof(T));
            return *this;
        };

        bool operator==(TVector<T> op2) const {
            if (length != op2.length) return false;
            for (size_t i = 0; i < length; i++) {
                if (arr[i] != op2.arr[i])
                    return false;
            }
            return true;
        };

        TVector<T> operator+(TVector<T> op2) const {
            if (length != op2.length) {
                throw "Cannot sum up vectors with diffetent length";
            }
            TVector<T> res(*this);
            for (size_t i = 0; i < length; i++) {
                res.arr[i] = res.arr[i] + op2.arr[i];
            }
            return res;
        };

        T operator*(TVector<T> op2) const {
            if (length != op2.length) {
                throw "Cannot multiply vectors with diffetent length";
            }
            T res = arr[0] * op2.arr[0];
            for (size_t i = 1; i < length; i++) {
                res = res + arr[i] * op2.arr[i];
            }
            return res;
        };

        TVector<T> operator*(T op2) const {
            TVector<T> res(*this);
            for (size_t i = 0; i < length; i++) {
                res.arr[i] = res.arr[i] * op2;
            }
            return res;
        };

        friend ostream& operator<<(ostream& stream, const TVector<T>& op2) {
            stream << '(' << ' ';
            for (size_t i = 0; i < op2.length; i++)
                stream << op2.arr[i] << ' ';
            stream << ')';
            return stream;
        };
};

#endif

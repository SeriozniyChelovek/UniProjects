#ifndef __TVECTOR__HPP__
#define __TVECTOR__HPP__

#include <iostream>

using namespace std;

template <typename T>
class TVector {

    protected:
        size_t length; // max_index = length - 1
        T* arr;

    public:
        TVector(size_t o_length = 1) : length(o_length) {
            arr = new T[length](); // value-init: элементы T() = 0
        };

        TVector(size_t o_length, const T &o_value) : length(o_length) { // Конструктор с заполнением. Нужен для работы TMatrix
            arr = new T[length];
            for (size_t i = 0; i < length; i++) {
                arr[i] = o_value;
            }
        };

        TVector(TVector<T> const &o_vec) : length(o_vec.length) {
            arr = new T[length];
            for (size_t i = 0; i < length; i++) {
                arr[i] = o_vec.arr[i];
            }
        };

        TVector(TVector<T>&& o_vec) : length(o_vec.length) {
            arr = o_vec.arr;
            o_vec.arr = nullptr;
            o_vec.length = 0;
        };

        TVector(T* o_arr, size_t o_length) : length(o_length) {
            arr = new T[length];
            for (size_t i = 0; i < length; i++) {
                arr[i] = o_arr[i];
            }
        };

        ~TVector() {
            delete[] arr;
        };

        size_t getLength() const {
            return length;
        };

        T& operator[](size_t index) {
            if (index >= length) {
                throw "Incorrect index";
            }
            return arr[index];
        };

        const T& operator[](size_t index) const {
            if (index >= length) {
                throw "Incorrect index";
            }
            return arr[index];
        };

        TVector<T>& operator=(const TVector<T>& op2) {
            if (this != &op2) {
                length = op2.length;
                delete[] arr;
                arr = new T[length];
                for (size_t i = 0; i < length; i++) {
                    arr[i] = op2.arr[i];
                }
            }
            return *this;
        };

        TVector<T>& operator=(TVector<T>&& op2) {
            if (this != &op2) {
                delete[] arr;
                arr = op2.arr;
                length = op2.length;
                op2.arr = nullptr;
                op2.length = 0;
            }
            return *this;
        };

        bool operator==(const TVector<T>& op2) const {
            if (length != op2.length) return false;
            for (size_t i = 0; i < length; i++) {
                if (!(arr[i] == op2.arr[i]))
                    return false;
            }
            return true;
        };

        TVector<T> operator+(const TVector<T>& op2) const {
            if (length != op2.length) {
                throw "Cannot sum up vectors with different length";
            }
            TVector<T> res(*this);
            for (size_t i = 0; i < length; i++) {
                res.arr[i] = res.arr[i] + op2.arr[i];
            }
            return res;
        };

        T operator*(const TVector<T>& op2) const {
            if (length != op2.length) {
                throw "Cannot multiply vectors with different length";
            }
            T res = T();
            for (size_t i = 0; i < length; i++) {
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

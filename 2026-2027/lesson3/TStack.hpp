#ifndef __TSTACK__HPP__
#define __TSTACK__HPP__

#include <iostream>

using namespace std;

template <typename T>
class TStack {
    T* arr;
    size_t arr_l;
    size_t top;

    public:
        TStack(size_t in_arr_l = 1) : arr_l(in_arr_l), top(0) {
            arr = new T[arr_l];
        };
        ~TStack() {
            delete[] arr;
        };
        bool isFull() const noexcept {
            return top == arr_l;
        };
        bool isEmpty() const noexcept {
            return top == 0;
        };
        T push(T el) {
            arr[top++] = el;
            return el;
        };
        T pop() {
            return arr[--top];
        };
        T getTop() const noexcept {
            return arr[top];
        };
        friend ostream& operator<<(ostream& stream, const TStack<T>& stack) {
            for (size_t i = 0; i < stack.top; i++)
                stream << stack.arr[i] << ' ';
            return stream;
        };
};

#endif

#ifndef __TQUEUE__HPP__
#define __TQUEUE__HPP__

#include <iostream>

using namespace std;

template <typename T>
class TQueue {
    T* arr;
    size_t arr_l;
    size_t head;
    size_t tail;
    bool _last_push = false;

    public:
        TQueue(size_t in_arr_l = 1) : arr_l(in_arr_l), head(0), tail(0) {
            arr = new T[arr_l];
        };
        TQueue(const TQueue& other) : arr_l(other.arr_l), head(other.head), tail(other.tail), _last_push(other._last_push) {
            arr = new T[arr_l];
            for (size_t i = 0; i < arr_l; i++) {
                arr[i] = other.arr[i];
            }
        };
        TQueue& operator=(const TQueue& other) {
            T* new_arr = new T[other.arr_l];
            for (size_t i = 0; i < other.arr_l; i++) {
                new_arr[i] = other.arr[i];
            }
            delete[] arr;
            arr = new_arr;
            arr_l = other.arr_l;
            head = other.head;
            tail = other.tail;
            _last_push = other._last_push;
            return *this;
        };
        ~TQueue() {
            delete[] arr;
        };
        bool isFull() const noexcept {
            return (head == tail) && _last_push;
        };
        bool isEmpty() const noexcept {
            return (head == tail) && !_last_push;
        };
        T push(T el) {
            _last_push = true;
            arr[tail] = el;
            tail = (tail + 1) % arr_l;
            return el;
        };
        T pop() {
            _last_push = false;
            T el = arr[head];
            head = (head + 1) % arr_l;
            return el;
        };
        T getTop() const {
            return arr[head];
        };
        friend ostream& operator<<(ostream& stream, const TQueue<T>& queue) {
            TQueue<T> tmp = queue;
            while (!tmp.isEmpty()) {
                stream << tmp.pop() << ' ';
            }
            return stream;
        };
};

#endif

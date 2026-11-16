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
            head = (head + 1) % arr_l;
            return arr[head];
        };
        T getTop() const noexcept {
            return arr[head];
        };
        friend ostream& operator<<(ostream& stream, const TQueue<T>& queue) {
            size_t i = queue.head;
            while (i != queue.tail) {
                i = (i + 1) % queue.arr_l;
                stream << queue.arr[i] << ' ';
            }
            return stream;
        };
};

#endif

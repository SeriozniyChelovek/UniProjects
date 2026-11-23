#ifndef __TLIST__HPP__
#define __TLIST__HPP__

#include "TNode.hpp"
#include <iostream>

using namespace std;

template <typename T>
class TList {
    TNode<T>* pFirst;
    size_t length;

    TNode<T>* getNode(ssize_t ind) const {
        TNode<T>* node = pFirst;
        for (ssize_t i = 0; i < ind; i++)
            node = node->pNext;
        return node;
    }

    public:
        TList() : pFirst(nullptr), length(0) {}

        TList(const TList& other) : pFirst(nullptr), length(0) {
            copyFrom(other);
        }

        ~TList() {
            while (pFirst != nullptr) {
                TNode<T>* next = pFirst->pNext;
                delete pFirst;
                pFirst = next;
            }
        }

        T add(T el, ssize_t ind = -1) {
            if (ind == -1)
                ind = (ssize_t)length;

            TNode<T>* node = new TNode<T>;
            node->data = el;

            if (ind == 0) {
                node->pNext = pFirst;
                pFirst = node;
            } else {
                TNode<T>* prev = getNode(ind - 1);
                node->pNext = prev->pNext;
                prev->pNext = node;
            }

            length += 1;
            return el;
        }

        T pop(ssize_t ind = -1) {
            if (ind == -1)
                ind = (ssize_t)length - 1;

            TNode<T>* node;

            if (ind == 0) {
                node = pFirst;
                pFirst = node->pNext;
            } else {
                TNode<T>* prev = getNode(ind - 1);
                node = prev->pNext;
                prev->pNext = node->pNext;
            }

            T val = node->data;
            delete node;

            length -= 1;
            return val;
        }

        T& operator[](size_t ind) {
            return getNode((ssize_t)ind)->data;
        }

        size_t getLength() const noexcept {
            return length;
        }

        bool isEmpty() const noexcept {
            return length == 0;
        }

        friend ostream& operator<<(ostream& stream, const TList<T>& outlist) {
            stream << ' ';
            for (TNode<T>* node = outlist.pFirst; node != nullptr; node = node->pNext) {
                stream << node->data << ' ';
            }

            return stream;
        }
};

#endif

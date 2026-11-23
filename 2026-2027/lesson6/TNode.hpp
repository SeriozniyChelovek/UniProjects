#ifndef __TNODE__HPP__
#define __TNODE__HPP__

template <typename T>
struct TNode {
    T data;
    TNode<T>* pNext;
};

#endif

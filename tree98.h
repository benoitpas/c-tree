#ifndef TREE98_H
#define TREE98_H

#include <utility>

template <typename T> class Tree {
private:
    T value;
    Tree* left;
    Tree* right;

public:
    Tree(T v, Tree* l, Tree* r);

    Tree<std::pair<int,T>>* addId();
};

template <typename T> Tree<T>::Tree(T v, Tree* l, Tree* r)
{
    value = v;
    left = l;
    right = r;
}

template <typename T> Tree<std::pair<int,T>>* Tree<T>::addId(){
    return 0;
}

#endif // TREE98_H
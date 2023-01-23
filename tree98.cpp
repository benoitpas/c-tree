#include "tree98.h"

template <typename T> Tree<T>::Tree(T v, Tree* l, Tree* r)
{
    value = v;
    left = l;
    right = r;
}

template <typename T> Tree<std::pair<int,T>>* Tree<T>::addId(){
    return null;
}
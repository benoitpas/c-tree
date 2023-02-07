#ifndef TREE98_H
#define TREE98_H

#include <sstream>
#include <stack>
#include <string>
#include <utility>

template <typename T> class Tree {
private:
    T value;
public:
    Tree<T>* left;
    Tree<T>* right;

public:
    Tree(T v);
    Tree(T v, Tree<T>* l, Tree<T>* r);

    T getValue() const { return value; };

    Tree<std::pair<int,T>>* addId() const;

    std::string toString() const;
};

template <typename T> Tree<T>::Tree(T v)
{
    value = v;
    left = nullptr;
    right = nullptr;
}

template <typename T> Tree<T>::Tree(T v, Tree* l, Tree* r)
{
    value = v;
    left = l;
    right = r;
}

template <typename T> Tree<std::pair<int,T>>* Tree<T>::addId() const
{
    Tree<std::pair<int,T>>* r;

    std::stack<std::pair<const Tree<T>*,Tree<std::pair<int,T>>**>> s;
    s.push(std::pair(this, &r));

    int id = 0;
    while(!s.empty())
    {
        auto p = s.top();
        s.pop();
        // Create the new leaf
        auto l = new Tree<std::pair<int,T>>(std::pair<int,T>(id++, p.first->getValue()));
        *p.second = l;

        // Then add left/right nodes to be processed
        if (p.first->left != nullptr) { s.push(*new std::pair(p.first->left, &l->left)); }
        if (p.first->right != nullptr) { s.push(*new std::pair(p.first->right, &l->right)); }
    }
    return r;
}

template <typename T> std::string Tree<T>::toString() const
{
    std::string empty = "";
    std::ostringstream ost;

    ost << "(" << valueToString(value) << (left == nullptr ? empty : "," + left->toString())
               << (right == nullptr ? empty : "," + right->toString()) << ")";

    return ost.str();
}

template <typename T> bool operator==(const Tree<T>& lhs, const Tree<T>& rhs)
{
    return (lhs.getValue() == rhs.getValue()
        && (lhs.left == rhs.left || (lhs.left != nullptr && *lhs.left == *rhs.left))
        && (lhs.right == rhs.right || (lhs.right != nullptr && *lhs.right == *rhs.right)));
}

#endif // TREE98_H
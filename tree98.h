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
    Tree(T v, Tree<T>* l, Tree<T>* r);

    T getValue() const { return value; };
    Tree<T>* getLeft() const { return left; }
    Tree<T>* getRight() const{ return right; }

    Tree<std::pair<int,T>>* addId() const;

    std::string toString() const;
};

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
        std::pair<const Tree<T>*,Tree<std::pair<int,T>>**> p = s.top();
        s.pop();
        // Create the new leaf
        Tree<std::pair<int,T>>* l = new Tree<std::pair<int,T>>(std::pair<int,T>(id++, p.first->getValue()), 0, 0);
        *p.second = l;

        // Then add left/right nodes to be processed
        if (p.first->getLeft() != 0) { s.push(*new std::pair(p.first->getLeft(), &l->left)); }
        if (p.first->getRight() != 0) { s.push(*new std::pair(p.first->getRight(), &l->right)); }
    }
    return r;
}

template <typename T> std::string Tree<T>::toString() const
{
    std::string empty = "";
    std::ostringstream ost;
    ost << "(" << valueToString(value) << (left == 0 ? empty : "," + left->toString())
               << (right == 0 ? empty : "," + right->toString()) << ")";
    return ost.str();
}

template <typename T> bool operator==(const Tree<T>& lhs, const Tree<T>& rhs)
{
    return (lhs.getValue() == rhs.getValue()
        && (lhs.getLeft() == rhs.getLeft() || (lhs.getLeft() != 0 && *lhs.getLeft() == *rhs.getLeft()))
        && (lhs.getRight() == rhs.getRight() || (lhs.getRight() != 0 && *lhs.getRight() == *rhs.getRight())));
}

#endif // TREE98_H
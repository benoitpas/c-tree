#include <memory>
#include <variant>


template<typename T>
using Ptr = std::shared_ptr<T>;

struct Nil {};

template<typename T>
struct Tree {
    T value;
    Ptr<std::variant<Nil, Tree<T>>> left;
    Ptr<std::variant<Nil, Tree<T>>> right;
    Tree(T v, Ptr<std::variant<Nil, Tree<T>>> l,Ptr<std::variant<Nil, Tree<T>>> r): value(v) { left = l; right = r; };
};
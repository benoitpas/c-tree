#include <memory>
#include <optional>

template<typename T>
using Ptr = std::shared_ptr<T>;

struct Nil {};

template<typename T>
struct Tree {
    T value;
    std::optional<Ptr<Tree<T>>> left;
    std::optional<Ptr<Tree<T>>> right;

    Tree(T v, std::optional<Ptr<Tree<T>>> l,std::optional<Ptr<Tree<T>>> r)
    : value(v)
    {
        left = l;
        right = r;
    }

    Tree(T v, Tree<T>* l, Tree<T>* r)
    : value(v)
    {
        left = std::optional<Ptr<Tree<const char*>>>(l);
        right = std::optional<Ptr<Tree<const char*>>>(r);
    }

    static std::string toString(std::optional<Ptr<Tree<T>>> v)
    {
        std::ostringstream ost;
        if (v) {
            ost << "," << v->get()->toString();
        }
        return ost.str();
    }

    std::string toString() const
    {
        std::string empty = "";
        std::ostringstream ost;

        ost << "(" << valueToString(value) << toString(left) << toString(right) << ")";

        return ost.str();
    }
};

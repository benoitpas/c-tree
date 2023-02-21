#include <memory>
#include <optional>

template<typename T>
using Opt = std::optional<T>;

template<typename T1, typename T2>
using Pair = std::pair<T1,T2>;

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
        left = std::optional<Ptr<Tree<T>>>(l);
        right = std::optional<Ptr<Tree<T>>>(r);
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

//        auto toString = [](std::optional<Ptr<Tree<T>>> v, std::ostringstream ost) {
//            if (v) { ost << "," << v->get()->toString(); };
//        };

        ost << "(" << valueToString(value) << toString(left) << toString(right) << ")";

        return ost.str();
    }

    Ptr<Tree<std::pair<int,T>>> addId(int id) {
        int nId = id;
        std::optional<Ptr<Tree<std::pair<int,T>>>> lId = std::nullopt;
        if (left) {
            auto l = left->get()->addId(id);
            lId = std::optional(l);
            nId = l->value.first + 1;
        }

        std::optional<Ptr<Tree<std::pair<int,T>>>> rId = std::nullopt;
        if (right) {
            auto r = right->get()->addId(nId);
            rId = std::optional(r);
            nId = r->value.first + 1;
        }

        Tree<std::pair<int,T>>* r = new Tree<std::pair<int,T>>(std::pair<int,T>(nId, value), lId, rId);
        return std::shared_ptr<Tree<std::pair<int,T>>>(r);
    }
};

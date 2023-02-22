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
    Opt<Ptr<Tree<T>>> left;
    Opt<Ptr<Tree<T>>> right;

    Tree(T v, Opt<Ptr<Tree<T>>> l,Opt<Ptr<Tree<T>>> r)
    : value(v)
    {
        left = l;
        right = r;
    }

    Tree(T v, Tree<T>* l, Tree<T>* r)
    : value(v)
    {
        left = Opt<Ptr<Tree<T>>>(l);
        right = Opt<Ptr<Tree<T>>>(r);
    }

    std::string toString() const
    {
        std::string empty = "";
        std::ostringstream ost;

        auto toString = [&](Opt<Ptr<Tree<T>>> v) {
            if (v) { ost << "," << v->get()->toString(); }
        };

        ost << "(" << valueToString(value);
        toString(left);
        toString(right);
        ost << ")";

        return ost.str();
    }

    Ptr<Tree<Pair<int,T>>> addId(int id) {
        int nId = id;
        Opt<Ptr<Tree<Pair<int,T>>>> lId = std::nullopt;
        if (left) {
            auto l = left->get()->addId(id);
            lId = Opt(l);
            nId = l->value.first + 1;
        }

        Opt<Ptr<Tree<Pair<int,T>>>> rId = std::nullopt;
        if (right) {
            auto r = right->get()->addId(nId);
            rId = Opt(r);
            nId = r->value.first + 1;
        }

        Tree<Pair<int,T>>* r = new Tree<Pair<int,T>>(Pair<int,T>(nId, value), lId, rId);
        return std::shared_ptr<Tree<Pair<int,T>>>(r);
    }
};

template <typename T> class Tree {
private:
    T value;
    Tree* left;
    Tree* right;

public:
    Tree(T v, Tree* l, Tree* r);
};
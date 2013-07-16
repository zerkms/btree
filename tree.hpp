#ifndef TREE_HPP_
#define TREE_HPP_

#include <memory>

#include "node.hpp"

namespace zerkms { namespace btree {

class Tree {
private:
    size_t t_;
    SharedNode root_;

public:
    Tree(size_t);

public:
    SharedNode Insert(const char);

private:
    void InsertNonFull(SharedNode, const char);
    void SplitChild(SharedNode, size_t);
};

}}

#endif
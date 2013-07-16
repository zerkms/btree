#include <iostream>

#include "node.hpp"

namespace b = zerkms::btree;

#if _DEBUG
size_t b::Node::counter_ = 0;
#endif

b::Node::Node(size_t t)
    :
    n_(0), isLeaf_(true), t_(t)
{
    keys_.reserve(2 * t - 1);
    children_.reserve(2 * t);

#if _DEBUG
    id_ = counter_++;
    std::cout << "Created node: " << id_  << std::endl;
#endif
}

b::Node::~Node()
{
#if _DEBUG
    std::cout << "Destroyed node: " << id_  << std::endl;
#endif
}

void b::Node::SetIsLeaf(bool isLeaf)
{
    isLeaf_ = isLeaf;
}

bool b::Node::IsLeaf()
{
    return isLeaf_;
}

char b::Node::GetKey(size_t i)
{
    return keys_.at(i);
}

void b::Node::SetKey(size_t i, char k)
{
    if (keys_.size() <= i) {
        keys_.resize(i + 1);
    }
    keys_.at(i) = k;
}

b::SharedNode b::Node::GetChild(size_t i)
{
    return children_.at(i);
}

void b::Node::SetChild(size_t i, b::SharedNode child)
{
    if (children_.size() <= i) {
        children_.resize(i + 1);
    }
    children_.at(i) = child;
}

size_t b::Node::GetN()
{
    return n_;
}

void b::Node::SetN(size_t n)
{
    if (keys_.size() > n) {
        keys_.resize(n);
    }

    if (children_.size() > n + 1) {
        children_.resize(n + 1);
    }

    n_ = n;
}
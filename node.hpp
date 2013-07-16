#ifndef NODE_HPP_
#define NODE_HPP_

#include <memory>
#include <vector>

namespace zerkms { namespace btree {

class Node {
#if _DEBUG
private:
    static size_t counter_;
    size_t id_;
#endif

private:
    bool isLeaf_;
    size_t t_;
    size_t n_;
    std::vector<char> keys_;
    std::vector<std::shared_ptr<Node>> children_;

public:
    Node(size_t);
    ~Node();

public:
    void SetIsLeaf(bool);
    bool IsLeaf();
    char GetKey(size_t);
    void SetKey(size_t, char);
    std::shared_ptr<Node> GetChild(size_t);
    void SetChild(size_t, std::shared_ptr<Node>);
    size_t GetN();
    void SetN(size_t);
};

typedef std::shared_ptr<Node> SharedNode;

}}

#endif
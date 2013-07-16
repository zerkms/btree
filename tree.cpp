#include "tree.hpp"

namespace b = zerkms::btree;

b::Tree::Tree(size_t t)
    :
    t_(t), root_(std::make_shared<Node>(t))
{
    root_->SetIsLeaf(true);
}

b::SharedNode b::Tree::Insert(const char key)
{
    SharedNode r = root_;

    if (r->GetN() == 2 * t_ - 1) {
        SharedNode s = std::make_shared<Node>(t_);
        root_ = s;
        s->SetIsLeaf(false);
        s->SetN(0);
        s->SetChild(0, r);
        SplitChild(s, 0);
        InsertNonFull(s, key);

        return s;
    } else {
        InsertNonFull(r, key);

        return r;
    }
}

void b::Tree::InsertNonFull(b::SharedNode x, const char k)
{
    int i = x->GetN() - 1;

    if (x->IsLeaf()) {
        while (i >= 0 && k < x->GetKey(i)) {
            x->SetKey(i + 1, x->GetKey(i));
            --i;
        }

        x->SetKey(i + 1, k);
        x->SetN(x->GetN() + 1);
    } else {
        while (i >= 0 && k < x->GetKey(i)) {
            --i;
        }

        ++i;

        if (x->GetChild(i)->GetN() == 2 * t_ - 1) {
            SplitChild(x, i);

            if (k > x->GetKey(i)) {
                ++i;
            }
        }

        InsertNonFull(x->GetChild(i), k);
    }
}

void b::Tree::SplitChild(b::SharedNode x, size_t i)
{
    SharedNode z(new Node(t_));
    
    SharedNode y = x->GetChild(i);

    z->SetIsLeaf(y->IsLeaf());
    z->SetN(t_ - 1);

    for (size_t j = 0; j <= t_ - 2; ++j) {
        z->SetKey(j, y->GetKey(t_ + j));
    }

    if (!y->IsLeaf()) {
        for (size_t j = 0; j <= t_ - 1; ++j) {
            z->SetChild(j, y->GetChild(t_ + j));
        }
    }

    for (size_t j = x->GetN(); j >= i + 1; --j) {
        x->SetChild(j + 1, x->GetChild(j));
    }
    x->SetChild(i + 1, z);

    for (int j = x->GetN() - 1; j >= (int)i; --j) {
        x->SetKey(j + 1, x->GetKey(j));
    }
    x->SetKey(i, y->GetKey(t_ - 1));
    x->SetN(x->GetN() + 1);

    y->SetN(t_ - 1);
}
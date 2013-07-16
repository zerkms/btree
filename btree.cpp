#include "tree.hpp"

namespace b = zerkms::btree;

int main(int argc, char** argv)
{
    b::Tree tree(2);

    tree.Insert('a');
    tree.Insert('b');
    tree.Insert('c');
    tree.Insert('d');
    tree.Insert('e');
    tree.Insert('f');
    tree.Insert('g');
    tree.Insert('h');

	return 0;
}

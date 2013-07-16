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
    tree.Insert('i');
    tree.Insert('j');
    tree.Insert('k');
    tree.Insert('l');
    tree.Insert('m');
    tree.Insert('n');
    tree.Insert('o');
    tree.Insert('p');
    tree.Insert('q');
    tree.Insert('r');
    tree.Insert('s');
    
	return 0;
}

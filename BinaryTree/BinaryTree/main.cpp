#include <iostream>
#include "BinaryTree.h"

int main(int argc, const char * argv[]) {
    Node<int>standart(10);
    BinaryTree<int> a(&standart);
    a.add(5);
    a.add(15);
    a.add(7);
    a.add(17);
    a.add(1);
    a.add(12);
    a.add(3);
    a.add(18);
    a.postorderTravesal();
    std::cout <<std::endl<<std::endl<<std::endl;
    a.remove(5);
    a.postorderTravesal();
    return 0;
}


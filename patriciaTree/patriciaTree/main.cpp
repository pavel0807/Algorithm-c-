//
//  main.cpp
//  patriciaTree
//
//  Created by Pavel on 20.05.2021.
//

#include <iostream>
#include "Patricia.h"
#include "graphVis.h"

void printBinChar(char symb);

int main(int argc, const char * argv[]) {
    setlocale(LC_ALL, "russian");
    printBinChar('a');
    printBinChar('b');
    printBinChar('c');
    printBinChar('d');


    PatriciaTree<char> tree;
    tree.addNode('a');
    tree.addNode('b');
    tree.addNode('c');
    tree.addNode('d');


    GraphViz<char> graph(&tree, "Graph.dot");
    std::string str = tree.treeToStr();
    std::cout << str << std::endl;
    graph.drawGraph();

    Node<char>* node = tree.searchNode('a');
    node = tree.searchNode('z');
    
}

void printBinChar(char symb)
{
    setlocale(LC_ALL, "russian");
    int mask = 0x80;
    std::cout << symb << "     ";
    while (mask)
    {
        std::cout << (symb & mask ? '1' : '0');
        mask >>= 1;
    }
    std::cout << "     " << symb + 'a';
    std::cout << std::endl;
}


//
//  main.cpp
//  AVL-TREE
//
//  Created by Pavel on 02.04.2021.
//

#include <iostream>
#include "avlTree.h"
#include <vector>
#include "GraphVizFunctions.h"
int main(int argc, const char * argv[]) {
    AVLTREE<int> tree;
    std::vector<int> a = {20,10,30,15,25};
    for(size_t i=0;i<a.size();++i)
    {
        tree.insert(a[i]);
    }
    tree.insert(35);
    GraphViz<int> graph(&tree, "test2.dot");
    graph.drawGraph();
    
    return 0;
}

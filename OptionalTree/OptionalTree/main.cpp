//
//  main.cpp
//  OptionalTree
//
//  Created by Pavel on 22.03.2021.
//
#include "OptiomalTree.h"
#include <iostream>
#include "Graph.h"
bool testOne();
int main(int argc, const char * argv[]) {
    return testOne();
}

bool testOne()
{
    OptimalTree tree({0, 1, 2, 3}, {6, 2, 8, 7},{10, 0, 0, 0, 0});
    
    GraphViz graph(&tree, "Graph.dot");
    

    graph.drawGraph();
    
    if(tree.treeToStr() != "2013")
    {
        return false;
    }
    
    bool searchKey0 = tree.searchNode(0)!= nullptr? true : false;
    bool searchKey1 = tree.searchNode(1)!= nullptr? true : false;
    bool searchKey2 = tree.searchNode(2)!= nullptr? true : false;
    bool searchKey3 = tree.searchNode(3)!= nullptr? true : false;
    bool searchKey4 = tree.searchNode(4)!= nullptr? true : false;
    bool searchKey5 = tree.searchNode(5)!= nullptr? true : false;
    if(searchKey0&&searchKey1&&searchKey2&&searchKey3)
    {
        if(!searchKey4&&!searchKey5)
        {
            return true;
        }
    }
    return false;
}

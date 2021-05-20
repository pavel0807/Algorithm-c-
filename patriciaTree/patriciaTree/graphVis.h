//
//  graphVis.h
//  patriciaTree
//
//  Created by Pavel on 20.05.2021.
//

#ifndef graphVis_h
#define graphVis_h

#include <iostream>
#include <fstream>
#include <string>
#include "Patricia.h"


template<typename T>
class GraphViz
{
public:
    GraphViz(PatriciaTree<T>* treePtr, const char* filename);
    void setFilename(std::string name);
    void drawGraph();
private:
    PatriciaTree<T>* _treePtr = nullptr;
    std::string _filename;
    std::string _dotStr;
    void writeToFile();
    void makeDotStr();
};

template<typename T>
GraphViz<T>::GraphViz(PatriciaTree<T>* treePtr, const char* filename)
    : _treePtr(treePtr), _filename(filename)
{
}

template<typename T>
void GraphViz<T>::setFilename(std::string name)
{
    _filename = name;
}

template<typename T>
void GraphViz<T>::makeDotStr()
{
    std::string resultStr("digraph G {\n");
    _treePtr->graphVizTraversal(resultStr);
    resultStr.append(" \n}");
    _dotStr = resultStr;
}

template<typename T>
void GraphViz<T>::writeToFile()
{
    std::ofstream fout(_filename);
    fout << _dotStr;
    fout.close();
}

template<typename T>
void GraphViz<T>::drawGraph()
{
    this->makeDotStr();
    this->writeToFile();
    std::string commandLineStr("/Users/pavel/Documents/svn/c++/Method/1/OptionalTree/OptionalTree/graphviz/2.47.0/bin/dot -Gcharset=latin1 -Tpng -o result.png ");
    commandLineStr += _filename;
    system(commandLineStr.c_str());
}


#endif /* graphVis_h */

#ifndef Graph_h
#define Graph_h
#include <iostream>
#include <fstream>
#include <string>
#include "OptiomalTree.h"

class GraphViz
{
public:
    GraphViz(OptimalTree* treePtr, const char* filename);
    void setFilename(std::string name);
    void drawGraph();
private:
    OptimalTree* _treePtr = nullptr;
    std::string _filename;
    std::string _dotStr;
    void writeToFile();
    void makeDotStr();
};

GraphViz::GraphViz(OptimalTree* treePtr, const char* filename)
    : _treePtr(treePtr), _filename(filename)
{
}

void GraphViz::setFilename(std::string name)
{
    _filename = name;
}

void GraphViz::makeDotStr()
{
    std::string resultStr("digraph G {\n");
    _treePtr->graphVizTraversal(resultStr);
    resultStr.append(" \n}");
    _dotStr = resultStr;
}

void GraphViz::writeToFile()
{
    std::ofstream fout;
    fout.open(_filename);
    if(fout.is_open())
        std::cout << "good";
    
    fout << _dotStr;
    fout.close();
}

void GraphViz::drawGraph()
{
    this->makeDotStr();
    this->writeToFile();
    std::string commandLineStr("/Users/pavel/Documents/svn/c++/Method/1/OptionalTree/OptionalTree/graphviz/2.47.0/bin/dot -Tpng -o result.jpg ");
    commandLineStr += _filename;
    system(commandLineStr.c_str());
}
#endif

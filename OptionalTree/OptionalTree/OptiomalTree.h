#ifndef OptiomalTree_h
#define OptiomalTree_h
#include <vector>
#include <sstream>
#include <string>
/*
 Реализовать обобщённый (шаблонный) класс оптимального двоичного дерева поиска с конструктором (получающим в качестве параметров массивы ключей ki, вероятностей успешного pi и неуспешного qi поиска), деструктором, а также методами поиска ключей, обхода узлов дерева, вывода в поток в виде строки. При необходимости реализовать и другие методы класса.
 */


//Структура узла с удачной вероятностью поиска
struct Node{
    Node(int dataNew) : data(dataNew), leftChild(nullptr), rightChild(nullptr){};
    int data;
    Node* leftChild = nullptr;
    Node* rightChild = nullptr;
};


//Структура ячейки матрицы
struct elementMatrix{
    int index ;
    int weightedPathLength ;
    int sumWeightsAllSubtreeNodes ;
};



//Класс оптимального дерева
class OptimalTree{
public:
    OptimalTree(const std::vector<int>& key,const std::vector<float>& p,const std::vector<float>& q);
    ~OptimalTree();
    std::string treeToStr();
    Node* searchNode(int key);
    void graphVizTraversal(std::string& odtStr);
    
private:
    void addNodes(Node* currentNode,const std::vector<int>& key,int leftBegin,int leftEnd,int rightBegin,int rightEnd);
    void setElementIJMatrix(std::vector<std::vector<elementMatrix>>& matrix,int i,int j,const std::vector<float>& p,const std::vector<float>& q);
    void setMatrix(const std::vector<int>& key,const std::vector<float>& p,const std::vector<float>& q);
    void remove(Node*& node);
    void nodeToStr(Node*& node, std::string& treeStr);
    Node* search(Node*& node, int key);
    void traversal(Node* node, Node* parentNode, std::string& odtStr);
    void addDotNode(std::string& dotStr, Node* key, Node* value);
private:
    std::vector<std::vector<elementMatrix>> _matrix;
    Node* _root;
    size_t _size;
};

//реализация public//
OptimalTree::OptimalTree(const std::vector<int>& key,const std::vector<float>& p,const std::vector<float>& q)
{
    _size = key.size();
    //создаем матрицу
    setMatrix(key, p, q);
    int rootIndexInKey=0;
    
    //находим индекс корня
    while(1)
    {
        if(key[rootIndexInKey] == _matrix[0][key.size()-1].index)
            break;
        ++rootIndexInKey;
    }
    
    //создаем узел с корнем
    _root = new Node(_matrix[0][key.size()-1].index);
    
    //добавялем рекурсивно все дерево
    addNodes(_root,key,0,rootIndexInKey-1,rootIndexInKey+1,_size-1);
    
}

OptimalTree::~OptimalTree()
{
    if (_root != nullptr)
        remove(_root);
}

std::string OptimalTree::treeToStr()
{
    std::string treeStr;
    nodeToStr(_root, treeStr);
    return treeStr;
}

Node* OptimalTree::searchNode(int key)
{
    return search(_root, key);
}


void OptimalTree::graphVizTraversal(std::string& odtStr)
{
    this->traversal(_root, nullptr, odtStr);
}

//реализация PRIVATE////

void OptimalTree::addNodes(Node* currentNode,const std::vector<int>& key,int leftBegin,int leftEnd,int rightBegin,int rightEnd)
{
    
    if(leftBegin >=0 && leftEnd >= 0 && leftEnd <= _size && leftBegin <= _size && leftBegin <= leftEnd)
    {
        Node* leftNode = new Node(_matrix[leftBegin][leftEnd].index);
        currentNode->leftChild = leftNode;
        int leftNodeIndex = 0;
        while (true)
        {
            if (key[leftNodeIndex] == _matrix[leftBegin][leftEnd].index)
                break;
            ++leftNodeIndex;
        }
        addNodes(leftNode,key,leftBegin, leftNodeIndex - 1, leftNodeIndex + 1, leftEnd);
    }
    
    if (rightBegin >= 0 && rightEnd < _size && rightBegin < _size && rightEnd >= 0 && rightBegin <= rightEnd)
    {
        Node* rightNode = new Node(_matrix[rightBegin][rightEnd].index);
        currentNode->rightChild = rightNode;
        int rightNodeIndex = 0;
        while (true)
        {
            if (key[rightNodeIndex] == _matrix[rightBegin][rightEnd].index)
                break;
            ++rightNodeIndex;
        }
        addNodes(rightNode, key, rightBegin, rightNodeIndex - 1, rightNodeIndex + 1, rightEnd);
    }
    
}





void OptimalTree::setElementIJMatrix(std::vector<std::vector<elementMatrix>>& matrix,int i,int j,const std::vector<float>& p,const std::vector<float>& q)
{
    size_t sizeKey = p.size();
    size_t T = 0, minT = INT_MAX;
    
    //Вычисляем W(i,j)
    int weightLeft = i-1 >= 0 ?  matrix[i-1][j].sumWeightsAllSubtreeNodes:0;
    int sumWeight = weightLeft + matrix[i][i].sumWeightsAllSubtreeNodes;
    matrix[i][j].sumWeightsAllSubtreeNodes = sumWeight;
    
    //Вычисляем T
    for (int currentlyRoot = j; currentlyRoot <= i; ++currentlyRoot)
    {
        T=0;
        T = 0;
        if (currentlyRoot > 0)
            T += matrix[currentlyRoot-1][j].weightedPathLength + matrix[currentlyRoot-1][j].sumWeightsAllSubtreeNodes;
        if (currentlyRoot < sizeKey - 1)
            T += matrix[i][currentlyRoot+1].weightedPathLength + matrix[i][currentlyRoot+1].sumWeightsAllSubtreeNodes;

        if (T < minT)
        {
            matrix[i][j].index = matrix[currentlyRoot][currentlyRoot].index;
            matrix[i][j].weightedPathLength = T;
            minT = T;
        }
    }

}


void OptimalTree::setMatrix(const std::vector<int>& key,const std::vector<float>& p,const std::vector<float>& q)
{
    size_t sizeKey = key.size();
    
    //обьявление матрицы построения оптимального дерева
    std::vector<std::vector<elementMatrix>> matrixNode;
    matrixNode.resize(sizeKey);
    for(size_t i=0;i<sizeKey;++i)
    {
        //обьявляем буфер для инициализации всех ячеек матрицы
        std::vector<elementMatrix> buff;
        
        //переразмериваем столбцы матрицы
        buff.resize(sizeKey);
        
        //инициализируем строки матрицы
        for(size_t j=0;j<sizeKey;++j)
        {
            buff[j]={0,INT_MAX,0};
        }
        matrixNode[i]=buff;
    }
    
    //заполняем главную диагональ
    for (int i = 0; i < sizeKey; ++i)
    {
        for (int j = 0; j < sizeKey; ++j)
        {
            matrixNode[i][j].index = i == j ? key[i] : 0;
            matrixNode[i][j].weightedPathLength = 0;
            matrixNode[i][j].sumWeightsAllSubtreeNodes = i == j ? p[i] + q[i] + q[i+1] : 0;
        }
    }
    
    //заполняем побочные диагонали
    for (int j = 1; j < sizeKey; ++j)
    {
        for (int i = 0; i + j < sizeKey; ++i)
        setElementIJMatrix(matrixNode,i+j,i,p, q);
    }
    
    for(size_t i=0;i<sizeKey;++i)
    {
        for(size_t j=i;j<sizeKey;++j)
        {
            elementMatrix buffer = matrixNode[i][j];
            matrixNode[i][j] = matrixNode[j][i];
            matrixNode[j][i] = buffer;
        }
    }
    _matrix = matrixNode;
}
void OptimalTree::remove(Node*& node)
{
    if (node != nullptr)
    {
        remove(node->leftChild);
        remove(node->rightChild);
        delete node;
    }
}
void OptimalTree::nodeToStr(Node*& node, std::string& treeStr)
{
    if (!node)
        return;

    treeStr += node->data + '0';
    nodeToStr(node->leftChild, treeStr);
    nodeToStr(node->rightChild, treeStr);
}

Node* OptimalTree::search(Node*& node, int key)
{
    if (node == nullptr)
        return node;

    Node* leftIndex = nullptr;
    leftIndex = search(node->leftChild, key);
    if (leftIndex != nullptr)
        return leftIndex;
    
    return node->data == key ? node : search(node->rightChild, key);
}

void OptimalTree::traversal(Node* node, Node* parentNode, std::string& odtStr)
{
    if (!node)
        return;

    if (parentNode != nullptr)
        addDotNode(odtStr, parentNode, node);

    traversal(node->leftChild, node, odtStr);
    traversal(node->rightChild, node, odtStr);
}

void OptimalTree::addDotNode(std::string& dotStr, Node* key, Node* value)
{
    std::ostringstream oss, vss;
    oss << key->data;
    dotStr += oss.str();
    dotStr.append(" -> ");
    vss << value->data;
    dotStr += vss.str();
    dotStr.append(" ;\n");
}
#endif /* OptiomalTree_h */

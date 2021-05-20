#ifndef avlTree_h
#define avlTree_h
#include <sstream>
/*Реализовать обобщённый (шаблонный) класс AVL-дерева (двоичного дерева поиска, сбалансированного по высоте) с конструктором (создающим пустое дерево), деструктором, методами вставки и удаления ключей (с восстановлением сбалансированности), поиска ключей, обхода узлов дерева, вывода в поток в виде строки. При необходимости реализовать и другие методы класса.*/

template <typename T>
struct Node{
    T key;
    unsigned char height;
    Node* leftChild ;
    Node* rightChild;
    Node(T _key)
    {
        key = _key;
        height = 1;
        rightChild=leftChild=nullptr;
    }
};

template <typename T>
class AVLTREE{
public:
    AVLTREE() = default;
    ~AVLTREE()
    {
        Destroy(_root);
    }
    void printTree();
    Node<T>* search(T searchKey);
    void remove(T deleteKey);
    void insert(T newKey);
    void graphVizTraversal(std::string& odtStr);
private:
    void printTreePrivate(Node<T>* node,int l);
    Node<T>* searchPrivate(const Node<T>* node,T searchKey);
    void removePrivate(Node<T>*& node,const T deleteKey);
    void insertPrivate(Node<T>*& node,const T newKey);
    Node<T>* removeMinKey(Node<T>* node);
    Node<T>* findMinKey( Node<T>* node);
    Node<T>* balance(Node<T>* node);
    Node<T>* rotateRight(Node<T>* node);
    Node<T>* rotateLeft(Node<T>* node);
    unsigned char height(const Node<T>* p);
    int balanceFactor(const Node<T>* p);
    void fixHeight( Node<T>* node);
    void Destroy(Node<T>*& node);
    void addDotNode(std::string& dotStr, Node<T>* key, Node<T>* value);
    void traversal(Node<T>* node, Node<T>* parentNode, std::string& odtStr);
private:
    Node<T>* _root = nullptr;
};

template <typename T>
void AVLTREE<T>::printTree()
{
    printTreePrivate(_root,0);
}



//wrap remove
template <typename T>
void AVLTREE<T>::remove(const T deleteKey)
{
     removePrivate(_root, deleteKey);
}

//wrap insert
template <typename T>
void AVLTREE<T>::insert(const T newKey)
{
     insertPrivate(_root, newKey);
}

template <typename T>
void AVLTREE<T>::printTreePrivate(Node<T>* node,int l)
{
    if(node != NULL)
    {
        l +=3;
        printTreePrivate(node->rightChild,l);
        std::cout << std::string(l,' ') << node->key  << std::endl;
        printTreePrivate(node->leftChild,l);
        l -=3;
    }
}

template <typename T>
Node<T>* AVLTREE<T>::search(T searchKey)
{
    Node<T>* currentNode = _root;
    while(currentNode != nullptr)
    {
        if(currentNode->key > searchKey)
        {
            currentNode = currentNode->leftChild;
        }
        else if(currentNode->key < searchKey)
        {
            currentNode = currentNode->rightChild;
        }
        else
        {
            return currentNode;
        }
    }
    return nullptr;
        
}


//remome node with value key is "deletekey"
template <typename T>
void AVLTREE<T>::removePrivate(Node<T>*& node,T deleteKey)
{
    if(!node) return ;
    if(deleteKey < node->key)
         removePrivate(node->leftChild,deleteKey);
    else if(deleteKey > node->key)
         removePrivate(node->rightChild,deleteKey);
    else
    {
        Node<T>* rootLeftSubtree = node->leftChild;
        Node<T>* rootRightSubtree = node->rightChild;
        node->leftChild = nullptr;
        node->rightChild = nullptr;
        node = nullptr;
        if(!rootRightSubtree) return;
        Node<T>* minNodeInRight = findMinKey(rootRightSubtree);
        minNodeInRight->rightChild = removeMinKey(rootRightSubtree);
        minNodeInRight->leftChild = rootLeftSubtree;
        node = balance(minNodeInRight);
    }
     node = balance(node);
}

//insert node in tree with root "node"
template <typename T>
void AVLTREE<T>::insertPrivate(Node<T>*& node,T newKey)
{
    if(!node)
    {
        node =  new Node<T>(newKey);
        return ;
    }
    if(newKey < node->key)
         insertPrivate(node->leftChild,newKey);
    else
        insertPrivate(node->rightChild,newKey);
     node = balance(node);
    
}

//remove node with min value key in subtrees "node"
template <typename T>
Node<T>* AVLTREE<T>::removeMinKey(Node<T>* node)
{
    if(node->leftChild == nullptr)
        return node->rightChild;
    node->leftChild = removeMinKey(node->leftChild);
    return balance(node);
    
}

//find node with min value key
template <typename T>
Node<T>* AVLTREE<T>::findMinKey(Node<T>* node)
{
    return node->leftChild ? findMinKey(node->leftChild):node;
}



//if balance factor |\| > 2
template <typename T>
Node<T>* AVLTREE<T>::balance(Node<T>* node)
{
    fixHeight(node);
    if(balanceFactor(node) == 2)
    {
        if(balanceFactor(node->rightChild) < 0 )
            node->rightChild = rotateRight(node->rightChild);
        return rotateLeft(node);
    }
    if(balanceFactor(node) == -2)
    {
        if(balanceFactor(node->leftChild) > 0)
            node->leftChild = rotateLeft(node->leftChild);
        return rotateRight(node);
    }
    return node;
}

//rotate tree to right if balance factor |\| <= 1
template <typename T>
Node<T>* AVLTREE<T>::rotateRight(Node<T>* node)
{
    Node<T>* leftSubTree = node->leftChild;
    node->leftChild = leftSubTree->rightChild;
    leftSubTree->rightChild = node;
    fixHeight(node);
    fixHeight(leftSubTree);
    return leftSubTree;
}

//rotate tree to left if balance factor |\| <= 1
template <typename T>
Node<T>* AVLTREE<T>::rotateLeft(Node<T>* node)
{
    Node<T>* rightSubTree = node->rightChild;
    node->rightChild = rightSubTree->leftChild;
    rightSubTree->leftChild = node;
    fixHeight(node);
    fixHeight(rightSubTree);
    return rightSubTree;
}

//wrap for calculating height
template <typename T>
unsigned char AVLTREE<T>::height(const Node<T>* node)
{
    return node?node->height:0;
}

//calсulates the height difference of the right and left subtrees
template<typename T>
int AVLTREE<T>::balanceFactor(const Node<T>* node)
{
    return height(node->rightChild)-height(node->leftChild);
}

//restores the value of the node height if the height value of the subrees is correct
template <typename T>
void AVLTREE<T>::fixHeight(Node<T>* node)
{
    unsigned char heightLeft = height(node->leftChild);
    unsigned char heightRight = height(node->rightChild);
    node->height = (heightLeft > heightRight ? heightLeft : heightRight) + 1;
}

//Destreoy
template <typename T>
void AVLTREE<T>::Destroy(Node<T>*& node)
{
    if(node != nullptr)
    {
        Node<T>* left = node->leftChild;
        Node<T>* right = node->rightChild;
        Destroy(left);
        Destroy(right);
        delete node;
        node = nullptr;
    }
}

template <typename T>
void AVLTREE<T>::addDotNode(std::string& dotStr, Node<T>* key, Node<T>* value)
{
    std::ostringstream oss, vss;
    oss << key->key;
    dotStr += oss.str();
    dotStr.append(" -> ");
    vss << value->key;
    dotStr += vss.str();
    dotStr.append(" ;\n");
}

template<typename T>
void AVLTREE<T>::graphVizTraversal(std::string& odtStr)
{
    this->traversal(_root, nullptr, odtStr);
}

template<typename T>
void AVLTREE<T>::traversal(Node<T>* node, Node<T>* parentNode, std::string& odtStr)
{
    if (!node)
        return;

    if (parentNode != nullptr)
        addDotNode(odtStr, parentNode, node);

    traversal(node->leftChild, node, odtStr);
    traversal(node->rightChild, node, odtStr);
}

#endif /* avlTree_h */

//
//  BinaryTree.h
//  BinaryTree
//
//  Created by Pavel on 03.02.2021.
//

#ifndef BinaryTree_h
#define BinaryTree_h

#include <stdio.h>
#include <string>
/*
удаление, ЛПК(для реализовать алгоритм поиска)

 */

//Структура Node,явл узлом дерева с шаблонным значением T
template<typename T>
struct Node
{
    //~Node(){delete _left,delete _right;};
    Node(T data):_data(data){};
    T _data;
    Node* _left = nullptr;
    Node* _right = nullptr;
};

template<typename T>
class BinaryTree
{
    
public:
    BinaryTree(Node<T>* root) : _root(root){} ;
    void add(T data);//добавление элементов
    void remove(T data);//удаление элементов
    Node<T>* search(T data);//поиск элемента
    void inorderTravesal();//Обход в отсортированном порядке
    void postorderTravesal();//ПКЛ
    
private:
    void postorderTravesalPrivate( Node<T>*& root,size_t size);//ПКЛ
    void addPrivate(T data,Node<T>*& root);//приватный метод добавления элемента в дерево
    Node<T>* _root; //указатель на корень дерева
};


template<typename T>
void BinaryTree<T>::add(T data)
{
    addPrivate(data,_root);
}

template<typename T>
void BinaryTree<T>::addPrivate(T data,Node<T>*& root)
{
    if(root ==nullptr)
    {
        root = new Node<T>(data);
        return;
    }
    Node<T>*& currentNode = root->_data > data ? root->_left : root->_right;
    addPrivate(data,currentNode);
}

template<typename T>
void BinaryTree<T>::postorderTravesal()
{
    postorderTravesalPrivate(_root,0);
}
template<typename T>
void BinaryTree<T>::postorderTravesalPrivate( Node<T>*& root,size_t size)
{
    if(root != NULL)
    {
        size +=3;
        postorderTravesalPrivate(root->_right,size);
        std::cout << std::string(size,' ') << root->_data  << std::endl;
        postorderTravesalPrivate(root->_left,size);
        size -=3;
    }
}

template<typename T>
Node<T>* BinaryTree<T>::search(T data)
{
    Node<T>* currentNode = _root;
    while(currentNode != nullptr)
    {
        if(currentNode->_data > data)
        {
            currentNode = currentNode->_left;
        }
        else if(currentNode->_data < data)
        {
            currentNode = currentNode->_right;
        }
        else
        {
            return currentNode;
        }
    }
    return NULL;
}


template<typename T>
void BinaryTree<T>::remove(T data)
{
    //
    Node<T>* currentNode = _root;
    Node<T>* parentNode;
    while(currentNode != nullptr)
    {
        
        
        if(currentNode->_data > data)
        {
            parentNode = currentNode;
            currentNode = currentNode->_left;
        }
        else if(currentNode->_data < data)
        {
            parentNode = currentNode;
            currentNode = currentNode->_right;
        }
        else
        {
            break;
        }
    }
    if(currentNode->_data != data)
    {
        return;
    }
    //
    
    if(currentNode != NULL)
    {
        //Если  не имеет  потомков
       if(currentNode->_left == NULL && currentNode->_right == NULL)
       {
           parentNode = parentNode->_data > data ? parentNode->_left = nullptr : parentNode->_right = nullptr;
           
       }
        //Если имеет одного потомка
       else if(currentNode->_left == NULL || currentNode->_right == NULL)
       {
           //Если левого
           if(currentNode->_left != NULL)
           {
               parentNode = parentNode->_data > data ? parentNode->_left = currentNode->_left : parentNode->_right = currentNode->_left;
           }
           //Если правого
           else if(currentNode->_right != NULL)
           {
               parentNode = parentNode->_data > data ? parentNode->_left = currentNode->_right : parentNode->_right = currentNode->_right;
           }
            
       }
        //Если имеет нескольких потомков
       else
       {
           //Ищем элемент со следующим номером,для этого делаем один шаг право,потом все влево
           Node<T>* nextNode = currentNode->_right;
           while(nextNode->_left != nullptr)
           {
               nextNode = nextNode->_left;
           }
          
          //рекурсивно удаляем следующий элемент из дерева
           remove(nextNode->_data);
           
           //меняем у предка удаляемого элемента ссылку на следующий элемент
           parentNode = parentNode->_data > data ? parentNode->_left = nextNode : parentNode->_right = nextNode;
           
           //меняем ссылку у нового элемента,которые стоит ан месте удаленного
           nextNode->_right = currentNode->_right;
           nextNode->_left = currentNode->_left;
           
         }
    }
    return;
}
#endif /* BinaryTree_h */

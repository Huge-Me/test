#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;
template<class T>
struct Node
{
    T Data;
    Node<T> *left,*right;
};
template<class T>
class BST
{
private:
    Node<T> *root;
    int size;
    void add1(Node<T>* bt,T e);
public:
    BST();
    ~BST(){};
    bool IsEmpty();
    void add(T e);
};
template<class T>
BST<T>::BST()
{
    root = nullptr;
    size = 0;
}
template<class T>
bool BST<T>::IsEmpty(){
    return size == 0;
}
template<class T>
void BST<T>::add(T e){
    if(root == nullptr){
        root = new Node<T>;
        root->Data = e;
        size++;
    }
    else{
        add1(root,e);
    }
}
template<class T>
void BST<T>::add1(Node<T>* bt,T e){
    if(e == bt->Data){
        return;
    }
    else if(e < bt->Data && bt->left == nullptr){
        bt->left = new Node<T>;
        bt->left->Data = e;
        size++;
        return;
    }
    else if(e > bt->Data &&  bt->right == nullptr){
        bt->right = new Node<T>;
        bt->right->Data = e;
        size++;
        return;
    }
    if( e < bt->Data){
        add1(bt->left,e);
    }
    else if(e > bt->Data){
        add1(bt->right,e);
    }
}
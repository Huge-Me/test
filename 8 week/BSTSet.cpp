#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;
template<class T>
struct BNode
{
    T Data;
    BNode<T> *left,*right;
};
template<class T>
class BST
{
private:
    BNode<T> *root;
    int size;
    BNode<T>* add1(BNode<T>* bt,T e);
    bool contains1(BNode<T>* bt,T e);
    void preOrder(BNode<T>* bt);
    void inOrder(BNode<T>* bt);
    void postOrder(BNode<T>* bt); 
    BNode<T>*  minimum(BNode<T>* bt);
    BNode<T>* maxmum(BNode<T>* bt);
    BNode<T>* removeMin(BNode<T>* bt);
    BNode<T>* removeMax(BNode<T>* bt);
    BNode<T>* remove(BNode<T>* bt,T e);
public:
    BST();
    ~BST(){};
    void IsEmpty();
    void add(T e);  //添加元素
    bool contains(T e);   //查询元素
    void preOrder(); // 前序递归遍历
    void inOrder(); // 中序递归遍历
    void postOrder(); // 后序递归遍历
    void preOrderNR();// 前序非递归遍历
    void levelOrder();// 层序遍历
    T minimum();//寻找最小值
    T maxmum();//寻找最大值
    T removeMin();//删除最小值
    T removeMax();//删除最大值
    void remove(T e);//删除指定元素
};
template<class T>
BST<T>::BST()
{
    root = nullptr;
    size = 0;
}
template<class T>
void BST<T>::IsEmpty(){
    if(size == 0){
        cout<<"It is Empty."<<endl;
    }
    else
        cout<<"It Is Not Empty."<<endl;
}

//添加元素
template<class T>
void BST<T>::add(T e){
    root = add1(root,e);
}
template<class T>
BNode<T>* BST<T>::add1(BNode<T>* bt,T e){
    if(bt == nullptr){
        size++;
        bt = new BNode<T>;
        bt->Data = e;
        bt->left = nullptr;
        bt->right = nullptr;
        return bt;
    }
    if( e < bt->Data){
        bt->left = add1(bt->left,e);
    }
    else if(e > bt->Data){
        bt->right = add1(bt->right,e);
    }
    return bt;
}

//查询元素
template<class T>
bool BST<T>::contains(T e){
    return contains1(root,e);
}
template<class T>
bool BST<T>::contains1(BNode<T>*bt,T e){
    if(bt == nullptr){
        return false;
    }
    if(e == bt->Data){
        return true;
    }
    else if(e < bt->Data){
        return contains1(bt->left,e);
    }
    else //e > bt->data
        return contains1(bt->right,e);
}

// 前序递归遍历
template<class T>
void BST<T>::preOrder(){
    preOrder(root);
}
template<class T>
void BST<T>::preOrder(BNode<T>* bt){
    if(bt == nullptr){
        return;
    }

    cout<<bt->Data<<endl;;
    preOrder(bt->left);
    preOrder(bt->right);
}

// 中序递归遍历
template<class T>
void BST<T>::inOrder(){
    inOrder(root);
}
template<class T>
void BST<T>::inOrder(BNode<T>* bt){
    if(bt == nullptr){
        return;
    }

    inOrder(bt->left);
    cout<<bt->Data<<endl;
    inOrder(bt->right);
}

// 后序递归遍历
template<class T>
void BST<T>::postOrder(){
    postOrder(root);
}
template<class T>
void BST<T>::postOrder(BNode<T>* bt){
    if(bt == nullptr){
        return;
    }

    postOrder(bt->left);
    postOrder(bt->right);
    cout<<bt->Data<<endl;
}

// 前序非递归遍历
template<class T>
void BST<T>::preOrderNR(){
    int top = -1;
    BNode<T>* s[100];
    BNode<T>* bt = root;
    while (bt != nullptr || top != -1)
    {
        while (bt != nullptr)
        {
            cout << bt->Data<<endl;
            s[++top] = bt;
            bt = bt->left;
        }
        if (top != -1)
        {
            bt = s[top--];
            bt = bt->right;
        }
    }
    
}

// 层序遍历
template<class T>
void BST<T>::levelOrder(){
    BNode<T>* Q[10], * q = nullptr;
    int front = -1,rear = -1;
    if (root == nullptr) return;
    Q[++rear] = root;
    while (front != rear) {
        q = Q[++front];
        cout << q->Data<<endl;
        if (q->left != NULL) Q[++rear] = q->left;
        if (q->right != NULL) Q[++rear] = q->right;
    }
}

//寻找最小值
template<class T>
T BST<T>::minimum() {
    if (size == 0) {
        return 0;
    }
    BNode<T>* mini = minimum(root);
    return mini->Data;
}
template<class T>
BNode<T>* BST<T>::minimum(BNode<T>* bt) {
    while (bt->left != nullptr) {
        bt = bt->left;
    }
    return bt;
}

//寻找最大值
template<class T>
T BST<T>::maxmum() {
    if (size == 0) {
        return 0;
    }
    BNode<T>* max = maxmum(root);
    return max->Data;
}
template<class T>
BNode<T>* BST<T>::maxmum(BNode<T>* bt) {
    while (bt->right != nullptr) {
        bt = bt->right;
    }
    return bt;
}

//删除最小值
template<class T>
T BST<T>::removeMin(){
    T res = minimum();
    root = removeMin(root);
    return res;
}
template<class T>
BNode<T>* BST<T>::removeMin(BNode<T>* bt){
    if(bt->left == nullptr){
        BNode<T>* rbt = new BNode<T>;
        rbt = bt->right;
        bt->right = nullptr;
        size--;
        return rbt;
    }
    bt->left = removeMin(bt->left);
    return bt;
}

//寻找最大值
template<class T>
T BST<T>::removeMax(){
    T res = maxmum();
    root = removeMax(root);
    return res;
}
template<class T>
BNode<T>* BST<T>::removeMax(BNode<T>* bt){
    if(bt->right == nullptr){
        BNode<T>* lbt = new BNode<T>;
        lbt = bt->left;
        bt->left = nullptr;
        size--;
        return lbt;
    }
    bt->right = removeMax(bt->right);
    return bt;
}

//删除指定元素
template<class T>
void BST<T>::remove(T e){
    root = remove(root,e);
}
template<class T>
BNode<T>* BST<T>::remove(BNode<T>* bt,T e){
    if(bt == nullptr){
        return bt;
    }
    if(e < bt->Data){
        bt->left = remove(bt->left,e);
        return bt;
    }
    else if(e > bt->Data){
        bt->right = remove(bt->right,e);
    }
    else{ // e = bt->Data
        //左子树为空
        if(bt->left == nullptr){
            BNode<T>* rbt = new BNode<T>;
            rbt = bt->right;
            bt->right = nullptr;
            size--;
            return rbt;
        }
        //右子树为空
        if(bt->right == nullptr){
            BNode<T>* lbt = new BNode<T>;
            lbt = bt->left;
            bt->left = nullptr;
            size--;
            return lbt;
        }
        //左右均不为空
        BNode<T>* successor = minimum(bt->right);
        successor->right = removeMin(bt->right);
        successor->left = bt->left;
        bt->left = bt->right =nullptr;
        delete bt;
        return successor;
    }
}
template<class T>
class BSTSet
{
private:
    BST<T> bst;
public:
    BSTSet();
    ~BSTSet(){};
    int GetSize();
    void isEmpty();
    void add(T t);
    bool contains(T t);
    void remove(T t);
};
template<class T>
BSTSet<T>::BSTSet(){
    bst = {};
}
template<class T>
int BSTSet<T>::GetSize(){
    return bst.size;
}
template<class T>
void BSTSet<T>::isEmpty(){
    bst.IsEmpty();
}
template<class T>
void BSTSet<T>::add(T t){
    bst.add(t);
}
template<class T>
bool BSTSet<T>::contains(T t){
    return bst.contains(t);
}
template<class T>
void BSTSet<T>::remove(T t){
    bst.remove(t);
}
int main() {
    BSTSet<int>bs1 = {};
    bs1.isEmpty();
    int num[6] = { 5,3,6,8,4,2 };
    for (int i = 0; i < 6; i++) {
        bs1.add(num[i]);
    }
    bs1.isEmpty();
    cout << bs1.GetSize()<< endl;
    bs1.remove(5);
    cout << bs1.GetSize() << endl;
    bs1.add(10);
    cout << bs1.GetSize() << endl;
    cout << bs1.contains(10) << endl;
}

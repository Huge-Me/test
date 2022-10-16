#include<iostream>
using namespace std;
template<class T>
class SegmentTree
{
private:
    T *tree;
    T *data;
    int data_Length;
    int tree_Length;
    int leftchild(int index){
        return 2 * index + 1;
    }
    int rightchild(int index){
        return 2 * index + 2;
    }
    //在treeindex的位置创建表示区间[l,r]的线段树
    void buildSegmentTree(int treeindex,int l,int r){
        if(l == r){
            treeindex = data[l];
        }
        int leftTreeIndex = leftchild(treeindex);
        int rightTreeIndex = rightchild(treeindex);
        int mid = l + (r - l) / 2;
        buildSegmentTree(leftTreeIndex,l,mid);
        buildSegmentTree(rightTreeIndex,mid + 1,r);
        //定义线段树功能
        tree[treeindex] = tree[leftTreeIndex] + tree[rightTreeIndex];
    }
public:
    SegmentTree(T A[],int A_Length);
    ~SegmentTree();
    int GetSize();
    T Get(int index);
    void PrintTree();
};
template<class T>
SegmentTree<T>::SegmentTree(T A[],int A_Length)
{
    data = new T[A_Length];
    for(int i = 0;i < A_Length; i ++){
        data[i] = A[i];
    }
    data_Length = A_Length;
    tree_Length = 4 * A_Length;
    tree = new T[tree_Length];
    buildSegmentTree(0,0,data_Length - 1);
}
template<class T>
int SegmentTree<T>::GetSize(){
    return data_Length;
}
template<class T>
T SegmentTree<T>::Get(int index){
    if(index < 0 || index >= data_Length){
        cout << "Index is illegal !" <<endl;
        return 0;
    }
    return data[index];
}
template<class T>
void SegmentTree<T>::PrintTree(){
    cout << "[" ;
    for(int i = 0;i < tree_Length;i ++){
        

        cout << tree[i];

        if(i != tree_Length - 1){
            cout << ",";
        }
    }
    cout << "]" ;
}
int main(){
    int A[5] = {2,4,6,8,20};
    SegmentTree<int> segTree (A,5);
    segTree.PrintTree();
    return 0;
}
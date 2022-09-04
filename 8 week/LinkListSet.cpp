#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;
template<class T>
struct Node {
	T Data;
	Node<T>* Next;
};
template<class T>
class LinkList {               //单链表声明
public:
	LinkList() {             //无参构造函数
		First = new Node<T>;
		First->Next = nullptr;
	}
	LinkList(T A[], int N) {         //含参构造函数
		First = new Node<T>;
		Node<T>* r = First, * s = nullptr;
		for (int i = 0; i < N; i++) {
			s = new Node<T>;
			s->Data = A[i];
			r->Next = s;
			r = s;
		}
		r->Next = nullptr;
	}
	~LinkList() {                 //析构函数
		Node<T>* p = First;
		while (First != nullptr) {
			First = First->Next;
			delete p;
			p = First;
		}
	}
	int GetLength() {               //求链表长度
		int count = 0;
		Node<T>* p = First->Next;
		while (p != nullptr) {
			p = p->Next;
			count++;
		}
		return count;
	}
	T Get(int i) {                   //按位查找
		Node<T>* p = First->Next;
		T X;
		int n = 1;
		while (p != nullptr && n < i) {
			p = p->Next;
			n++;
		}
		if (p == nullptr) {
			return 0;
		}
		else {
			X = p->Data;
			return X;
		}
	}
	bool Locate(T X) {                  //包含元素
		Node<T>* p = First->Next;
		int n = 1;
		while (p != nullptr) {
			if (p->Data == X) {
				return true;
			}
			else {
				p = p->Next;
				n++;
			}
		}
		return false;
	}
    int Location(T X) {                  //按值查找
        Node<T>* p = First->Next;
        int n = 1;
        while (p != nullptr) {
            if (p->Data == X) {
                return n;
            }
            else {
                p = p->Next;
                n++;
            }
        }
        return 0;
    }
	void Insert(int i, T X) {               //插入元素
		Node<T>* p = First, * s = nullptr;
		int n = 0;
		while (p != nullptr && n < i - 1) {
			p = p->Next;
			n++;
		}
		if (p == nullptr)
			cout << "Insert Failde" << endl;
		else {
			s = new Node<T>;
			s->Data = X;
			s->Next = p->Next;
			p->Next = s;
		}
	}
	T Delete(int i) {                   //删除元素
		T X;
		Node<T>* p = First;
		Node<T>* q = nullptr;
		int n = 0;
		while (p != nullptr && n < i - 1) {
			p = p->Next;
			n++;
		}
		if (p == nullptr || p->Next == nullptr) {

			return 0;
		}
		else {
			q = p->Next;
			X = q->Data;
			p->Next = q->Next;
			delete q;
			return X;
		}
	}
	void PrintList() {             //打印链表
		Node<T>* p = First->Next;
		while (p != nullptr) {
			cout << p->Data << endl;
			p = p->Next;
		}
		cout << endl;
	}
	void Revise(int i, T X) {            //  修改
		Node<T>* p = First;
		int n = 0;
		while (p != nullptr && n < i ) {
			p = p->Next;
			n++;
		}
		if (p == nullptr) {
			cout << "Revise Failed" << endl;
		}
		else {
			p->Data = X;
		}
	}
    bool isEmpty(){
        if(First->Next == nullptr){
            return true;
        }
        else
            return false;
    }
private:
	Node<T>* First;
};
template<class T>
class LinkListSet{
private:
    LinkList<T> list;
public:
    LinkListSet();
    ~LinkListSet(){};
    int GetSize();
    bool isEmpty();
    void add(T t);
    bool contains(T t);
    void remove(T t);
};
template<class T>
LinkListSet<T>::LinkListSet(){
    list = {};
}
template<class T>
int LinkListSet<T>::GetSize(){
    return list.GetLength();
}
template<class T>
bool LinkListSet<T>::isEmpty(){
    return list.isEmpty();
}
template<class T>
void LinkListSet<T>::add(T t){
    if(!list.Locate(t)){
        list.Insert(1,t);
    }
    else
        return;
}
template<class T>
bool LinkListSet<T>::contains(T t){
    return list.Locate(t);
}
template<class T>
void LinkListSet<T>::remove(T t){
    int i = list.Location(t);
    list.Delete(i);
}
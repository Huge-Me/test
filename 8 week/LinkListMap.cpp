#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;
template <class K, class V>
class MapNode{
public:
	MapNode(K key = NULL, V value = NULL, MapNode<K, V> *next = NULL){
		m_key = key;
		m_value = value;
		this->next = next;
	}
public:
	K m_key;
	V m_value;
	MapNode<K, V> *next;
};
template <class K, class V>
class Map{
public:
	virtual int size() = 0;
	virtual bool isEmpty() = 0;
	//增加操作
	virtual void add(K key, V value) = 0;
	//删除操作
	virtual V remove(K key) = 0;
	//修改操作
	virtual void set(K key, V value) = 0;
	//查找操作
	virtual bool contains(K key) = 0;
	virtual V get(K key) = 0;
};
template <class K, class V>
class LinkedListMap : public Map<K, V>{
public:
	LinkedListMap(){
		head.m_key = NULL;
		head.m_value = NULL;
		head.next = NULL;
		m_size = 0;
	}
	...
private:
	MapNode<K, V> head;
	int m_size;
};
template <class K, class V>
class LinkedListMap : public Map<K, V>{
public:
	//增加操作
	void add(K key, V value){
		if (!contains(key)){
			MapNode<K, V> *p = new MapNode<K, V>(key, value, head.next);
			head.next = p;
			m_size++;
		}
	}
};
template <class K, class V>
class LinkedListMap : public Map<K, V>{
public:

	//删除操作
	V remove(K key){
		MapNode<K, V> *pre = &head;
		MapNode<K, V> *node = pre->next;
		while (node){
			if (key == node->m_key){
				pre->next = node->next;
				V res = node->m_value;
				delete node;
				m_size--;
				return res;
			}
			pre = node;
			node = node->next;
		}
		cout << "映射中不包含" << key << '!' << endl;
		return NULL;
	}
};
template <class K, class V>
class LinkedListMap : public Map<K, V>{
public:
	//修改操作
	void set(K key, V value){
		MapNode<K, V> *node = head.next;
		while (node){
			if (key == node->m_key){
				node->m_value = value;
				return;
			}
			node = node->next;
		}
		cout << "映射中不包含" << key << '!' << endl;
	}
};
template <class K, class V>
class LinkedListMap : public Map<K, V>{
public:
	//查找操作
	bool contains(K key){
		MapNode<K, V> *node = head.next;
		while (node){
			if (key == node->m_key){
				return true;
			}
			node = node->next;
		}
		return false;
	}
	V get(K key){
		MapNode<K, V> *node = head.next;
		while (node){
			if (key == node->m_key){
				return node->m_value;
			}
			node = node->next;
		}
		cout << "映射中不包含" << key << '!' << endl;
		return NULL;
	}
};
template <class K, class V>
class LinkedListMap : public Map<K, V>{
public:
	int size(){
		return m_size;
	}
	bool isEmpty(){
		return m_size == 0;
	}
};


#include<iostream>
#include<vector>
#include<cmath>
#include<string>
#include<map>
#include<cstdlib>
#include<ctime>
#include<unordered_set>
using namespace std;
template<class T>
class Array{
private:
    T data[];
    int size;
public:
    Array(int capacity){
        T * data = new T[capacity];
        size = 0;
    }
    Array(){
        int capacity = 100;
        T * data = new T[100];
        size = 0;
    }
    int GetSize(){
        return size;
    }
    int GetCapacity(){
        return (sizeof(data) / sizeof(data[0]));
    }
    bool IsEmpty(){
        return size == 0;
    }
    void addLast(T t){
        if(size == GetCapacity){
            cout << "Error!!" <<endl;
            return; 
        }
        data[size] = t;
        size ++;
    }
};
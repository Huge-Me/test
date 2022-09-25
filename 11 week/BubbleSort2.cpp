#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
template <class T>
void Swap(T a[],T A,T B){
    T t = a[A];
    a[A] = a[B];
    a[B] = t;
}
template <class T>
void BubbleSort2(T A[],int A_Length){
    for(int i = 0;i + 1 < A_Length; i++){
        bool isSwapped = false;
        for(int j = 0;j + 1 <= A_Length - i - 1; j++){
            if(A[j] > A[j + 1]){
                Swap(A,j,j + 1);
                isSwapped = true;
            }
        }
        if(!isSwapped)
            break;
    }
}
int main(){
    int a[6] = {45,64,23,75,12,74,};
    BubbleSort2(a,6);
    for(int i = 0; i < 6; i++){
        cout << a[i] << endl;
    }
    return 0;
}
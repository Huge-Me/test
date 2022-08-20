#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std; 
template<class T>
int Lower(T A[],int A_Length,T target){
    int l = -1;
    int r = A_Length - 1;
    while(l < r){
        int mid = l + (r - l + 1) / 2;
        if(A[mid] < target){
            l = mid;
        }
        else
            r = mid - 1;
    }
    return l;
}
int main(){

    int C[6] = {1,1,3,3,5,5};
    for(int i = 0;i <= 6;i++){
        int k = Lower(C,6,i);
        cout<<k<<" ";
    }
    return 0;
}
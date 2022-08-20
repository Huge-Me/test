#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std; 
template<class T>
int Upper(T A[],int A_Length,T target){
    int l = 0;
    int r = A_Length;
    while(l < r){
        int mid = l + (r - l) / 2;
        if(A[mid] <= target){
            l = mid + 1;
        }
        else
            r = mid;
    }
    return l;
}
int main(){

    int C[6] = {1,1,3,3,5,5};
    for(int i = 0;i <= 6;i++){
        int k = Upper(C,6,i);
        cout<<k<<" ";
    }
    return 0;
}
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
template<class T>
int Lower_Ceil(T A[],int A_Length,T target){
    int c = Upper(A,A_Length,target);
    if(c - 1 > 0 && A[c - 1] == target){
        int i = c - 1;
        while(i >= 0){
            if(A[i] == target){
                i--;
            }
            else{
                break;
            }
        }
        return i + 1;
    }
    return c;
}
int main(){

    int C[6] = {1,1,3,3,5,5};
    for(int i = 0;i <= 6;i++){
        int k = Lower_Ceil(C,6,i);
        cout<<k<<" ";
    }
    cout<<endl;
    int D[8] = {1,1,3,3,3,3,5,5};
    for(int i = 0;i <= 8;i++){
        int k = Lower_Ceil(D,8,i);
        cout<<k<<" ";
    }
    return 0;

}
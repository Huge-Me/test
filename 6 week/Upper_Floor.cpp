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
template<class T>
int Upper_Floor(T A[],int A_Length,T target){
    int c = Lower(A,A_Length,target);
    if(c + 1 <A_Length - 1 && A[c + 1] == target){
        int i = c + 1;
        while(i <= A_Length - 1){
            if(A[i] == target){
                i++;
            }
            else{
                break;
            }
        }
        return i - 1;
    }
    return c;
}
int main(){

    int C[6] = {1,1,3,3,5,5};
    for(int i = 0;i <= 6;i++){
        int k = Upper_Floor(C,6,i);
        cout<<k<<" ";
    }
    cout<<endl;
    int D[8] = {1,1,3,3,3,3,5,5};
    for(int i = 0;i <= 8;i++){
        int k = Upper_Floor(D,8,i);
        cout<<k<<" ";
    }
    return 0;

}
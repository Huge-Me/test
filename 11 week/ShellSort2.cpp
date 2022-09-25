#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
template<class T>
void ShellSort(T A[],int A_Length){
    int h = A_Length / 2;
    while (h >= 1)
    {
        for(int i = h; i < A_Length; i ++){
            T t = A[i];
            int j;
            for(j = i; j - h >= 0 && t < A[j - h]; j -= h){
                A[j] = A[j - h];
            }
            A[j] = t;
        }
        h /= 2;
    }
    
}
int main(){
    int a[6] = {45,64,23,75,12,74,};
    ShellSort(a,6);
    for(int i = 0; i < 6; i++){
        cout << a[i] << endl;
    }
    return 0;
}
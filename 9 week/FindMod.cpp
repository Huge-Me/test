/* 在一个由元素组成的表中 出现次数最多的元素称为众数。试写一个寻找众数的 
算法，并分析其计算复杂性。 */
#include<iostream>
using namespace std;
void FindMod(int A[],int A_Length){
    //假设元素为int型且元素在0~99
    int temp[100] = {0};
    for(int i = 0; i < A_Length; i ++){
        temp[A[i]] ++;
    }
    int Mod = 0;
    int Number = 0;
    for(int i = 0; i < 100; i ++){
        if(temp[i] > Number){
            Number = temp[i];
            Mod = i;
        }
    }
    cout << "The Mod Is: " << Mod <<endl;
    cout << "The Number Is: " << Number <<endl;
}
int main(){
    int a[20] = {28,26,10,54,34,12,64,75,28,28,26,10,10,28,53,23,75,29,60,29};
    FindMod(a,20);
    int b[5] = {2,2,2,3,3};
    FindMod(b,5);
    return 0;
}
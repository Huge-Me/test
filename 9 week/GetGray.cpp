/* 2-34Gray码是一个长度为2"的序列序列中无相同元素，
每个元素都是长度为n位的串，相邻元素恰好只有一位不同。用分治策略设计一个算法对任意的n构造相应的Gray码 */
#include<iostream>
#include<cmath>
using namespace std;
//n <= 10
int A[1024][1024] = {};
void Gray(int n){
    int m = pow(2,n);
    if(n == 1){
        A[0][0] = 0;
        A[1][0] = 1;
        return;
    }
    for(int i = 0; i < m / 2; i ++){
        A[i][n - 1] = 0;
        A[m - 1 - i][n - 1] = 1;
    }
    Gray(n - 1);
    for(int i = m / 2; i < m; i ++){
        for(int j = 0; j < n -  1; j ++){
            A[i][j] = A[m - 1 - i][j];
        }
    }
}
void GetGray(int n){
    int m = pow(2,n);
    Gray(n);
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j ++){
            cout << A[i][j] << "  " ;
        }
        cout << endl;
    }
}
int main(){
    GetGray(4);
    int n;
    cin >> n;
    GetGray(n);
    return 0;
}
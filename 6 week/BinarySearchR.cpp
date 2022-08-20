#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;
template<class T>
int GetLength(T& a) {                 /*数组长度*/
	return (sizeof(a) / sizeof(a[0]));
}  
template<class T>
void PrintArray(T A[], int N) {            /*打印数组*/
	for (int i = 0; i < N; i++) {
		cout << A[i] << endl;
	}
}
void Random(int A[], int A_Length, int Left, int Right) {             /*生成随机数字数组*/
	srand(time(0));
	for (int i = 0; i < A_Length; i++) {
		A[i] = rand() % (Right - Left + 1) + Left;
	}
}
template<class T>
void Swap(T A[], int i, int j) {     //交换数组元素
	T t;
	t = A[j];
	A[j] = A[i];
	A[i] = t;
}
template<class T>
void QSort3(T A[], int l, int r) {
	if (l >= r)
		return;
	int p = rand() % (r - l + 1) + l;
	Swap(A, l, p);
	//A[L+1,lt]<v,A[lt+1,i-1]==v,A[gt,R]>v
	int lt = l, i = l + 1, gt = r + 1;
	while (i < gt) {
		if (A[i] < A[l]) {
			lt++;
			Swap(A, i, lt);
			i++;
		}
		else if (A[i] > A[l]) {
			gt--;
			Swap(A, gt, i);
		}
		else {
			i++;
		}
	}
	Swap(A, l, lt);
	//A[L,lt-1]<v,A[lt,gt-1]==v,A[gt,R]>v
	QSort3(A, l, lt - 1);
	QSort3(A, gt, r);
}
template<class T>
void QuickSort3(T A[], int Length) {
	QSort3(A, 0, Length - 1);
}
template<class T>
int BSearchR(T A[],int l,int r,T target){
    if(l>r) return -1;
    int mid = l + (r - l) / 2;
    if(A[mid] < target){
        return BSearchR(A,mid+1,r,target);
    }
    if(A[mid] == target){
        return mid;
    }
    else{
        return BSearchR(A,l,mid-1,target);
    }
}
template<class T>
int BinarySearchR(T A[],int A_Length,T target){
    return BSearchR(A,0,A_Length-1,target);
}
int main(){
    int A[10];
    int A_Length = GetLength(A);
    Random(A,A_Length,10,99);
    QuickSort3(A,A_Length);
    cout<<"The Array:"<<endl;
    PrintArray(A,A_Length);
    cout<<"The Data U Want:";
    int k;
    cin>>k;
    int n = BinarySearchR(A,A_Length,k);
    cout<<"The Data "<< k <<" Is "<< n <<endl;
    int B[5]={-1,2,5,8,9};
    int n1 = BinarySearchR(B,5,-1);
    cout<<n1<<endl;
    return 0;

}
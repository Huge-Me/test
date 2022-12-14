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
int Partition(T A[], int L, int R) {
	int p = rand() % (R - L + 1) + L;
	T t1 = A[p];
	A[p] = A[L];
	A[L] = t1;
	int j = L;
	for (int i = L + 1; i <= R; i++) {
		if (A[i] < A[L]) {
			j++;
			T t = A[i];
			A[i] = A[j];
			A[j] = t;
		}
	}
	T t = A[j];
	A[j] = A[L];
	A[L] = t;
	return j;
}
template<class T>
void QSort(T A[], int l, int r) {
	if (l >= r)
		return;
	int p = Partition(A, l, r);
	QSort(A, l, p - 1);
	QSort(A, p + 1, r);
}
template<class T>
void QuickSort(T A[],int Length) {
	QSort(A, 0, Length - 1);
}
int main() {      //快速排序
	int A[10];
	int A_Length = GetLength(A);
	Random(A, A_Length, 10, 99);
	cout << "At The First:" << endl;
	PrintArray(A, A_Length);
	QuickSort(A,A_Length);
	cout << "After QuickSort:" << endl;
	PrintArray(A, A_Length);
	return 0;
}
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
int Partition2(T A[], int L, int R) {
	int p = rand() % (R - L + 1) + L;
	Swap(A, L, p);
	int i = L + 1;
	int j = R;
	while (true) {
		while (i <= j && A[i] >= A[L]) {
			i++;
		}
		while (j >= i && A[j] <= A[L]) {
			j--;
		}
		if (i >= j) break;
		Swap(A, i, j);
		i++;
		j--;
	}
	Swap(A, j, L);
	return j;
}
template<class T>
void QSort2(T A[], int l, int r) {
	if (l >= r)
		return;
	int p = Partition2(A, l, r);
	QSort2(A, l, p - 1);
	QSort2(A, p + 1, r);
}
template<class T>
void QuickSort2(T A[], int Length) {
	QSort2(A, 0, Length - 1);
}
int main() {      //快速排序
	int A[10];
	int A_Length = GetLength(A);
	Random(A, A_Length, 10, 99);
	cout << "At The First:" << endl;
	PrintArray(A, A_Length);
	QuickSort2(A,A_Length);
	cout << "After QuickSort:" << endl;
	PrintArray(A, A_Length);
	return 0;
}
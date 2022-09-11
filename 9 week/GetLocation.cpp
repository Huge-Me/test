

/*
	某石油公司计划建造一条由东向西的主输油管道。该管道要穿过一个有n门油并的油田。
	从每口油并都要有一条输油管道沿最短路经(或南或北)与主管道相连。
	如果给定n口油并的位置,即它们的x坐标和坐全标,应如何确定主管道的最优位置，
	即使各油井到主管道之间的输油管道长度总和最小的位置?证明可在线性时间内确定主管道的最优位置。
*/
#include<iostream>
#include<math.h>
using namespace std;
template<class T>
void Swap(T x,T y){
    T t = x;
    x = y;
    y = t;
}
template<class T>
void QSort3(T A[], int l, int r) {//快速排序实现
	if (l >= r)
		return;
	int p = rand() % (r - l + 1) + l;
	Swap(A[l],A[p]);
	//A[L+1,lt]<v,A[lt+1,i-1]==v,A[gt,R]>v
	int lt = l, i = l + 1, gt = r + 1;
	while (i < gt) {
		if (A[i] < A[l]) {
			lt++;
			Swap(A[i],A[lt]);
			i++;
		}
		else if (A[i] > A[l]) {
			gt--;
			Swap(A[i],A[gt]);
		}
		else {
			i++;
		}
	}
	Swap(A[i],A[lt]);
	//A[L,lt-1]<v,A[lt,gt-1]==v,A[gt,R]>v
	QSort3(A, l, lt - 1);
	QSort3(A, gt, r);
}
template<class T>
void QuickSort3(T A[], int Length) {//快速排序
	QSort3(A, 0, Length - 1);
}
void GetLocation(int n,int A[]){
    QuickSort3(A,n);
    int Location;
	//求中位数
    if(n % 2 == 0){
        Location = (A[n / 2] + A[n / 2 - 1]) / 2;
    }
    else{
        Location = A[n / 2];
    }
    cout << "The Location Is: " << Location <<endl;
    int s = 0;
	//求最小长度
    for(int i = 0;i < n;i ++){
        s += abs(Location - A[i]);
    }
    cout << "The Least Length Is: " << s <<endl;
}
int main(){
    int A[10] = {-5,-4,-3,-2,-1,1,2,3,4,5};
    GetLocation(10,A);
	int B[5] = {2,4,6,8,10};
	GetLocation(5,B);
    return 0;
}
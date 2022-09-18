#include<iostream>
using namespace std;
template <class T>
class MaxHeap
{
public:
	MaxHeap(int mx = 10); //默认堆的最大值为10
	virtual ~MaxHeap();

	bool IsEmpty(); //判断堆是否为空
	void Push(const T& e); //向堆中插入数据
	void Pop();           // 删除堆顶
	const T& Top() const;  //读取堆顶的值

private:
	T* heapArray;
	int maxSize; //堆的最大值
	int currentSize; //堆的当前大小
	void trickleUp(int index); //向上渗透
	void trickleDown(int index); //向下渗透
};

template<class T>
MaxHeap<T>::MaxHeap(int mx )
{
	if (mx < 1) throw"max size must be >=1";
	maxSize = mx;
	currentSize = 0;
	heapArray = new T[maxSize];
}

template<class T>
MaxHeap<T>::~MaxHeap()
{
	delete[] heapArray;
}



template<class T>
bool MaxHeap<T>::IsEmpty()
{
	return currentSize == 0;
}

template<class T>
void MaxHeap<T>::Push(const T& e)
{
	if (currentSize == maxSize) throw"is full";
	heapArray[currentSize] = e; //在数组尾部插入e
	trickleUp(currentSize);  //向上渗透
	currentSize++; //插入后堆当前大小 加1
}

template<class T>
void MaxHeap<T>::trickleUp(int index)
{
	int parent = (index - 1) / 2; //当前节点的父亲节点
	T bottom = heapArray[index];  //bottom 保存待插入节点
	while (index > 0 && heapArray[parent] < bottom)
	{
		heapArray[index] = heapArray[parent];
		index = parent;
		parent = (parent - 1) / 2;
	}
	heapArray[index] = bottom;
}

template<class T>
const T& MaxHeap<T>::Top() const
{
	return heapArray[0];
}


template<class T>
void MaxHeap<T>::Pop()
{
	heapArray[0] = heapArray[--currentSize];
	trickleDown(0);

}

template<class T>

void MaxHeap<T>::trickleDown(int index)
{
	int largeChild;
	T top = heapArray[index];

	while (index < currentSize / 2)
	{
		int leftChild = 2 * index + 1;
		int rightChild = 2 * index + 2;
		if (rightChild < currentSize && heapArray[leftChild] < heapArray[rightChild])
		{
			largeChild = rightChild;

		}
		else
		{
			largeChild = leftChild;
		}
		if (top >= heapArray[largeChild])
			break;
		heapArray[index] = heapArray[largeChild];
		index = largeChild;
	}
	heapArray[index] = top;
}
template<class T>
void HeapSort(T A[],int A_Length){
    MaxHeap<int> h(100);
    for(int i = 0;i < A_Length;i ++){
        h.Push(A[i]);
    }
    for(int i = A_Length - 1; i >= 0; i --){
        A[i] = h.Top();
        h.Pop();
    }
}
int main(){
    int A[10] = {34,52,37,74,12,85,45,17,83,95};
    HeapSort(A,10);
    for(int i = 0; i < 10; i ++){
        cout << A[i] <<endl;
    }
    return 0;
}
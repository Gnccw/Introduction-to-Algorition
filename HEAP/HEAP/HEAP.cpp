#include<iostream>
#include<time.h>

using namespace std;
void max_heapify(int A[], int i,int n);
void build_max_heap(int A[], int n);
void heapsort(int A[], int n);

int main()
{
	const int n = 200000;
	int A[n] = { 0 };
	for (int i = n; i > 0; i--)
	{
		A[n - i] = i;
	}
	double totaltime;
	clock_t start,finish;
	start=clock();
	heapsort(A, n);
	finish=clock();
	totaltime=(double(finish-start))/CLOCKS_PER_SEC;
	cout<<totaltime;
	

}

void max_heapify(int A[], int i, int n)
{
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	int largest;
	if (l<n&&A[l]>A[i]) largest = l;
	else largest = i;
	if (r<n&&A[r]>A[largest]) largest = r;
	if (i != largest) swap(A[i], A[largest]);
	else return;
	if ((2 * l + 1) >= n) return;  //若i的儿子为叶子节点，则终止递归
	max_heapify(A, largest, n);
}

void build_max_heap(int A[], int n)
{
	int i = n / 2 - 1;
	for (int j = i; j >= 0; j--)
	{
		max_heapify(A, j, n);
	}
}

void heapsort(int A[], int n)
{
	build_max_heap(A, n);
	for (int i = n-1; i>1; i--)
	{
		swap(A[i], A[0]);
		n--;
		max_heapify(A, 0,n);
	}
	if (A[0] > A[1]) swap(A[0], A[1]);
}
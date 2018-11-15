#include<iostream>
using namespace std;

void Quicksort(int A[], int p, int r);
int Partition(int A[], int p, int r);

int main()
{
	int a[17] = { 1, 4, 3, 5, 6, 2, 3, 4, 56, 3, 44, 22,454,546,2,135435435,5 };
	Quicksort(a, 0, 16);
	for (int i = 0; i < 17; i++)
	{
		cout << a[i] << " ";
	}
}

void Quicksort(int A[], int p, int r)
{
	if (p<r)
	{
		int q = Partition(A, p, r);
		Quicksort(A, p, q - 1);
		Quicksort(A, q + 1, r);
	}
	else return;
}

int Partition(int A[], int p, int r)
{
	int x = A[r];
	int i = p - 1;
	for (int j = p; j < r;j++)
	{
		if (A[j] <=x)
		{
			
			i++;
			swap(A[i], A[j]);
		}
	}
	swap(A[i + 1], A[r]);
	return i + 1;
}
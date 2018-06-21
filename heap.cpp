#include<iostream>

using namespace std;


void printHeap(int A[], const int& n)
{
	for(int i = 0; i < n; ++i)
	{
		cout<<A[i]<<endl;
	}
	cout<<endl;
}


void maxHeapify(int A[], const int& i, const int& n)
{
	if( i >= n ) return;

	int left = 2 * i + 1;
	int right = 2 * i + 2;
	
	int max = i;

	if( left < n && A[left] > A[max] )
	{
		max = left;
	}
	if( right < n && A[right] > A[max] )
	{
		max = right;
	}

	if( i == max) return;

	swap(A[i],A[max]);
	maxHeapify(A,max,n);
}

void sortHeap(int A[], int sorted[], const int& n)
{
	for(int i = 0; i < n; ++i)
	{
		sorted[n-1-i] = A[0];
	    swap(A[0],A[n-1-i]);
	    maxHeapify(A,0,n-1-i);	
	}	
}

void createHeap(int A[], const int& n)
{
	for(int i = (n-1)/2; i >=0; --i)
	{
		maxHeapify(A,i,n);
	}
}

int main()
{
	int A[9] = {10,8,4,2,1,4,5,7,8};
	int sorted[9];
	createHeap(A,9);
	printHeap(A,9);
	sortHeap(A,sorted,9);
	cout<<endl;
	printHeap(sorted,9);

	cout<<endl;
	int B[5] = {10,5,4,3,1};
	int sorted1[5];
	createHeap(B,5);
	printHeap(B,5);
	sortHeap(B,sorted1,5);
	cout<<endl;
	printHeap(sorted1,5);
}

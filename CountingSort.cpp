#include<iostream>

using namespace std;

void CountingSort(const int A[], const int& n, const int& nRange)
{
	int *count = new int[nRange];
	int *output = new int[nRange];

	for(int i = 0; i < nRange; ++i)
	{
		count[i] = 0;
		output[i] = 0;
	}

	for(int i = 0; i < n; ++i)
	{
		if( A[i] < 0 || A[i] > nRange - 1)
			cout<<"Out of Range Value : "<<A[i]<<"..ignored..";
		else
			if( A[i] )
				count[A[i]]++;
	}

	for(int i = 1; i < nRange; ++i)
		count[i] += count[i-1];

	for(int i = 0; i < n; ++i)
	{
		int ind = A[i];
		output[count[ind] - 1] = ind;
		count[ind]--;
	}

	for(int i = 0; i < n; ++i)
		cout<<output[i]<<"\t";

	cout<<endl;
}

int main()
{
	int A[10] = {1,4,1,2,7,5,2,0,0,0};
	int n = 10;
	int nElements = 7;

	CountingSort(A,nElements,n);

	int C[20] = {9,8,4,3,2,1,9,8,1,9,8,6,4,3,2,1,7,3,8,6};
	n = 10;
	nElements = 20;
	CountingSort(C,nElements,n);
}

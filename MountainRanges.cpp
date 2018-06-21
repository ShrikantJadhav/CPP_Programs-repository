#include<iostream>
#include<vector>

using namespace std;

class MountainRange
{
	public:
		int countPeaks(vector<int> A)
		{
			int n = A.size();
			int c = 0;

			if( n == 1) return 1;
			
			if( n > 1 && A[0] > A[1] )
				c++;
			if( n > 1 && A[n-2] < A[n-1])
				c++;

			for(int i = 1; i < n - 1; ++i)
			{
				if( A[i] > A[i+1] &&
					A[i] > A[i-1] )
					c++;
			}
			return c;
		}
};

int main()
{
	MountainRange MR;
	vector<int> R = {5,6,2,4};
	cout<<MR.countPeaks(R)<<endl;
	vector<int> R1 = {1,1,1,1,1,1};
	cout<<MR.countPeaks(R1)<<endl;
	vector<int>R2 = {2,1};
	cout<<MR.countPeaks(R2)<<endl;
	vector<int> R3 = {2,5,3,7,2,8,1,3,1};
	cout<<MR.countPeaks(R3)<<endl;
	return 0;
}

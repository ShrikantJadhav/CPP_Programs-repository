#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class FilipTheFrog
{
	public:
	int countReachableIslands(vector<int> A, int k)
	{
		return count;
	}
};

int main()
{
	FilipTheFrog ftf;
	vector<int> A = {4,7,1,3,5};
	cout<<ftf.countReachableIslands(A,1)<<endl;

	vector<int> A1 = {100,101,103,105,107};
	cout<<ftf.countReachableIslands(A1,2)<<endl;

	vector<int> A2 = {17,10,22,14,6,1,2,3};
	cout<<ftf.countReachableIslands(A2,4)<<endl;
}

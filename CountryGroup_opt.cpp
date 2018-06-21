#include<iostream>
#include<vector>

using namespace std;

class CountryGroup
{
	public:
		int solve(vector<int> a)
		{
			int n = a.size();
			int c = 0;
			int i = 0;

			while( i < n)
			{
				c++;
				int x = a[i];
				if(i+x > n)  //If there are no x number of elements then return -1
					return -1;

				for(int k = i; k < i+x; ++k)
				{
					if(a[k] != x) //if next x elements are not x return -1
						return -1;
				}
				i = i + x;
			}
			return c;
		}
};

int main()
{
	CountryGroup CG;
	vector<int> v1 = {2,2,3,3,3};
	cout<<CG.solve(v1)<<endl;
	vector<int> v2 = {1,1,1,1,1};
	cout<<CG.solve(v2)<<endl;
	vector<int> v3 = {3,3};
	cout<<CG.solve(v3)<<endl;
	vector<int> v4 = {4,4,4,4,1,1,2,2,3,3,3};
	cout<<CG.solve(v4)<<endl;
	vector<int> v5 = {2,1,2,2,1,2};
	cout<<CG.solve(v5)<<endl;
}


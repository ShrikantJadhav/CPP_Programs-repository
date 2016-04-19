#include<iostream>
#include<vector>

using namespace std;

class CountryGroup
{
	public:
		int solve(vector<int> a)
		{
			int count[101];
			int nCountryCount = 0;

			for(int i = 0; i < 101; ++i)
					count[i] =0;

			for(int i = 0; i < a.size(); ++i)
			{
				if( a[i] <=0 || a[i] > 100)
					continue;
				count[a[i]]++;
			}

			for(int i = 2; i < 101; ++i)
			{
				if(count[i] != 0)
				{
					if(count[i] == i)
					{
						nCountryCount++;
					}
					else
					{
						return -1;
					}
				}
			}

			return nCountryCount + count[1];
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

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class LiveConcert
{
	public:

	int maxHappiness(vector<int> h, vector<string> s)
	{
		int nRetHappiness = 0;
		for(int i = 0; i < s.size(); ++i)
		{
			string strName = s[i];
			int mx= 0;
			for(int j = 0 ; j < s.size(); ++j)
			{
				if( strName == s[j] )
				{
					mx= max(h[j],mx);
					h[j] = 0;
				}
			}
			nRetHappiness += mx;
		}
		return nRetHappiness;
	}
};

int main()
{
	LiveConcert LC;
	vector<int> h = {10,5,6,7,1,2};
	vector<string> s = {"ciel","bessie","john","bessie","bessie","john"};
	cout<<LC.maxHappiness(h,s)<<endl;

	vector<int> h1 = {3,3,4,3,3};
	vector<string> s1 = {"a","a","a","a","a"};
	cout<<LC.maxHappiness(h1,s1)<<endl;

}

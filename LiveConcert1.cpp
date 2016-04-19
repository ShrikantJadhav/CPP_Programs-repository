#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>

using namespace std;

struct sortPairs
{
	bool operator()(std::pair<string,int> a, std::pair<string,int> b)
	{
		return a.first == b.first? a.second > b.second:a.first<b.first;
	}
};

class LiveConcert
{
	public:
		int maxHappiness(vector<int> h, vector<string>s)
		{
			vector<std::pair<string,int> > vecOfPairs;

			for(int i = 0; i < s.size(); ++i)
				vecOfPairs.push_back(make_pair(s[i],h[i]));

			sort(vecOfPairs.begin(), vecOfPairs.end(),sortPairs());
	
			int mxScore = vecOfPairs[0].second;
			for(int i = 1; i < s.size(); ++i)
			{
				if( vecOfPairs[i].first != vecOfPairs[i-1].first)
						mxScore += vecOfPairs[i].second;

			}
			return mxScore;
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

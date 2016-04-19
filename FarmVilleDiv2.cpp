//Problem statement
//https://community.topcoder.com/stat?c=problem_statement&pm=14047
//

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

class FarmvilleDiv2
{
	public:

	int minTime(vector<int> Time, vector<int> Cost, int nBudget)
	{
		vector<pair<int,int> > vecOfPairs;
		int n = Time.size();

		for(int i = 0; i < n; ++i)
		{
			pair<int,int> p = make_pair(Cost[i],Time[i]);
			vecOfPairs.push_back(p);
		}

		sort(vecOfPairs.begin(),vecOfPairs.end());
		for(int i = 0; i <n ; i++)
		{
			if( vecOfPairs[i].second * vecOfPairs[i].first <= nBudget )
			{
				nBudget -= vecOfPairs[i].second * vecOfPairs[i].first;
				vecOfPairs[i].second = 0;
			}
			else
			{
				while(vecOfPairs[i].first <= nBudget &&
						  vecOfPairs[i].second > 0 )
				{
					vecOfPairs[i].second--;
				    nBudget -= vecOfPairs[i].first;
			    }
			}
		}

		int sum = 0;
		for(int i = 0; i< n; ++i)
		{
			sum += vecOfPairs[i].second;
		}
		return sum;
	}
};

int main()
{
	FarmvilleDiv2 fm;

	vector<int> time = {100};
	vector<int> cost = {1};
	cout<<fm.minTime(time,cost,26)<<endl;

	vector<int> time1 = {100};
	vector<int> cost1 = {1};
	cout<<fm.minTime(time1,cost1,101)<<endl;

	vector<int> time2 = {2,1};
	vector<int> cost2 = {1,1};
	cout<<fm.minTime(time2,cost2,3)<<endl;

	vector<int> time3 = {1,2,3,4,5};
	vector<int> cost3 = {5,4,3,2,1};
	cout<<fm.minTime(time3,cost3,15)<<endl;

	vector<int> time4 = {100,100,100,100,100,100,100,100,100,100};
	vector<int> cost4 = {2,4,6,8,10,1,3,5,7,9};
	cout<<fm.minTime(time4,cost4,5000)<<endl;

	vector<int> time5 = {30,40,20,10};
	vector<int> cost5 = {10,20,30,40};
	cout<<fm.minTime(time5,cost5,5)<<endl;
	
}

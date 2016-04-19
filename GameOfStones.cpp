#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class GameOfStones
{
	public:
		int count(vector<int> stones)
		{
			int sum = accumulate(stones.begin(),stones.end(),0);
			int n = stones.size();

			if( sum % n != 0)
				return -1; //can't equally distribute sum number of stones

			int r = sum/n;//each index will have r number of stones
			int cost = 0;
			for(int i= 0; i < n; ++i)
			{
				if( stones[i] %2 != r%2 )
					return -1;

				if( stones[i] > r)
				{
					cost += (stones[i] - r)/2;
				}
			}
			return cost;
		}
};

int main()
{
	GameOfStones GS;
	vector<int> v1 = {7,15,9,5};
	cout<<GS.count(v1)<<endl;

	vector<int> v2 = {10,16};
	cout<<GS.count(v2)<<endl;

	vector<int> v3 = {2,8,4};
	cout<<GS.count(v3)<<endl;
}

//Problem statement
//https://community.topcoder.com/stat?c=problem_statement&pm=14138

#include <iostream>

using namespace std;


class CoinFlipDiv2
{
	public:
		int countCoins(string state)
		{
			int nCount = 0;
			int n = state.length();
			for(int i = 0; i < n; ++i)
			{
				if(( i > 0 && state[i-1] != state[i] )||
				   ( i < n-1 && state[i+1] != state[i] ))
				{
					nCount++;
				}
			}
			return nCount;
		}
};


int main()
{
	CoinFlipDiv2 c;
	cout<<c.countCoins("HT")<<endl;
	cout<<c.countCoins("T")<<endl;
	cout<<c.countCoins("HHH")<<endl;
	cout<<c.countCoins("HHTHHH")<<endl;
	cout<<c.countCoins("HHHTTTHHHTTTHTHTH")<<endl;
	return 0;
}

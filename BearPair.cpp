//Problem statement
//https://community.topcoder.com/stat?c=problem_statement&pm=14130

#include<iostream>

using namespace std;

class BearPair
{
	public:
			int bigDistance(string s)
			{
				int n = s.length();
				int maxDiff = -1;
				for(int i = 0; i < n; ++i)
				{
					for(int j = 0 ; j < n; ++j)
					{
						if( s[i] != s[j] )
						{
							int CurDiff = j-i;
							if( CurDiff > maxDiff)
							{
								maxDiff = CurDiff;
							}
						}
					}
				}
				return maxDiff;
			}
};

int main()
{
		BearPair bp;
		cout<<bp.bigDistance("bear")<<endl;
		cout<<bp.bigDistance("abcba")<<endl;
		cout<<bp.bigDistance("oooohyeahpotato")<<endl;
		cout<<bp.bigDistance("xxyyxyxyyyyyyxxxyxyxxxyxyxyyyyyxxxxxxyyyyyyyyxxxxx")<<endl;
		cout<<bp.bigDistance("zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz")<<endl;
}

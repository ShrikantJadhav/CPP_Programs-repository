#include<iostream>

using namespace std;

class BearCheats
{
	public:
		string eyeSight(int a, int b)
		{
			int nMisMatchCount = 0;
			if( a == 0)
			{
				if( b >= 0 && b <= 9) return "happy";
				else return "glasses";
			}
			
			if( b == 0 )
			{
				if( a >= 0 && a <= 9) return "happy";
				else return "glasses";
			}

			while(a && b)
			{
				if( a%10 != b%10)
					nMisMatchCount++;
				a = a/10;
				b = b/10;
			}

			if( a == 0 && b == 0 &&
				nMisMatchCount <= 1)
			{
				return "happy";
			}
			else
			{
				return "glasses";
			}
		}
};


int main()
{
	BearCheats BC;
	cout<<BC.eyeSight(8072,3072)<<endl;
	cout<<BC.eyeSight(508,540)<<endl;
	cout<<BC.eyeSight(854000,854000)<<endl;
	cout<<BC.eyeSight(1,0)<<endl;
	cout<<BC.eyeSight(385900,123000)<<endl;
}

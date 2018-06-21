#include<iostream>
#include<cmath>

using namespace std;

class FibonacciDiv2
{
		public:
			int find(int x)
			{
				int F0 = 0;
				int F1 = 1;

				while(1)
				{
					if( F0 == x || F1 == x)
							return 0;
					int tmp = F1 + F0;
					F0 = F1;
					F1 = tmp;
					if( F1 < x  &&
						x < (F0 + F1))
					{
						return min(abs(F1 - x),abs(x - (F0 + F1)));
					}
				}
			}
};

int main()
{
	FibonacciDiv2 FB;
	cout<<FB.find(1)<<endl;
	cout<<FB.find(13)<<endl;
	cout<<FB.find(15)<<endl;
	cout<<FB.find(19)<<endl;
	cout<<FB.find(1000000)<<endl;
	return 0;
}

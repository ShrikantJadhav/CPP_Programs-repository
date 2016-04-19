#include<iostream>

using namespace std;

class LuckyXOR
{
	public:
		int construct(int num)
		{
			int LuckyNum[6] = {4,7,44,47,74,77};

			for(int i = 0;i < 6; ++i)
			{
				int b = num ^ LuckyNum[i];
				if(b > num && b < 100)
					return b;
			}
			return -1;
		}
};

int main()
{
	LuckyXOR LX;
	cout<<LX.construct(4)<<endl;
	cout<<LX.construct(19)<<endl;
	cout<<LX.construct(88)<<endl;
	cout<<LX.construct(36)<<endl;
}

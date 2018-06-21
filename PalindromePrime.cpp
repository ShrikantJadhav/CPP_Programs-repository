#include<iostream>
#include<cmath>

using namespace std;

class PalindromePrime
{
	public:
		bool IsPalindrome(int num)
		{
			int len = log10(num) + 1;
			bool bPal = true;
			double i = 1;

			while(i <= len-i)
			{
				if(num % (int)pow(10,i) != num / (int)pow(10,len - i)) 
				{
					bPal = false;
					break;
				}
				i++;
			}
			return bPal;
		}

		bool IsPrime(int num)
		{
			bool bPrime = true;

			if ( num == 1 ) return false;
			if ( num == 2 ) return true;

			for( int i = 2; i*i <= num; i++)
			{
				if( num % i == 0)
				{
					bPrime = false;
					break;
				}
			}
			return bPrime;
		}

		int count(int L, int R)
		{
			int count = 0;
			if( L <= 2)
			{
				count++;
				L = 3;
			}

			if( L % 2 == 0) L++;

			for(int i = L; i <= R; i+=2 )
			{
				if(IsPalindrome(i) && IsPrime(i))
					count++;
			}

			return count;
		}
};


int main()
{
	PalindromePrime p;
	cout<<p.count(100,150)<<endl;
	cout<<p.count(1,9)<<endl;
	cout<<p.count(1,1)<<endl;
	cout<<p.count(1,1000)<<endl;
}

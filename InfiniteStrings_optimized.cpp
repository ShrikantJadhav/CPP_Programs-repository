#include<iostream>
#include<string>

using namespace std;

class InfiniteString
{
	public:
		int gcd( int a, int b)
		{
			if( b == 0 ) return a;
			if( a < b) swap(a,b);
			if( a % b == 0) return b;
			return gcd(b,a%b);
		}

		string equal(string s, string t)
		{
			int nSLen = s.length();
			int nTLen = t.length();

			int g = gcd(nSLen,nTLen);
			string subStr = s.substr(0,g);

			for(int i = 0; i < nSLen; i+=g)
			{
				if(subStr != s.substr(i,g))
					return "Non equal";
			}

			for(int i = 0; i < nTLen; i+=g)
			{
				if(subStr != t.substr(i,g))
					return "Non equal";
			}
			return "Equal";
		}
};

int main()
{
	InfiniteString IS;
	cout<<IS.equal("ab","ab")<<endl;
	cout<<IS.equal("ab","abab")<<endl;
	cout<<IS.equal("abc","bca")<<endl;
	cout<<IS.equal("aba","abab")<<endl;
	cout<<IS.equal("aaaaa","aaaaaa")<<endl;
	cout<<IS.equal("ababab","abab")<<endl;
	cout<<IS.equal("a","z")<<endl;
	return 0;
}

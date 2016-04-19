#include<iostream>
#include<string>

using namespace std;

class InfiniteString
{
	public:
		string equal(string s, string t)
		{
			if( s.length() == t.length())
			{
				if(s != t)
					return "Not equal";
			}
			string tmpS = s;
			string tmpT = t;

			while(s != t)
			{
				size_t nSLength = s.length();
				size_t nTLength = t.length();

				if( nSLength != nTLength )
				{
					if(nSLength < nTLength )
						s += tmpS;
					else
						t += tmpT;
				}
				else
				{
					return "Not equal";
				}
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

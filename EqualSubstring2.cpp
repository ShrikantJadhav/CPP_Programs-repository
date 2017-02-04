#include<iostream>
#include<string>

using namespace std;

class EqualSubstrings2
{

public:
int get(string str)
{
	int n = str.size();
	int count = 0;

	int k = 1;
	while( k <= n-1 )
	{
		for(int i = 0; i < n - 1; ++i)
		{
			string sub1 = str.substr(i,k);
			for(int j = i + k; j < n; ++j)
			{
				string sub2 = str.substr(j,k);
				//cout<<sub1<<" "<<sub2<<endl;
				if ( sub1 == sub2)
				{
					count++;
				}
			}
		}
		k++;
	}
	return count;
}
};

int main()
{
	EqualSubstrings2 eqc;
	cout<<eqc.get("abab")<<endl;
	cout<<eqc.get("aaab")<<endl;
	cout<<eqc.get("aa")<<endl;
	cout<<eqc.get("aaaab")<<endl;
	cout<<eqc.get("onetwothreeonetwothree")<<endl;
	cout<<eqc.get("abcd")<<endl;
}

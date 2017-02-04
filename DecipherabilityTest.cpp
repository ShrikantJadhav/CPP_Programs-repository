#include<iostream>
#include<string>

using namespace std;

class DecipherabilityTest
{
	public:
		string check(string s,string t)
		{
			for(int i = 0; i < s.length(); ++i)
			{
				string tmp = s.substr(0,i) + s.substr(i+i);
				if( tmp == t)
					return "Possible";
			}
			return "Impossible";
		}
};


int main()
{
		DecipherabilityTest DT;
		cout<<DT.check("sunuke","snuke")<<endl;
}

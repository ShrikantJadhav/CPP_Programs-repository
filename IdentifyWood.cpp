#include<iostream>
#include<string>

using namespace std;

class IdentifyingWood
{
	public:
	string check(string s, string t)
	{
		int count = 0;
		int lastMatched = -1;
		int j = 0;
		for(int i = 0; i < t.length(); ++i)
		{
			for(; j < s.length(); ++j)
			{
				if(s[j] == t[i] )
				{
					lastMatched = j;
					count++;
					break;
				}
			}
			j = lastMatched + 1;
		}

		if( count == t.length() )
		{
			return "Yep, it's wood.";
		}
		return "Nope.";
	}
};

int main()
{
	IdentifyingWood IW;
	cout<<IW.check("abcdefg","acdf")<<endl;
	cout<<IW.check("oxoxoxox","ooxxoo")<<endl;
	cout<<IW.check("oxoxoxox","xxx")<<endl;
	cout<<IW.check("qwerty","qwerty")<<endl;
	cout<<IW.check("string","longstring")<<endl;
}

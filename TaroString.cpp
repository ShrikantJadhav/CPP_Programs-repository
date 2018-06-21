#include<iostream>
#include<string>

using namespace std;

class TaroString
{
	public:
		string getAnswer(string s)
		{
			int cCount = 0, aCount = 0, tCount = 0;
			string cat = "CAT";
			int k = 0;

			for(int i =0; i < s.size(); ++i)
			{
				if(s[i] == 'A') aCount++;
				if(s[i] == 'C') cCount++;
				if(s[i] == 'T') tCount++;
				if(s[i] == cat[k])
					k++;
			}

			if(k == 3 && cCount == 1 && aCount ==1 && tCount == 1)
			{
				return "Possible";
			}
			else
			{
				return "Impossible";
			}
		}
};

int main()
{
	TaroString TS;
	cout<<TS.getAnswer("XCYAZTX")<<endl;
	cout<<TS.getAnswer("CTA")<<endl;
	cout<<TS.getAnswer("ACBBAT")<<endl;
	cout<<TS.getAnswer("SGHDJHFIOPUFUHCHIOJBHAUINUIT")<<endl;
	cout<<TS.getAnswer("CCCATT")<<endl;
	
}


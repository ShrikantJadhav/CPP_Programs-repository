#include<iostream>
#include<set>


using namespace std;

class SqaureScoreDiv2
{
	public:
		int getscore(string s)
		{
			int c = 0;
			for(int i = 0; i < s.size();++i)
			{
				for(int j = i; j < s.size(); ++j)
				{
					set<char> st;
					for(int k = i; k <= j; ++k)
					{
						st.insert(s[k]);
					}
					if(st.size() == 1)
						c++;
				}
			}
			return c;
		}

};

int main()
{
	SqaureScoreDiv2 SSD;
	cout<<SSD.getscore("aaaba")<<endl;
	cout<<SSD.getscore("zzzxxzz")<<endl;
	cout<<SSD.getscore("abcdefghijklmnopqrstuvwxyz")<<endl;
	cout<<SSD.getscore("p")<<endl;
	cout<<SSD.getscore("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa")<<endl;

}

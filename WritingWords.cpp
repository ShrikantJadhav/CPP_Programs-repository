#include<iostream>
#include<string>

using namespace std;

class WritingWords
{
	public:
		int write(string word)
		{
			int count = 0;
			for(int i = 0; i < word.size(); ++i)
			{
				int k = (int)(word[i]) - 64;
				count +=k;
			}
			return count;
		}
};

int main()
{
	WritingWords WW;
	cout<<WW.write("A")<<endl;
	cout<<WW.write("ABC")<<endl;
	cout<<WW.write("VAMOSGIMNASIA")<<endl;
	cout<<WW.write("TOPCODER")<<endl;
	cout<<WW.write("SINGLEROUNDMATCH")<<endl;
	cout<<WW.write("ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ")<<endl;
}

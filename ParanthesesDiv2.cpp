#include<iostream>

using namespace std;

class ParanthesesDiv2Easy
{
	public:
		int getDepth(string s)
		{
			int maxDepth = 0;

			int curDepth = 0;
			for(int i = 0; i < s.size(); ++i)
			{
				if( s[i] == '(' )
					curDepth++;
				if( s[i] == ')' )
					curDepth = 0;

				if( curDepth > maxDepth )
						maxDepth = curDepth;
			}
			return maxDepth;
		}
};

int main()
{
	ParanthesesDiv2Easy PD;
	cout<<PD.getDepth("(())")<<endl;
	cout<<PD.getDepth("()()()")<<endl;
	cout<<PD.getDepth("(())()")<<endl;
	cout<<PD.getDepth("((())())(((())(()))())")<<endl;
	cout<<PD.getDepth("()")<<endl;
}

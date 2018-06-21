#include<iostream>
#include<string>
#include<sstream>

using namespace std;

class MicroStrings
{
	public:
		string makeMicroString(int A, int D)
		{
			stringstream ss;
			ss<<A;
			string str = ss.str();

			while(A >= 0)
			{
				A = A - D;
				if( A >= 0)
				{
					ss.str("");
					ss<<A;
					str += ss.str();
				}
			}
			return str;
		}
};

int main()
{
	MicroStrings MS;
	cout<<MS.makeMicroString(12,5)<<endl;
	cout<<MS.makeMicroString(3,2)<<endl;
	cout<<MS.makeMicroString(31,40)<<endl;
	cout<<MS.makeMicroString(30,6)<<endl;
}

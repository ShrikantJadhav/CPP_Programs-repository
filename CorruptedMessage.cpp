#include<iostream>
#include<string>

using namespace std;

class CorruptedMessage
{
	public:
		string reconstructMessage(string strMsg, int n)
		{
			if( n == 0) return strMsg;
			int l = strMsg.length();
			for(int i = 0; i < l; ++i)
			{
				int count = 0;
				for(int j = 0; j < l; ++j)
				{
					if(strMsg[i] != strMsg[j])
						count++;
				}
				if(count == n)
					return string(strMsg.size(),strMsg[i]);
			}
			
			if( l == n)
			{
				char ch = 'a';
				for(int i = 97; i < 123;++i)
				{
					ch = i;
					if(strMsg.find(ch) == string::npos)
					{
						break;
					}
				}
				return string(strMsg.size(),ch);
			}
			//ideally should not come here, as per input constraint
			//return null
			return strMsg;
		}
};

int main()
{
	CorruptedMessage CM;
	cout<<CM.reconstructMessage("hello",3)<<endl;
	cout<<CM.reconstructMessage("abc",3)<<endl;
	cout<<CM.reconstructMessage("wwwwwwwwwwwwwwwwww",0)<<endl;
	cout<<CM.reconstructMessage("ababba",3)<<endl;
	cout<<CM.reconstructMessage("ozztxtoxytyt",10)<<endl;
	cout<<CM.reconstructMessage("jlmnmiunaxzywed",13)<<endl;
	return 0;
}

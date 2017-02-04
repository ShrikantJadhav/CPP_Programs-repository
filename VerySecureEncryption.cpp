#include<iostream>
#include<string>
#include<vector>

using namespace std;

class VerySecureEncryption
{
	public:
		string encrypt(string strMsg, vector<int> key, int n)
		{
			string sMsg = strMsg;
			for(int i = 0; i < n; ++i)
			{
				for(int j = 0; j < key.size(); ++j)
				{
					sMsg[key[j]] = strMsg[j];
				}
				strMsg = sMsg;
			}
			return strMsg;
		}
};

int main()
{
	VerySecureEncryption vse;
	vector<int> key = {1,2,0};
	cout<<vse.encrypt("abc",key,1)<<endl;	

	vector<int> key1 = {4,3,2,1,0};
	cout<<vse.encrypt("abcde",key1,1)<<endl;	

	cout<<vse.encrypt("abcde",key1,2)<<endl;	
}

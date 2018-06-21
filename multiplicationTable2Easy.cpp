#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

string isGoodSet(vector<int> table, vector<int> t)
{
	int n = sqrt(table.size());

	string retValue[2] = {"Not Good","Good"};

	for(int i = 0; i < t.size(); ++i)
	{
		for(int j = 0; j < t.size(); ++j)
		{
			int nIndex = (t[i] * n) + t[j];

			if( nIndex > table.size() )
				return retValue[0];

			bool bFound = false;
			for(int k = 0; k < t.size(); ++k)
			{
				if( t[k] == table[nIndex] )
					bFound = true;
			}

			if( ! bFound )
				return retValue[0];
		}
	}
	return retValue[1];
}

int main()
{
	vector<int> A  = {1, 1, 2, 3, 1, 0, 2, 3, 3, 3, 0, 3, 2, 2, 2, 0};
	vector<int> t = {1,0};

	cout<<isGoodSet(A,t)<<endl;

	vector<int> C = {1, 1, 2, 3, 1, 0, 2, 3, 3, 3, 0, 3, 2, 2, 2, 0};
	vector<int> t1 = {2,2};

	cout<<isGoodSet(C,t1)<<endl;

	vector<int> B = {1, 1, 2, 3, 1, 0, 2, 3, 3, 3, 0, 3, 2, 2, 2, 0};
	vector<int> t2 = {0,1,2,3};

	cout<<isGoodSet(B,t2)<<endl;

	vector<int> t3 = {1};
	cout<<isGoodSet(B,t3)<<endl;

	vector<int> D = {2,2,2,2,2,2, 2,2,2,2,2,2, 2,2,2,2,2,2, 2,2,2,2,2,2, 2,2,2,2,2,2, 2,2,2,2,2,2};
	vector<int> t4 = {2,4,5};
	cout<<isGoodSet(D,t4)<<endl;

	vector<int> t5 = {0,1,3,4,5};
	cout<<isGoodSet(D,t5)<<endl;
}

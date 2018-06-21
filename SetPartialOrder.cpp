#include<iostream>
#include<set>
#include<vector>

using namespace std;

class SetPartialOrder
{
	public:
	string compareSets(vector<int> X, vector<int> Y)
	{
		set<int> SetX(X.begin(),X.end());
		set<int> SetY(Y.begin(),Y.end());

		for(size_t i = 0; i < X.size(); ++i)
			SetY.erase(X[i]);

		for(size_t i = 0; i < Y.size(); ++i)
			SetX.erase(Y[i]);

		vector<string> retValues = {"EQUAL","LESS","GREATER","INCOMPARABLE"};
		size_t xn = SetX.size();
		size_t yn = SetY.size();
		if(xn == 0 && yn ==0)
		{
			return retValues[0];
		}
		if(xn < yn)
		{
			return retValues[1];
		}
		if(xn > yn )
		{
			return retValues[2];
		}
		if( xn == yn )
		{
			return retValues[3];
		}

	}
};

int main()
{
	SetPartialOrder SP;
	vector<int> X = {1,2,3,5,8};
	vector<int> Y = {8,5,1,3,2};
	cout<<SP.compareSets(X,Y)<<endl;
	vector<int> X1 = {2, 3, 5, 7};
	vector<int> Y1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	cout<<SP.compareSets(X1,Y1)<<endl;
	vector<int> X2 = {2, 4, 6, 8, 10, 12, 14, 16};
	vector<int> Y2 = {2, 4, 8, 16};
	cout<<SP.compareSets(X2,Y2)<<endl;
	vector<int> X3 = {42, 23, 17};
	vector<int> Y3 = {15, 23, 31};
	cout<<SP.compareSets(X3,Y3)<<endl;
	return 0;
}

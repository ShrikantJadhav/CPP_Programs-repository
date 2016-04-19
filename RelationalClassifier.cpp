#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class RelationalClassfier
{
	public:
  	string isBijection(vector<int> X, vector<int> Y)
	{
		sort(X.begin(), X.end());
		sort(Y.begin(), Y.end());

		bool bijection = true;

		for(int i = 0;bijection == true && i < X.size() - 1; ++i)
		{
			if( X[i] == X[i+1] )
				bijection=false;
		}

		for(int i = 0; bijection == true && i < Y.size() - 1; ++i)
		{
			if( Y[i] == Y[i+1] )
				bijection=false;
		}

		if( bijection )
			return "Bijection";
		else
			return "Not";
	}
};

int main()
{
	RelationalClassfier RC;
	vector<int> X = {1,1};
	vector<int> Y = {2,3};
	cout<<RC.isBijection(X,Y)<<endl;

	vector<int> X1 = {4,5};
	vector<int> Y1 = {2,2};
	cout<<RC.isBijection(X1,Y1)<<endl;

	vector<int> X2 = {1};
	vector<int> Y2 = {2};
	cout<<RC.isBijection(X2,Y2)<<endl;

	vector<int> X3 = {1,2,3,4,5};
	vector<int> Y3 = {1,2,3,4,5};
	cout<<RC.isBijection(X3,Y3)<<endl;

	vector<int> X4 = {14,12,10,13,20,18,9,17,14,9};
	vector<int> Y4 = {18,6,8,15,2,14,10,13,15};
	cout<<RC.isBijection(X4,Y4)<<endl;
}

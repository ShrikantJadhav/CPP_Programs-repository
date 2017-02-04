#include<iostream>
#include<vector>

using namespace std;

class AmebaDiv2
{
	public:
		int simulate(vector<int> X, int A)
		{
			for(int i = 0; i < X.size(); ++i)
			{
				if( X[i] == A)
					A += X[i];
			}
			return A;
		}
};

int main()
{
	AmebaDiv2 AD;
	vector<int> v = {2,1,3,1,2};
	cout<<AD.simulate(v,1)<<endl;

	vector<int> v1 = {1,4,9,16,25,36,49};
	cout<<AD.simulate(v1,10)<<endl;

	vector<int> v2 = {1,2,4,8,16,32,64,128,256,1024,2048};
	cout<<AD.simulate(v2,1)<<endl;

	vector<int> v3 = {817,832,817,832,126,817,63,63,126,817,832,287,823,817,574};
	cout<<AD.simulate(v3,63)<<endl;
}

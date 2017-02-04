#include<iostream>
#include<vector>
#include<set>

using namespace std;

class ThePhatomMenace
{
	public:

	int find(vector<int> Doors, vector<int> Droids)
	{
		vector<set<int> > vecOfDist;

		for(int i = 0; i < Doors.size(); ++i)
		{
			set<int> tempSet;

			for(int j = 0; j < Droids.size(); ++j)
			{
				tempSet.insert(abs(Doors[i] - Droids[j]));
			}
			vecOfDist.push_back(tempSet);
		}

		int retValue = 0;
		for(int i = 0; i < Doors.size() ; ++i)
		{
			std::set<int>::iterator itr;
			itr = vecOfDist[i].begin();

			if(itr != vecOfDist[i].end() && *itr > retValue )
			{
				retValue = *itr;
			}
		}
		return retValue;
	}
};


int main()
{
	ThePhatomMenace TPM;
	vector<int> A = {1,2,3,4};
	vector<int> B = {5,6,7,8};
	cout<<TPM.find(A,B)<<endl;

	vector<int> A1 = {1};
	vector<int> B1 = {10};
	cout<<TPM.find(A1,B1)<<endl;

	vector<int> A2 = {2,3,5,7,11};
	vector<int> B2 = {1,8,13};
	cout<<TPM.find(A2,B2)<<endl;

	vector<int> A3 = {1,3,5,7,9,11,13,15,17,19};
	vector<int> B3 = {2,4,6,8,10,12,14,16,18,20};
	cout<<TPM.find(A3,B3)<<endl;

	vector<int> A4 = {2,1};
	vector<int> B4 = {4,3};
	cout<<TPM.find(A4,B4)<<endl;
}

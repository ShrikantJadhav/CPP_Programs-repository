#include<iostream>
#include<set>
#include<vector>

using namespace std;

class Cdgame
{
	public:
		int rescount(vector<int> A, vector<int> B)
		{
			set<int> setResults;
			uint64_t sumA = 0;
			uint64_t sumB = 0;

			for(int i = 0; i < A.size() ; ++i)
				sumA += A[i];

			for(int i = 0; i < B.size() ; ++i)
				sumB += B[i];

			for(int i = 0; i < A.size(); ++i)
			{
				for(int j = 0 ; j < B.size(); ++j)
				{
					sumA = sumA - A[i] + B[j];
					sumB = sumB - B[j] + A[i];
					setResults.insert(sumA * sumB);
					sumA = sumA + A[i] - B[j];
					sumB = sumB + B[j] - A[i];
				}
			}
			
			return setResults.size();
		}
};

int main()
{
	Cdgame c;
	vector<int> A = {1,2};
	vector<int> B = {3,4};
	cout<<c.rescount(A,B)<<endl;

	vector<int> A1 = {1,2,4};
	vector<int> B1 = {8,16,32};
	cout<<c.rescount(A1,B1)<<endl;

	vector<int> A2 = {1,1,1};
	vector<int> B2 = {1,1,1};
	cout<<c.rescount(A2,B2)<<endl;

	vector<int> A3 = {1,2,3};
	vector<int> B3 = {5,5,5};
	cout<<c.rescount(A3,B3)<<endl;

	vector<int> A4 = {3,3,4,1};
	vector<int> B4 = {2,2,2,100};
	cout<<c.rescount(A4,B4)<<endl;

	vector<int> A5 = {31,34,55,56,57};
	vector<int> B5 = {1,2,3,4,5};
	cout<<c.rescount(A5,B5)<<endl;
}

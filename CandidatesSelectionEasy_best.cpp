#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class CandidatesSelectionEasy
{
		public:
vector<int> sort(vector<string> score, int x)
{
	int n = score.size();
	vector<int> ids(n);
	for (int i = 0; i < n; i++)
	{
		ids[i] = i;
	}

	// we can use a custom comparator function using a lambda - new c++11 feature
	std::sort(ids.begin(), ids.end(), [&](int a, int b) {
		return make_pair(score[a][x],a) < make_pair(score[b][x],b);
	});

	return ids;
}
};

int main()
{
	CandidatesSelectionEasy CE;
	vector<string> V1 = {"ACB","BAC","CBA"};
	vector<int> v = CE.sort(V1,1);
	cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<endl;

	vector<string> V2 = {"A","C","B","C","A"};
	vector<int> v1 = CE.sort(V2,0);
	cout<<v1[0]<<" "<<v1[1]<<" "<<v1[2] <<" "<< v1[3]<<" "<<v1[4]<<endl;
}

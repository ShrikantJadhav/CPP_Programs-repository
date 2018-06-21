#include <iostream>
#include <string>
#include <vector>

using namespace std;

class CandidatesSelectionEasy
{
	public:
		vector<int> sort(vector<string> score, int x)
		{
			vector<vector<int> > rank;
			for(int i = 0; i < 50; ++i)
			{
				vector<int> v1;
				rank.push_back(v1);
			}

			vector<int> sortedCandidates;

			for(int i = 0; i < score.size(); ++i)
			{
				char ch = score[i][x];
				int r = (int)(ch - '0');
				vector<int>& r1 = rank[r];
				r1.push_back(i);
			}

			for(int i = 0; i < 50; ++i)
			{
				vector<int>& r1 = rank[i];
				if( r1.size() != 0)
				{
					for(int j = 0; j < r1.size(); ++j)
							sortedCandidates.push_back(r1[j]);
				}
			}

			return sortedCandidates;
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

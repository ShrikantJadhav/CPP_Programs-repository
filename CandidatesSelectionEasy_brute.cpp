#include<iostream>
#include<vector>
#include<string>

using namespace std;

class CandidatesSelectionEasy
{
	public:
		vector<int> sort(vector<string> score, int x)
		{
			vector<int> sortedCandidate;
			for(char ch = 'A'; ch <= 'Z'; ch++)
			{
				for(int i = 0; i < score.size(); ++i)
				{
					if(score[i][x] == ch )
					{
						sortedCandidate.push_back(i);
					}
				}
			}

			return sortedCandidate;
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

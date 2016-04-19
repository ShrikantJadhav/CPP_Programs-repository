#include<iostream>
#include<vector>

using namespace std;

class DevuAndGame
{
	public:
		string canWin(vector<int> vecNextLevel)
		{
			if(vecNextLevel.size() == 0) return "Lose";
			vector<bool> vecVisited;
			vecVisited.resize(vecNextLevel.size());

			for(int i = 0; i < vecNextLevel.size(); ++i)
				vecVisited[i] = false;

			int i = 0;
			int n = vecNextLevel.size();
			while( i >= 0 && i <= n-1 &&
				   vecNextLevel[i] != -1 &&
				   vecNextLevel[i] != i &&
				   vecVisited[i] != true )
			{
				vecVisited[i] = true;
				i = vecNextLevel[i];
			}

			if(vecNextLevel[i] == -1)
					return "Win";
			else
					return "Lose";
		}
};

int main()
{
	DevuAndGame DG;
	vector<int> V1 = {1,-1};
	cout<<DG.canWin(V1)<<endl;

	vector<int> V2 = {1,0,-1};
	cout<<DG.canWin(V2)<<endl;

	vector<int> V3 = {29,33,28,16,-1,11,10,14,6,31,7,35,34,8,15,17,26,12,13,22,1,20,2,21,-1,5,19,9,18,4,25,32,3,30,23,10,27};
	cout<<DG.canWin(V3)<<endl;

	vector<int> V4 = {17,43,20,41,42,15,18,35,-1,31,7,33,23,33,-1,-1,0,33,19,12,42,-1,-1,9,9,-1,39,-1,31,46,-1,20,44,41,-1,-1,12,-1,36,-1,-1,6,47,10,2,4,1,29};
	cout<<DG.canWin(V4)<<endl;

	vector<int> V5 = {3,1,1,2,-1,4};
	cout<<DG.canWin(V5)<<endl;
}

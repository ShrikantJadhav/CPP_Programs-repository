#include<iostream>
#include<string>
#include<vector>

using namespace std;

class BichromeBoard
{
	public:
		string ableToDraw(vector<string> board)
		{
			for(int k = 0; k < 2; ++k)
			{
				bool bad = false;

				for(int i = 0; i < board.size(); ++i)
				{
					for(int j = 0; j < board[i].size(); ++j)
					{
						if(board[i][j] != '?')
						{
							if(board[i][j] != ((i+k+j)%2 ==0?'W':'B'))
									bad = true;
						}
					}
				}

				if(! bad )
				{
					return "Possible";
				}
			}
			return "Impossible";
		}
};

int main()
{
	BichromeBoard BB;
	vector<string> b = {"W?W", "??B", "???"};
	cout<<BB.ableToDraw(b)<<endl;
	vector<string> b1 = {"W??W"};
	cout<<BB.ableToDraw(b1)<<endl;
	vector<string> b2 = {"??"};
	cout<<BB.ableToDraw(b2)<<endl;
	vector<string> b3 = {"W???", "??B?", "W???", "???W"};
   	cout<<BB.ableToDraw(b3)<<endl;
	vector<string> b4 = {"W???", "??B?", "W???", "?B?W"};
   	cout<<BB.ableToDraw(b4)<<endl; 
	return 0;
}

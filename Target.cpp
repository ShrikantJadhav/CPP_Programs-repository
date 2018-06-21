#include<iostream>
#include<vector>

using namespace std;

class Target
{
	public:
	vector<string> draw(int n)
	{
		vector<string> board;
		for(int i = 0; i < n; ++i)
		{
			string str(n+1,' ');
			board.push_back(str);
		}

		for(int i = 0; i < n ; i+=2)
		{
			for(int j = i; j <= n-1-i; ++j)
			{
				board[i][j] = '#';	
				board[j][i] = '#';
			}

			for(int j = n-1-i; j <= i ; ++j)
			{
				board[i][j] = '#';
				board[n-j-1][i] = '#';
			}
		}

		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
					cout<<board[i][j]<<" ";
			}
			cout<<endl;
		}
		return board;
	}
};

int main()
{
	Target T;
	T.draw(5);
	T.draw(9);
	T.draw(13);
	T.draw(17);
	T.draw(21);
}

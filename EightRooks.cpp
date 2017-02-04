#include<iostream>
#include<string>

using namespace std;

class EightRooks
{
	public:
		string isCorrect(string chessBoard[])
		{
			int row[8];
			int col[8];

			for(int i = 0; i < 8; ++i)
			{
				row[i] = 0; col[i] = 0;
			}

			for(int i = 0; i < 8; ++i)
			{
				for(int j = 0 ; j < 8 ; ++j)
				{
					if(chessBoard[i][j] == 'R')
					{
						row[i]++;
						col[j]++;
					}
				}
			}

			for(int i = 0; i < 8;++i)
			{
				if( row[i] != 1 && col[i] != 1)
						return "Incorrect";
			}
			return "Correct";
		}
};

int main()
{
	EightRooks ER;
	string cb[] = {"R.......", ".R......", "..R.....", "...R....", "....R...", ".....R..", "......R.", ".......R"};
	cout<<ER.isCorrect(cb)<<endl;

	string cb1[] = {"........", "....R...", "........", ".R......", "........", "........", "..R.....", "........"};
	cout<<ER.isCorrect(cb1)<<endl;

	string cb2[] = {"......R.", "....R...", "...R....", ".R......", "R.......", ".......R", "..R.....", ".......R"};
	cout<<ER.isCorrect(cb2)<<endl;

	string cb3[] = {"........", "........", "........", "........", "........", "........", "........", "........"};
	cout<<ER.isCorrect(cb3)<<endl;

	return 0;
}

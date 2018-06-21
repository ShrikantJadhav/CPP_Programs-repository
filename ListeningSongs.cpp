#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

class ListeningSongs
{
	public:
	int listen(vector<int> A, vector<int> B, int mins, int T)
	{
		if( A.empty() || B.empty() )
			return -1;
		
		uint64_t sec = mins * 60;
		uint64_t curSec = 0;

		int ASize = A.size();
		int BSize = B.size();

		sort(A.begin(),A.end());
		sort(B.begin(),B.end());

		int AIdx = 0;
		int BIdx = 0;
		int Acount = 0;
		int Bcount = 0;

		while((AIdx < ASize) && (A[AIdx] <= sec) && Acount < T)
		{
			curSec += A[AIdx++];
			Acount++;
		}

		if(BIdx < BSize && sec - curSec >= B[BIdx] && Bcount < T )
		{
			curSec += B[BIdx++];
			Bcount++;
		}

		while(sec - curSec >= 0)
		{
			if( AIdx < ASize && BIdx < BSize )
			{
				if( (A[AIdx] <= B[BIdx]) && (sec - curSec >= A[AIdx]))
				{
					curSec += A[AIdx++];
					Acount++;
				}
				else
				{
					if( sec - curSec >= B[BIdx] )
					{
						curSec+= B[BIdx++];
						Bcount++;
					}
					else
					{
						break;
					}
				}
			}
			else
			{
				break;
			}
		}

		while( AIdx < ASize && sec - curSec >= A[AIdx])
		{
				curSec += A[AIdx++];
				Acount++;
		}

		while( BIdx < BSize && sec - curSec >= B[BIdx])
		{
				curSec += B[BIdx++];
				Bcount++;
		}

		if( Acount >= T  && Bcount >=T )
			return Acount + Bcount;
		else
			return -1;
	}
};


int main()
{
	ListeningSongs LS;
	vector<int> A = {300,200,100};
	vector<int> B = {400,500,600};
	cout<<LS.listen(A,B,17,1)<<endl;

	vector<int> A1 = {300,200,100};
	vector<int> B1 = {400,500,600};
	cout<<LS.listen(A1,B1,10,1)<<endl;

	vector<int> A2 = {60,60,60};
	vector<int> B2 = {60,60,60};
	cout<<LS.listen(A2,B2,5,2)<<endl;

	vector<int> A3 = {120,120,120,120,120};	
	vector<int> B3 = {60,60,60,60,60,60};
	cout<<LS.listen(A3,B3,10,3)<<endl;

	vector<int> A4 = {196,147,201,106,239,332,165,130,205,221,248,108,60};
	vector<int> B4 = {280,164,206,95,81,383,96,255,260,244,60,313,101};
	cout<<LS.listen(A4,B4,60,3)<<endl;

	vector<int> A5 = {100,200,300};
	vector<int> B5 = {100,200,300};
	cout<<LS.listen(A5,B5,2,1)<<endl;

	vector<int> A6 = {100,200,300,400,500,600};
	vector<int> B6 = {100,200};
	cout<<LS.listen(A6,B6,1000,3)<<endl;
}

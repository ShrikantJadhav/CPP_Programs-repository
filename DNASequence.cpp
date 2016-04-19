#include<iostream>

using namespace std;

class DNASequence
{
	public:
		int longestDNASequence(string strSequence)
		{
			int nMax = 0;
			int nCur = 0;
			for(int i = 0; i < strSequence.length();++i)
			{
				if( (strSequence[i] == 'A') ||
					(strSequence[i] == 'C') ||
					(strSequence[i] == 'G') ||
					(strSequence[i] == 'T' ))
				{
					nCur += 1;
					if( nCur > nMax )
					{
						nMax = nCur;
					}
				}
				else
				{
					nCur = 0;
				}
			}
			return nMax;
		}
};

int main()
{
	DNASequence ds;
	cout<<ds.longestDNASequence("TOPBOATER")<<endl;
	cout<<ds.longestDNASequence("SUSHI")<<endl;
	cout<<ds.longestDNASequence("GATTACA")<<endl;
	cout<<ds.longestDNASequence("GOODLUCK")<<endl;
	cout<<ds.longestDNASequence("VVZWKCSIQEGANULDLZESHUYHUQGRKUMFCGTATGOHMLKBIRCA")<<endl;
}

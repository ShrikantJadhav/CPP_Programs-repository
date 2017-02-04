#include <iostream>
#include <algorithm>

using namespace std;

int Istr(string strInput, int k)
{
	int count[26];
	int max;

	for(int i = 0 ; i < 26; ++i)
		count[i] = 0;	

	size_t length = strInput.size();
	for(size_t i = 0 ; i < length; ++i)
	{
		int indx = (int)strInput[i] - 97 ;
		count[indx]++;
		if( count[indx] > max)
			max = count[indx];
	}

	int sum = 0;

	for(int i = 0; i < k; i++)
	{
		int ind = -1;
		int maxValue = 0;
		for( int i = 0; i < 26; ++i)
		{
			if( count[i] > maxValue )
			{
				ind = i;
				maxValue = count[i];
			}
		}
		count[ind]--;
	}

	for( int i = 0 ; i < 26; ++i)
	{
		sum += (count[i] * count[i]);
	}
	return sum;
}

int main()
{
	cout<<Istr("abacaba",1)<<endl;
	cout<<Istr("aba",1)<<endl;
	cout<<Istr("abacaba",0)<<endl;
	cout<<Istr("abacaba",3)<<endl;
	cout<<Istr("abc",3)<<endl;
	cout<<Istr("wersrsresesrsesrawsdsw",11)<<endl;
}

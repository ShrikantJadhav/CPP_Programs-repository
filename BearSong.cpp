#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class BearSong
{
	public:
	int countRareNotes(vector<int> Notes)
	{
		sort(Notes.begin(), Notes.end());

		int count = 0;
		size_t n = Notes.size();
		for(size_t i = 0; i < Notes.size(); ++i)
		{
			if( (i >0 && Notes[i] == Notes[i-1]) ||
				(i < n-1 && Notes[i] == Notes[i+1]))
			{
				count++;
			}
		}

		return n - count;
	}
};


int main()
{
	BearSong BS;
	vector<int> A = {9,10,7,8,9};
	cout<<BS.countRareNotes(A)<<endl;

	vector<int> A1 = {8,8,7,6,7,3,5,10,9,3};
	cout<<BS.countRareNotes(A1)<<endl;

	vector<int> A2 = {234,462,715,596,906};
	cout<<BS.countRareNotes(A2)<<endl;

	vector<int> A3 = {17};
	cout<<BS.countRareNotes(A3)<<endl;

	vector<int> A4 = {1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,
			1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,
			1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000};
	cout<<BS.countRareNotes(A4)<<endl;
	return 0;
}

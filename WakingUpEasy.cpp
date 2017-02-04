#include<iostream>
#include<vector>

using namespace std;

class WakingUpEasy
{
	public:
		int countAlarms(vector<int> volume, int S)
		{
			int n = 0;
			while( S > 0)
			{
				for(int i = 0; i < volume.size(); ++i)
				{
					S = S - volume[i];
					n++;
					if( S <= 0)
						return n;
				}
			}
			return n;
		}
};

int main()
{
	WakingUpEasy WUE;
	vector<int> v1 = {5,2,4};
	cout<<WUE.countAlarms(v1,13)<<endl;
	cout<<WUE.countAlarms(v1,3)<<endl;

	vector<int> v2 = {1};
	cout<<WUE.countAlarms(v2,1000)<<endl;

	vector<int> v3 = {42, 68, 35, 1, 70, 25, 79, 59, 63, 65, 6, 46, 82, 28, 62, 92, 96, 43, 28, 37,
			  92, 5, 3, 54, 93, 83, 22, 17, 19, 96, 48, 27, 72, 39, 70, 13, 68, 100, 36,
			    95, 4, 12, 23, 34, 74, 65, 42, 12, 54, 69};
	cout<<WUE.countAlarms(v3,9999)<<endl;
}

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct SortByY
{
		bool operator()(std::pair<int,int> x, std::pair<int,int> y)
		{
				return x.second != y.second? x.second < y.second:x.first < y.first;
		}
};

class CatchTheBeatEasy
{
		public:
				string ableToCatcheAll(vector<int> X, vector<int> Y)
				{
						int n = X.size();

						vector<std::pair<int,int> > vecPoints;
						for(int i =0 ; i < n; ++i)
						{
								vecPoints.push_back(make_pair(X[i],Y[i]));
						}

						sort(vecPoints.begin(), vecPoints.end(), SortByY());

						int x0 = 0, y0 = 0;
						for (int i = 0; i < n; i++) 
						{
							int x1 = vecPoints[i].first;
							int y1 = vecPoints[i].second;
							if (abs(x1 - x0) > y1 - y0)
						   	{
								return "Not able to catch";
						    }
							x0 = x1;
							y0 = y1;
						}	
					return "Able to catch";
					
				}
};

int main()
{
	CatchTheBeatEasy CT;
	vector<int> V1 = {70,-108,52,-70,84,-29,66,-33};
	vector<int> V2 = {141,299,402,280,28,363,427,232};
	cout<<CT.ableToCatcheAll(V1,V2)<<endl;

	vector<int> V3 = {-175,-28,-207,-29,-43,-183,-175,-112,-183,-31,-25,-66,-114,-116,-66};
	vector<int> V4 = {320,107,379,72,126,445,318,255,445,62,52,184,247,245,185};
	cout<<CT.ableToCatcheAll(V3,V4);
	return 0;
}

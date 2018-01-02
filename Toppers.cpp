#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<iterator>

using namespace std;

bool sortPair(pair<int,int> x,
              pair<int,int> y)
{
  if( x.second > y.second )
    return true;
  else 
    return false;
}

int main()
{
  int T = 0;
  cin>>T;

  while( T > 0)
  {
    int N = 0;
    cin>>N;

    vector<std::pair<int,int> > vecPairRollNMarks(N,make_pair(0,0));

    for(int i = 0; i < N; ++i )
    {
      int marks = 0;
      cin>>marks;
      vecPairRollNMarks[i] = make_pair(i,marks);
    }

    for(int i = 0; i < N; ++i)
    {
      cout<<"i : "<<i <<"; Marks:"<<vecPairRollNMarks[i].second<<endl;
    }

    cout<<endl;

    int k;
    cin>>k;
    sort(vecPairRollNMarks.begin(),vecPairRollNMarks.end(),sortPair);
    for(int i = 0; i < N; ++i)
    {
      cout<<"i : "<<i <<"; Marks:"<<vecPairRollNMarks[i].second<<endl;
    }

    for(int i = 0; i < k; ++i )
    {
      cout<<vecPairRollNMarks[i].first<<" ";
    }
    cout<<endl;
    T--;
  }
  return 0;
}

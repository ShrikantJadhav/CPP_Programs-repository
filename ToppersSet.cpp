#include<iostream>
#include<set>
#include<utility>

using namespace std;

struct comparePairs
{
public:
  bool operator()(const pair<int,int>& x,
                 const pair<int,int>& y)
  {
    return (x.second > y.second)?true:false;
  }
};

int main()
{
  int T = 0;
  cin>>T;

  while( T > 0 )
  {
    int N = 0;
    cin>>N;

    multiset<pair<int,int>,comparePairs> setMarks;
    for(int i = 0; i < N; ++i)
    {
      int marks;
      cin>>marks;

      setMarks.insert(make_pair(i,marks));
    }
    for( const auto& itr : setMarks )
    {
      cout<<itr.first<<" "<<itr.second<<endl;
    }

    int k = 0;
    cin>>k;

    for( const auto& itr : setMarks )
    {
      cout<<itr.first<<" ";
      --k;
      if( k == 0 )
        break;
    }
    cout<<endl;
    --T;
  }
}

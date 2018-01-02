#include<iostream>
#include<set>

using namespace std;

class StudentRecord
{
public:
  int m_rollNum;
  int m_marks;

  bool operator<(const StudentRecord& st) const
  {
    return (this->m_marks > st.m_marks)?true:false;
  }
};


int main()
{
  int T = 0; cin>>T;

  while( T > 0 )
  {
    int N; cin>>N;
    set<StudentRecord> st;

    for(int i = 0 ; i < N; ++i)
    {
      StudentRecord str;
      str.m_rollNum = i;
      cin>>str.m_marks;
      st.insert(str);
    }

    for(const auto& itr : st)
    {
      cout<<itr.m_rollNum<<" "<<itr.m_marks<<endl;
    }

    int k; cin>>k;
    for(const auto& itr : st)
    {
      cout<<itr.m_rollNum<<" ";
      --k; if( k <= 0) break;
    }
    cout<<endl;
    --T;
  }
}

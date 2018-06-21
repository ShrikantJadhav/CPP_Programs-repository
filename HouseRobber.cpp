//House robber prblem from leetcode

#include<iostream>
#include<vector>

using namespace std;

class Solution {

public:

    int rob(vector<int>& A) {

	if(A.size() == 0) return 0;
	int max  = A[0];
	int maxExcluding = 0;

	for(int  i = 1; i < A.size(); ++i)
	{
	    int tmp = max;
	    if( A[i] + maxExcluding > max)
	    {
		max = A[i] + maxExcluding;
	    }
	    maxExcluding = tmp;
	}
	return max;
    }
};

int main()
{
    Solution s;
    vector<int> v{1,2,3,1};
    cout<<s.rob(v)<<endl;

    vector<int> v1{2,7,9,3,1};
    cout<<s.rob(v1)<<endl;

    return 0;
}

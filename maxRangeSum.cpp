//RangeSum problem leetcode
#include<iostream>
#include<vector>

using namespace std;

class NumArray {
public:
    NumArray(vector<int> nums) {
	m_size = nums.size();
	m_sum.resize(m_size,0);

	int prev = 0;
	for(int i = 0; i < m_size; ++i)
	{
	    m_sum[i] = nums[i] + prev;
	    prev = m_sum[i];
	}
    }

    int sumRange(int i, int j) {
	if( i > 0 && j < m_size)
	{
	    return m_sum[j] - m_sum[i-1];
	}
	else
	{
	    if( i == 0 && j < m_size )
	    {
		return m_sum[j];
	    }
	    else
	    {
		return -1;
	    }
	}
    }
private:
    vector<int> m_sum;
    size_t m_size;
};


int main()
{
    vector<int> nVec{-2,0,3,-5,2,-1};
    NumArray A(nVec);
    cout<<A.sumRange(0,2)<<endl;
    cout<<A.sumRange(2,5)<<endl;
    cout<<A.sumRange(0,5)<<endl;
    return 0;
}

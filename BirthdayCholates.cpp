#include <bits/stdc++.h>
#include <vector>
#include <iostream>

using namespace std;

int solve(int n, vector < int > s, int d, int m){
    vector<int> sum(n,0);

    sum[0] = s[0];
    for(size_t i = 1; i < s.size(); ++i)
    {
	sum[i] = sum[i-1] + s[i];
    }

    int count = 0;
    if( sum[m-1] == d) count++;
    for(int i = m; i < n; ++i)
    {
	if( (sum[i] - sum[i-m]) == d)
	    count++;
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    vector<int> s(n);
    for(int s_i = 0; s_i < n; s_i++){
	cin >> s[s_i];
    }
    int d;
    int m;
    cin >> d >> m;
    int result = solve(n, s, d, m);
    cout << result << endl;
    return 0;
}


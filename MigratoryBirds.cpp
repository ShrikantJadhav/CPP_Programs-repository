#include <bits/stdc++.h>
#include <vector>
#include <iostream>

using namespace std;

int migratoryBirds(int n, vector <int> ar) {
    vector<int> count(5,0);
    int maxInd = 0;
    int max=0;

    for(const auto& i : ar)
    {
	count[i-1]++;
	if( count[i-1] > max)
	{
	    max = count[i-1];
	    maxInd = i;
	}
	else
	{
	    if( count[i-1] == max && i < maxInd)
	    {
		maxInd = i;
	    }
	}
    }
    return maxInd;
}

int main() {
    int n;
    cin >> n;
    vector<int> ar(n);
    for(int ar_i = 0; ar_i < n; ar_i++){
	cin >> ar[ar_i];
    }
    int result = migratoryBirds(n, ar);
    cout << result << endl;
    return 0;
}

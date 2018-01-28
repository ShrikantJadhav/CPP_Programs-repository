#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector <int> breakingRecords(vector <int> score) 
{
    int best = numeric_limits<int>::min();
    int worst = numeric_limits<int>::max();
    int bestBeaten = -1;
    int worstBeaten = -1;
    for(size_t i = 0; i < score.size(); ++i)
    {
	if( score[i] > best )
	{
	    best = score[i];
	    bestBeaten++;
	}
	if( score[i] < worst )
	{
	    worst = score[i];
	    worstBeaten++;
	}
    }

    vector<int> v(2,0);
    v[0] = bestBeaten;
    v[1] = worstBeaten;

    return v;
}

int main() 
{
    int n;
    cin >> n;
    vector<int> score(n);
    for(int score_i = 0; score_i < n; score_i++){
	cin >> score[score_i];
    }
    vector <int> result = breakingRecords(score);
    for (ssize_t i = 0; i < result.size(); i++) {
	cout << result[i] << (i != result.size() - 1 ? " " : "");
    }
    cout << endl;


    return 0;
}


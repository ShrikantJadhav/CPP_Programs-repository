#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

string solve(int year){
    vector<int> days{31,28,31,30,31,30,31,31,30,31,30,31};
    vector<string> months{"01","02","03","04","05","06","07","08","09","10","11","12"};;

    int numOfDays = days[0];
    if( ((year >= 1919) && 
		((year % 400 == 0) || (( year % 4 == 0) && ( year % 100 != 0 )))) ||
	    ( year < 1918 && year % 4 == 0))
    {
	numOfDays += days[1] + 1;
    }else if( year == 1918 )
    {
	numOfDays += 15;    
    }
    else
    {
	numOfDays += days[1];
    }
    int month = 2;
    while((256 - numOfDays) > 30)
    {
	numOfDays += days[++month];
    }

    stringstream ss;
    ss<<(255 - numOfDays)<<"."<<months[month]<<"."<<year;
    return ss.str();
}

int main() {
    int year;
    cin >> year;
    string result = solve(year);
    cout << result << endl;
    return 0;
}

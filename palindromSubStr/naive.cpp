#include<iostream>
#include<string>
#include<set>
#include<iterator>

using namespace std;

//Naive approach would be to find out all substrings
//and then iterate over those to find palindromic strings.
//See other files in this directory for solution with suffix array, manchar algo, and palindromic tree

bool checkIfPalindrome(const string& str)
{
    int i = 0;
    int j = str.size() - 1;
    while( i <= j )
    {
    	if(str[i] != str[j])
    	    return false;
    	++i;
    	--j;
    }
    return true;
}


void getAllSubstrings(const string& str, set<string>& vec)
{
    int n = str.size();

    for(int i = 0; i < n; i++)
    {
    	for(int j = 0; j < n-i; ++j)
	{
	    string subStr = str.substr(i,j+1);
	    if( checkIfPalindrome(subStr) )
	    {
	    	vec.insert(subStr);
	    }
	}
    }
}

void printAllPalindromicSubstr(const string& str)
{
    //first you need find all substrings
    set<string> vecSubstr;
    getAllSubstrings(str,vecSubstr);
    copy(vecSubstr.begin(), vecSubstr.end(),
    	ostream_iterator<string>(cout," "));
}

int main()
{
    string A = "aba";
    cout<<"string = "<<A<<endl;
    printAllPalindromicSubstr(A);
    cout<<endl;

    string B = "abaab";
    cout<<"string = "<<B<<endl;
    printAllPalindromicSubstr(B);
    cout<<endl;

    string C = "abaabcc";
    cout<<"string = "<<C<<endl;
    printAllPalindromicSubstr(C);
    cout<<endl;
}

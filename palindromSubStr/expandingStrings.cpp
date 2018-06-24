#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<iterator>
#include<algorithm>

using namespace std;

void expandToCheckPalindrome(string str, int i, int j, 
			     set<string>& setPalindrome)
{
    if( i < 0 || j >= str.size() )
    	return;

    if(str[i] == str[j])
    {
    	//cout<<"Substring = "<<str.substr(i,j-i+1)<<endl;
    	setPalindrome.insert(str.substr(i,j-i+1));
    	expandToCheckPalindrome(str,i-1,j+1,setPalindrome);
    }
    return;
}

void printAllPalindromicSubstr(string str)
{
    set<string> setPalindrome;
    for(int i = 0; i < str.size(); ++i)
    {
    	expandToCheckPalindrome(str,i,i,setPalindrome);
    	expandToCheckPalindrome(str,i,i+1,setPalindrome);
    }

    copy(setPalindrome.begin(), setPalindrome.end(),
    	    ostream_iterator<string>(cout,","));	
    cout<<endl;
}

int main()
{
    string str = "abaaba";
    cout<<"String = "<<str<<" - List of all palindromic substr = ";
    printAllPalindromicSubstr(str);

    string str1 = "ababbccbb";
    cout<<"String = "<<str1<<" - List of all palindromic substr = ";
    printAllPalindromicSubstr(str1);
}

#include<iostream>

using namespace std;

void print()
{
    cout<<"Called for last argument\n"<<endl;
}

template < typename T, typename... ARGS >
void print(const T& firstArg, const ARGS&... args)
{
    cout<<firstArg<<endl;
    print(args...);
}

int main()
{
    print(1,2.3,"Shrikhand");
    return 0;
}

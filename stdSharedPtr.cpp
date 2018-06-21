#include<iostream>
#include<memory>

using namespace std;

int main()
{
	shared_ptr<int> a(new int(10));
	//cout<<a->use_count(); //Error - This throws an error, if you dont know, please understand operator->()
}

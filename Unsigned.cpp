#include<iostream>

//Expressions that mix signed and unsigned values can yield surprising results
//All signed values are converted to unsigned value
using namespace std;

int main()
{
	unsigned int a = -1;
	int b = -1;
	
	cout<<a * b<<endl;

	unsigned int u = 10 , u2 = 42;
	cout<<u2-u<<endl;
	cout<<u - u2<<endl;
	
	int i = 10, i2 = 42;
	cout<< i2 - i<<endl;
	cout<< i - i2<<endl;

	cout<< i - u<<endl;
	cout<< u - i <<endl;
}

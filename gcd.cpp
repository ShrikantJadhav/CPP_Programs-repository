#include<iostream>
#include <assert.h>

using namespace std;

int gcd( int a, int b)
{
	if( b == 0 ) return a;
	if( a < b) swap(a,b);
	if( a % b == 0) return b;
	return gcd(b,a%b);
}

int main()
{
	assert(gcd(4,2) == 2);
	assert(gcd(10,4) == 2);
	assert(gcd(4,3) == 1);
	assert(gcd(2,4) == 2);
	assert(gcd(225,175) == 25);
	return 0;
}

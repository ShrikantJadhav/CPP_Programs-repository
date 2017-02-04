#include<iostream>
#include<thread>
#include<mutex>

using namespace std;

int num = 1;
mutex mut;

int getNextNumber()
{
	lock_guard<mutex> lck(mut);
	num++;
	if(num > 10000)
		return -1;
	return num;
}

bool isPrime(int n)
{
	if( n == 1) return false;
	if( n == 2) return true;

	if( n % 2 == 0) return false;

	for(int i = 3; i * i <= n ; i+=2)
	{
		if( n % i == 0)
			return false;
	}
	return true;
}

void run(int Tid)
{
	int n = 0;
	while( (n = getNextNumber()) != -1)
	{
			if( isPrime(n) )
			{
				cout<<"Found by thread Id: "<<Tid<< " - Prime - "<<n<<endl;
			}
	}
}


int main()
{
	thread t1(run,1);
	thread t2(run,2);
	
	t1.join();
	t2.join();
	return 0;
}

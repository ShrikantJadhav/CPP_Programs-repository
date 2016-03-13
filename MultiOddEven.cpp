#include<iostream>
#include<thread>
#include<condition_variable>
#include<chrono>
#include<ctime>

using namespace std;

mutex m;
condition_variable cv;

int n; //global data

void printEven()
{
	chrono::time_point<chrono::system_clock> start,end;
	start = chrono::system_clock::now();
	unique_lock<mutex> ul(m);
	while(n < 110000)
	{
		while(n%2 != 0 )
		cv.wait(ul);
		//cout<<"Print Even : "<<n<<endl;
		n++;
		cv.notify_all();
	}
	end = chrono::system_clock::now();

	chrono::duration<double> elapsed = end - start;
	cout<<"Print Even Elapsed time : "<<elapsed.count()<<endl;

}

void printOdd()
{
	chrono::time_point<chrono::system_clock> start,end;
	start = chrono::system_clock::now();
	unique_lock<mutex> ul(m);
	while(n < 110000)
	{
		while(n % 2 == 0)
		cv.wait(ul);
		//cout<<"Print Odd : "<<n<<endl;
		n++;
		cv.notify_all();
	}
	end = chrono::system_clock::now();
	chrono::duration<double> elapsed = end - start;
	cout<<"Print odd Elapsed time : "<<elapsed.count()<<endl;
}

int main()
{
	n = 1;
	thread t1(printEven);
	thread t2(printOdd);

	t1.join();
	t2.join();

	chrono::time_point<chrono::system_clock> start,end;
	start = chrono::system_clock::now();
	n = 0;
	while(n < 110000)
	{
		if( n % 2 == 0 )
		{
		//cout<<"Print : "<<n<<endl;
		}
		n++;
	}
	end = chrono::system_clock::now();
	chrono::duration<double> elapsed = end - start;
	cout<<"Elapsed time without threading: "<<elapsed.count()<<endl;

	return 0;	
}

#include <iostream>
#include <thread>

using namespace std;


int main()
{
    int forks[5];
    thread t[5];

    for(int i = 0; i < 5; ++i)
    {
        t = new thread(processPhilosopherActions,i);
    }
    return 0;
}


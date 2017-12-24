#include<iostream>
#include<chrono>
#include<thread>
#include<cstdlib>
#include<string>

using namespace std;


int main()
{
    string chars="abcdefgghijklmnopqrstuvwxyz1234567890~!@#$%^&*()-=_+,./<>?:;{}[]|";
    int l = chars.length();

    int lineWidth = 80;
    bool skipChars[lineWidth];
    fill(skipChars,skipChars+lineWidth,false);

    while(1)
    {
        for(int i = 0; i < lineWidth ; ++i)
        {
            if( skipChars[i] )
            {
                cout<<"  ";
            }
            else
            {
                char c = chars[(rand() % l)];
                cout<<"\033[1;32m"<<c<<" ";
            }
        }
        for(int i = 0; i < 10; ++i)
        {
            int num = (rand() % lineWidth);
            skipChars[num] = !skipChars[num];
        }
        cout<<endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    return 0;
}

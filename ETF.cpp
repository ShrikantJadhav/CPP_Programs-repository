#include<iostream>

using namespace std;

int getETF(int n)
{
    int ret = n;

    for(int i = 2; i * i <= n; ++i)
    {
        if( n % i == 0 )
        {
            while( n % i == 0)
            {
                n = n / i;
            }
            ret = ret - ret/i;  
        }
        
    }
    if( n > 1)
        ret -= ret/n;
    return ret;

}

int main()
{
    int T;
    cin>>T;

    for(int i = 0; i < T; ++i)
    {
        int n;
        cin>>n;
        cout<<getETF(n)<<endl;
    }
}
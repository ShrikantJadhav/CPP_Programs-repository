#include<iostream>
using namespace std;
int getMedian(int tmp[], int lb, int ub){
    cout<<"\n Inputs to getMedian = "<<lb <<"  " <<ub;
    return ((lb + ub)/2);
}

int max(int a, int b){
    if( a <= b){
        return b;
    }
    else
    {
        return a;
    }
}
void findMedian(int a[] , int b[],int n){


    cout<<endl;
    for (int p = 0 ; p< n;p++){
        cout<<" a["<<p<<"]="<<a[p];
    }

    cout<<endl;
    for (int p = 0 ; p< n;p++){
        cout<<" b["<<p<<"]="<<b[p];
    }
    int median_a = getMedian(a,0,n);
    int median_b = getMedian(b,0,n);
    cout<<"\n\n\nValue of n = " << n;
    cout<<"\nMedian_a = :" <<median_a <<" = " << a[median_a] <<"\nMedian_b = :" <<median_b <<" = " << b[median_b];

    if(a[median_a] < b[median_b]){
        //That means median of merged array lies in second part of a and first part of b
        median_a = getMedian(a,median_a,n);
        median_b = getMedian(b,0,median_b);
        n = max((n - median_a),median_b) + 1;
        cout<<"\nNew value of n = :" << n;

        cout<<"\nIF part - \nMedian_a = :" <<median_a <<" = " << a[median_a] <<"\nMedian_b = :" <<median_b <<" = " << b[median_b];

        if( median_a == n || median_b == 0)
        {
            cout<<"\nmedian of sorted array: " << a[median_a];
            cout<<"\nmedian of sorted array: " << b[median_b];
            return;
        }
        findMedian(a + (median_a - 1),b,n);
    }
    else{
        //That means median of merged array lies in first part of a and second part of b

        median_a = getMedian(a,0,median_a);
        median_b = getMedian(b,median_b,n);
        cout<<"\nElse part - \nMedian_a = :" <<median_a <<" = " << a[median_a] <<"\nMedian_b = :" <<median_b <<" = " << b[median_b];
        n = max((n - median_a),median_b) + 1;
        cout<<"\nNew value of n = :" << n;

        if( median_b == n || median_a == 0){
            cout<<"\nmedian of sorted array: " << a[median_a];
            cout<<"\nmedian of sorted array: " << b[median_b];
            return;
        }
        findMedian(a,b + (median_b - 1),n);
    }
}

int main(int argc, char* argv[]){
    int a[8] = {1,9,14,64,78,999,2345,3452};
    int b[8] = {2,10,15,65,99,1234,7890,10000};
    cout<<" 1,2,9,10,14,15,64,65,78,99,999,1234,2345,7890";

    int n = 8; //Both the arrays are of size n
    findMedian(a,b,n-1);
}

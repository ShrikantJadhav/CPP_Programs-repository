#include<iostream>

using namespace std;

int binarySearch(char a[],int lb, int ub){

    int mid = (lb+ub)/2;
    if(lb == ub){
        return lb;
    }
    if(a[mid] == '$')
    {
        ub = mid -1;
    }
    else
    {
        lb = mid + 1;
    }
    return binarySearch(a,lb,ub);
}

int findInInfiniteSeries(char a[],int n){
    char special='$';
    int i = 1;
    int k = 1;
    while(a[i-1] != '$' && i < n){
            //cout<<a[i]<<endl;
            k = i;
            i = i * 2;  //check chars at 2^n posistion.
        }
    //do binary search between a[k] to a[i]
    return binarySearch(a,k,i);
}

int main(){
    char a[]={'1','2','3','4','5','6','7','8','9','1','1','4','5','$','$','$','$','$','$','$','$','$'};
    int n = sizeof(a)/sizeof(a[0]);
    cout<<n;
    cout<<endl<<"$ found at " <<findInInfiniteSeries(a,n);
}

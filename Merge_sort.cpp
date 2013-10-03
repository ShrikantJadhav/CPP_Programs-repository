#include<iostream>

using namespace std;

int merge_items(int a[],int lb, int mid, int ub){
    int start1 = lb;
    int start2 = mid +1 ;

    while(start1<=mid && start2<=ub){
        if(a[start1] > a[start2]){
            swap(a[start1],a[start2]);
        }
        start1++;
    }
}

int merge_sort(int a[],int lb , int ub){
    if(lb < ub){
        int mid = (lb + ub)/2;
        merge_sort(a,0,mid);
        merge_sort(a,mid+1,ub);
        merge_items(a,lb,mid,ub);
    }
}

int main()
{
    int a[15] = {3,2,11,14,16,5,7,19,8,10,4,1,18,9,6};

    int n = sizeof(a)/sizeof(a[0]);
    merge_sort(a,0,n-1);

    cout<<"Output:";
    for(int i = 0; i< n;i++){
        cout<<a[i]<<" ";
    }
}

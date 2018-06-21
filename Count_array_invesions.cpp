#include<iostream>

using namespace std;

int count = 0;
void merge(int a[],int low, int mid, int high){
        int n = high - low + 1;
        int temp[n];
        int rStart = mid+1;
        int i = low;
        int k = 0;

        while(low <= mid && rStart<= high){
                if(a[low] <= a[rStart]){
                        temp[k] = a[low];
                        low++;
                }
                else
                {
                        temp[k] = a[rStart];
                        rStart++;
                        count++;
                }
                k++;
        }

        while(low<=mid){
                temp[k++] = a[low++];
        }

        while(rStart <= high){
                temp[k++] = a[rStart++];
        }

        for(int k = 0; k<n; k++){
                a[i+k] = temp[k];
        }

        std::cout<<"\n";

        for(int k = 0; k< n ; k++){
        std::cout<<"\t"<<a[k];
    }
}

int merge_sort(int a[],int lb , int ub){
    if(lb < ub){
        int mid = (lb + ub)/2;
        merge_sort(a,0,mid);
        merge_sort(a,mid+1,ub);
        merge(a,lb,mid,ub);
    }
}

int main()
{
    int a[15] = {3,2,11,14,16,5,7,19,8,10,4,1,18,9,6};

    int n = sizeof(a)/sizeof(a[0]);
    merge_sort(a,0,n-1);

    cout<<endl<<"Array Inversion Count = "<<count;
}

#include<iostream>

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

void mergeSort(int a[], int low, int high){
        int mid;
        if(low < high){
                mid = (low + high) / 2;
                mergeSort(a,low,mid);
                mergeSort(a,mid+1,high);
                merge(a,low,mid,high);
        }
}

int main(){
    int a[10] = {10,1,15,9,4,2,6,67,3,7};

        for(int i = 0; i <= 9;i++)
    {
        std::cout<<"\t"<<a[i];
    }

    mergeSort(a,0,9);
    return 0;
}

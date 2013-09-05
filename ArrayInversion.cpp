#include<iostream>
#include<memory>

using namespace std;

int merge(int arr[], int lb, int mid, int ub){
    int i, j, k;
    int n1 = mid - lb + 1;
    int n2 =  ub - mid;
    int inv_count;

    /* create temp arrays */
    int *L = new int[n1];
    int *R = new int[n2];

    /* Copy data to temp arrays L[] and R[] */
    for(i = 0; i < n1; i++){
        L[i] = arr[lb + i];
    }
    for(j = 0; j <= n2; j++){
        R[j] = arr[mid + 1+ j];
        }

    i = 0;
    j = 0;
    k = lb;
    inv_count = 0;

    while( i < n1 && j < n2){
        if(L[i] < R[j]){
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
            inv_count = inv_count + (mid + 1 - i);
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    delete L;
    delete R;
}

int mergeSort(int a[],int lb,int ub){

    if (lb < ub){
        int mid = (lb+ub)/2;
        cout<<" lb = " << lb <<" ub = " << ub<< endl;
        inv_count = mergeSort(a,lb,mid);
        cout<<" lb = " << lb <<" ub = " << ub<< endl;
        inv_count += mergeSort(a,mid+1,ub);
        inv_count += merge(a,lb,mid,ub);
    }
    //if( lb == ub )
    //    return;

}


int main(int argc,char *argv[]){
    int a[10] = {1,5,4,3,2,6,7,10,9,8};

    int n = sizeof(a)/sizeof(a[0]);
    int count;
    cout<<"Size of n : " << n;
    count = mergeSort(a,0,n-1);

    for( int p =0 ; p< n;p++){
        cout << " " << a[p];
    }

    cout<< endl <<" Number of inversions = " << count;
    return 0;
}

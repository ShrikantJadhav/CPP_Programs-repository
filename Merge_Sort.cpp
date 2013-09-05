#include<iostream>
#include<memory>

using namespace std;

void merge(int arr[], int lb, int mid, int ub){
    int i, j, k;
    int n1 = mid - lb + 1;
    int n2 =  ub - mid;

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

    while( i < n1 && j < n2){
        if(L[i] < R[j]){
            arr[k++] = L[i++];
        }
        else
        {
            arr[k++] = R[j++];
        }
    }

    /* Copy the remaining elements of L[], if there are any */
    while (i < n1)
    {
        arr[k++] = L[i++];
    }

    /* Copy the remaining elements of R[], if there are any */
    while (j < n2)
    {
        arr[k++] = R[j++];
    }

    delete L;
    delete R;
}

void mergeSort(int a[],int lb,int ub){

    if (lb < ub){
        int mid = (lb+ub)/2;
        cout<<" lb = " << lb <<" ub = " << ub<< endl;
        mergeSort(a,lb,mid);
        cout<<" lb = " << lb <<" ub = " << ub<< endl;
        mergeSort(a,mid+1,ub);
        merge(a,lb,mid,ub);
    }
    //if( lb == ub )
    //    return;

}


int main(int argc,char *argv[]){
    int a[10] = {9,8,7,4,5,16,3,2,1,10};

    int n = sizeof(a)/sizeof(a[0]);
    mergeSort(a,0,n-1);

    cout<<"Sorted List: " << endl;

    for( int p =0 ; p< n;p++){
        cout << " " << a[p];
    }
    return 0;
}

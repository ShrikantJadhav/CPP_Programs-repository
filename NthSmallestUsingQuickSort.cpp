#include <iostream>

using namespace std;

void printArray(int a[], int n){
    cout<<"\nContent of the array : "<< endl;
    for(int i = 0; i< n ; i++){
        cout<< a[i] << " ";
    }
}

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int partition(int a[],int l, int r){
    int pivot = a[l];
    int down = l+1;
    int up = r;
    while(down <= up){
            while(pivot > a[down]){
                down++;
            }
            while(pivot < a[up]){
                up--;
            }
            cout<<"\nNew down = " << down << " New UP = " << up;
            if(down < up){
                swap(a[down],a[up]);
                printArray(a,10);
            }
            else{
                swap(a[l],a[up]);
                printArray(a,10);
                return up;
            }
    }
    printArray(a,10);
}

void quicksort(int a[],int down, int up, int s){
    if(down < up){
        int p = partition(a,down,up);
        cout<< "\nnew pivot index :" << p;
        if( s-1 == p) {
            cout<<"\n "<< s <<" smallest element is : "<< a[p];
            return;
        }
        if( s < p ){
            quicksort(a,down,p-1,s);
        }
        else{
            quicksort(a,p+1,up,s);
        }
    }
}

//int main(int argc, char * argv[]){
//    int a[10]= {10,6,3,5,2,7,4,15,13,11};
//    printArray(a,10);
//    int n = sizeof(a)/sizeof(a[0]);
//    int s = 5; //indicates 5th smallest element
//    quicksort(a,0,n-1,s);
//}


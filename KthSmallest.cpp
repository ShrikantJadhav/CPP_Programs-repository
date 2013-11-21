//Author: Shrikant Jadhav
//Program to find kth smallest element using quick sort

#include<iostream>

int partition(int a[], int lb, int ub){
        int pivot = a[lb];
        int up = ub;
        int down = lb +1 ;
		        
        while(down < up){
                while(pivot > a[down] && down <= ub){
                        down++;
                }

                while(pivot < a[up] && up >= lb){
                        up--;
                }

                if(up > down){
                        int temp = a[up];
                        a[up] = a[down];
                        a[down] = temp;
                }
        }

        int temp = a[lb];
        a[lb] = a[up];
        a[up] = temp;
        return up;
}

void ModifiedQuickSort(int a[],int lb,int ub, int search, int &retValue){
	int pivot = 0; 
	if(lb < ub){
		pivot = partition(a,lb,ub);
		if(pivot == search - 1){
			retValue = pivot;
		}
		else{
			if( pivot > search-1){
				ModifiedQuickSort(a,lb,pivot - 1,search,retValue);
			}
			if(pivot < search-1){
				ModifiedQuickSort(a,pivot + 1,ub, search,retValue);
			}
		}
	}
}


int kthSmallest(int a[], int n, int search){
	bool flag = false;
	int *temp = new int[n];
	for(int i = 0;i< n;i++){
		temp[i] = a[i];
	}
	int retVal = -1;
	ModifiedQuickSort(temp,0,n-1,search,retVal);

	if(retVal == -1){
		retVal = search - 1;
	}

	retVal = temp[retVal];
	delete temp;
	return retVal;
}


int main(){
	int a[15] = {100,2,200,5,1,75,205,34,89,87,77,68,90,98,77};
	std::cout<<"4th Smallest element is :"<<kthSmallest(a,15,4);
	
	std::cout<<"\n1st Smallest element is :"<<kthSmallest(a,15,1);
		
	std::cout<<"\n9th Smallest element is :"<<kthSmallest(a,15,9);

	std::cout<<"\n12th Smallest element is :"<<kthSmallest(a,15,12);

	std::cout<<"\n15th Smallest element is :"<<kthSmallest(a,15,15);

	return 0;
}

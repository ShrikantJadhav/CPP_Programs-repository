//Too inefficient -  o(n^2) complexity
#include<iostream>

class QuickFindUF{
private:
	int *a;
	int n;
public:
	QuickFindUF(int N);
	~QuickFindUF();
	bool isConnected(int p, int q);
	void Union(int p, int q);
	void printSet();
	void print();
};

QuickFindUF::QuickFindUF(int N){
	a = new int[N];
	for(int i = 0; i < N;i++){
		a[i] = i;
	}
	n = N;
}

void QuickFindUF::print(){
	for(int i = 0 ; i< n;i++){
		std::cout<<"\t"<<a[i];
	}
}

QuickFindUF::~QuickFindUF(){
	delete[] a;
}

bool QuickFindUF::isConnected(int p, int q){
	return (a[p] == a[q]);
}

void QuickFindUF::Union(int p, int q){
	int former = a[p];
	int lateral = a[q];
	for(int i = 0 ; i < n;i++){
		if(a[i] == former){
			a[i] = lateral;
		}
	}
}

void QuickFindUF::printSet(){
	std::cout<<std::endl;
	int *q;
	q = new int[n];

	for(int i = 0; i < n;i++){
		q[i] = 0;
	}

	for(int i = 0; i < n ;i++){
		if(q[i] != 1){
			int searchFor = a[i];
			std::cout<<" { ";
			for(int j = i; j < n; j++){
				if(searchFor == a[j]){
					q[j] = 1;
					std::cout<<" " << j << " ";
				}
			}
			std::cout<<" } ";
	}
}
		
	delete[] q;
}

int main(){
	QuickFindUF q(10);
	q.printSet();
	q.Union(9,8);
	std::cout<<"\n\nPerform : Union of 3 & 4:";
	q.printSet();
	q.Union(1,3);
	std::cout<<"\n\nPerform : Union of 4 & 8:";
	q.printSet();
	q.Union(4,1);
	q.Union(7,0);
	q.Union(5,0);
	q.Union(9,4);
	q.print();
	std::cout<<"\n\nPerform : Union of 5 & 6:";
	q.printSet();
	std::cout<<"\nIf 3 and 8 are connected:";
	q.isConnected(3,8) == true ?std::cout<<"Yes":std::cout<<"No";

	int i;
	std::cin>>i;
}

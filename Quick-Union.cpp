//Efficient than Quick-Find, Find and union operation takes linear time
#include<iostream>

class QuickUnion{
private:
	int *a;
	int n;
public:
	QuickUnion(int N);
	~QuickUnion();
	void Union(int p, int q);
	bool isConnected(int p,int q);
	void print();
};

QuickUnion::QuickUnion(int N){
	a = new int[N];
	n = N;
	
	for(int i = 0; i < n;i++){
		a[i] = i;
	}
}

QuickUnion::~QuickUnion(){
	delete[] a;
}

void QuickUnion::Union(int p, int q){
	// Assign the value of p as parent of a[q]
	a[q] = p;
}

bool QuickUnion::isConnected(int p,int q){
	//check if root of p and q is same, if yes then return true else return false
	std::cout<<"\n"<<p << "=" <<a[p]<<" "<<q << " = " <<a[q];

	if(a[p] == q || a[q] == p){
		return true;
	}
	else
	{
		if(a[p] == p){ // p is the root
			return this->isConnected(p,a[q]);
		}
		else{
				if(a[q] == q){ // q is the root
					return this->isConnected(a[p],q);
				}
				else{
					return this->isConnected(a[p],a[q]);
				}
		}
	}
}

void QuickUnion::print(){
	std::cout<<"\n";
	for(int i = 0 ; i< n;i++){
		std::cout<<" "<<a[i];
	}
}

int main(){
	QuickUnion q(10);
	q.print();
	q.Union(3,4);
	std::cout<<"\n\nPerform : Union of 3 & 4:";
	q.print();
	q.Union(4,8);
	std::cout<<"\n\nPerform : Union of 4 & 8:";
	q.print();
	q.Union(5,6);
	std::cout<<"\n\nPerform : Union of 5 & 6:";
	q.print();
	std::cout<<"\nIf 3 and 8 are connected:";
	q.isConnected(3,8) == true ?std::cout<<"Yes":std::cout<<"No";

	int n;
	std::cin >> n;
}

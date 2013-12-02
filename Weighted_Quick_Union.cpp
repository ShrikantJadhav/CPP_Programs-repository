//Algorithm complexity - N + M * ln(N)  for find and union operations
//Efficient than quick-union, this one tries to keep length of the tree as small as possible

#include<iostream>

class WeigthedQuickUnion{
private:
	int *a;
	int *s;
	int n;
public:
	WeigthedQuickUnion(int N);
	~WeigthedQuickUnion();

	bool isConnected(int p, int q);
	void Union(int p, int q);
	int root(int p);
	void print();
};

WeigthedQuickUnion::WeigthedQuickUnion(int N){
	n = N;
	a = new int[n];
	s = new int[n];

	for(int i = 0; i< n;i++){
		a[i] = i;
		s[i] = 0;
	}
}

WeigthedQuickUnion::~WeigthedQuickUnion(){
	delete[] a;
	delete[] s;
}

int WeigthedQuickUnion::root(int p){
	if(a[p] == p){
		return p;
	}
	else
	{
		return root(a[p]);
	}
}

void WeigthedQuickUnion::Union(int p, int q){
	int root_p = root(p);
	int root_q = root(q);

	if(s[root_p] >= s[root_q]){
		a[root_q] = root_p;
	}
	else{
		a[root_p] = root_q;
	}
}

bool WeigthedQuickUnion::isConnected(int p, int q){
	return (root(p) == root(q));
}

void WeigthedQuickUnion::print(){
	std::cout<<"\n";
	for(int i = 0 ; i< n; i++){
		std::cout<<"\t"<<a[i];
	}
}


int main(){
	WeigthedQuickUnion wq(10);
	wq.print();
	wq.Union(2,3);
	wq.Union(5,4);
	wq.print();
	wq.Union(4,3);
	wq.print();
	wq.Union(3,9);
	wq.print();
	wq.Union(6,7);
	wq.print();
	wq.Union(2,7);
	wq.print();

	int n;
	std::cin>>n;
}

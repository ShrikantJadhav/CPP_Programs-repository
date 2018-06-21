#include "MySharedPointer.hpp"
#include <iostream>

using namespace std;

int main()
{
	my_shared_ptr<int> ptr(new int(10));
	cout<<"*ptr = "<< *ptr <<" Ref Count : "<<ptr.use_count()<<endl;

	{
		my_shared_ptr<int> ptr1(ptr);
		cout<<"Ref Count : " <<ptr1.use_count()<<endl;
		cout<<"Ref Count : "<<ptr.use_count()<<endl;
	}
	cout<<"Ref Count : "<<ptr.use_count()<<endl;
	return 0;
}

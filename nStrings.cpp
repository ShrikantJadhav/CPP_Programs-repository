#include<iostream>
#include<string>

std::string A("000");

void binary(int n){
    if( n < 1 )
        std::cout<<std::endl<<A;
    else{
        A[n-1]='0';
        binary(n-1);
        A[n-1]='1';
        binary(n-1);
    }
}
int main(){
    binary(3);
}

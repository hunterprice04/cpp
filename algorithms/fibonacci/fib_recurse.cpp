#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

unsigned long long fib_recurse(unsigned long long n);

int main(){
	long long num;
	cout<<"num: ";
	while(cin>>num){
		if(num<0){
			cout<<"Bad Number\n";
			continue;
		}
		cout<<"fib of "<<num<<": "<<fib_recurse(num)<<endl;
		cout<<"num: ";
	}
}


unsigned long long fib_recurse(unsigned long long n){
	if(n==0)return 0;
	if(n==1||n==2)return 1;
	return fib_recurse(n-1) + fib_recurse(n-2);
}

#include <iostream>
using namespace std;

typedef long long ll;

ll fib_dynamic(ll n);

int main(){
	ll num;
	cout<<"num: ";
	while(cin>>num){
		if(num<0){
			cout<<"Bad Number\n";
			continue;
		}
		cout<<"fib of "<<num<<": "<<fib_dynamic(num)<<endl;
		cout<<"num: ";
	}
}

// creates a cache with a small space complexity then dynamically computes the fibonacci number
ll fib_dynamic(ll n){
    // create the cache
    ll cache[3] = {0,1,1};

    // base cases
    if(n==0) return cache[0];
    if(n==1) return cache[1];
    if(n==2) return cache[2];

    // loops until the nth number of the fibonacci sequence has beem computed
    int i = 3;
    while (i <= n) {
        // shifts the numbers down the array then calculates the third index of the cache
        cache[0] = cache[1];
        cache[1] = cache[2];
        cache[2] = cache[0] + cache[1];
        i++;
    }
    return cache[2];
}
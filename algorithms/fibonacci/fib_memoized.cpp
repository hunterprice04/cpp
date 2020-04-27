/* Hunter Price 
 * 11/26/29
 * This is my first attempt at memoization. Finds the fibonacci value of the 
 * value the user passes.
 */
#include <iostream>
#include <vector>
using namespace std;

unsigned long long fib_memoized(unsigned long long n, vector<unsigned long long>&save);

int main(){
  /* declare variables */
  unsigned long long num, i;
  vector<unsigned long long>cache;

  /* set first two values of fib sequence */
  cache.resize(2,0);
  cache[1]=1;
  cout<<"num: ";

  /* while the user has values find fib for given value */
  while(cin>>num){
    if(num<0){ /* if the given number is less than zero */
      cout<<"Bad Number\n";
      continue;
    }

    if(num>=cache.size()){  /* if the value is larger than the size of the cache resize the cache */
      cache.resize(num+1,-1);
    }else if(cache[num]!=-1){  /* if the value is already in the cache return fib of the value */
      cout<<"fib of "<<num<<": "<<cache[num]<<endl;
      cout<<"num: ";
      continue;
    }

    /* When numbers larger than 100,000 are passed to the function and 
     * the cache has not been built up, the program will segfault.
     * This is due to the amount of available stack space. Without the cache being 
     * built up the program will call over 100,000 recursive calls until it fills
     * the stack space resulting in a seg fault. This if statement checks if the number
     * is large enough and its not stored in the cache then it will build the cache up to the 
     * number to avoid filling up the stack space.
     */
    if(num>100000&&cache[num]==-1){
      for(i=100000;i<num-(num%100000);i+=100000)fib_memoized(i,cache);
    }

    /* if reaches this portion of the loop call recursive function and print out the fib */
    cout<<"fib of "<<num<<": "<<fib_memoized(num,cache)<<endl;
    cout<<"num: ";
  }
}

/* recursive memoization function to find fib of n. takes the a number n and a vector of saved fib
 * values by reference */
unsigned long long fib_memoized(unsigned long long n, vector<unsigned long long>&save){
  if(save[n] == -1){ /* if the current n has not been found find the n and add it to the cache */
    save[n] = fib_memoized(n-1,save) + fib_memoized(n-2,save);
  }
  return save[n]; /* return the value at the location n in the cache */
}

// Hunter Price
// This program determines if a users inputted number is a prime number 
// uses a brute force approach to calculate if it is a prime

#include <iostream>
#include <string>
#include <math.h>
#include <sstream>
using namespace std;

bool is_prime(long long & N);


int main(int argc, char **argv){
    // declare variables
    long long N;
    string input;
    stringstream ss;

    // loop until the user types q
    while(1){
        // read in user input and assigns it to the correct variables
        ss.clear();
        cout << "Enter Number to find if it is prime (q to quit): ";
        cin >> input;

        // case to quit program
        if(input[0]=='q')break;

        // if the input is not a number continue to the top of the loop
        ss.str(input);
        if(!(ss>>N))continue;

        // computes if prime and prints the result
        if(is_prime(N)) cout << N << " is prime.\n";
        else cout << N << " is not prime.\n";
    }

    return 0;
}

// determines if the number N is prime 
bool is_prime(long long &N){
    // loops from 2 to the sqrt of N
    // if any number divided evenly into N the number is not prime
    for ( long long i = 2; i <= sqrt(N); i++){
        if (N%i==0) return false;
    }
    return true;
}
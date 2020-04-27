// Hunter Price
// This program computes the greatest common divisor of the two
// user inputted values using Euclids algorithm

#include <iostream>
#include <string>
#include <math.h>
#include <sstream>
using namespace std;

long long greatest_common_divisor(long long x, long long y);


int main(int argc, char **argv){
    // declare variables
    long long x,y;
    string input;
    stringstream ss;

    // loop until the user types q
    while(1){
        // read in user input and assigns it to the correct variables
        ss.clear();
        cout << "Enter two numbers seperated by a space to find the gcd(q to quit): ";
        getline(cin,input);

        // case to quit program
        if(input[0]=='q')break;

        // if the input is not two numbers continue to the top of the loop
        ss.str(input);
        if(!(ss>>x>>y))continue;

        // computes the greatest common divisor
        cout << "gcd(" << x << ',' << y << ") = " << greatest_common_divisor(x,y) << endl;
    }

    return 0;
}

// computes and returns the greatest common divisor using Euclid's algorithm
long long greatest_common_divisor(long long x, long long y){
    // declare variables
    long long r; 
    
    // insure y is greater than x
    if ( y < x ) swap(x,y);
    
    // assigns r to the remained of y mod x
    r = y % x;

    // loop until the remainder is 0
    while ( r != 0 ){
        y = x;
        x = r;
        r = y % x;
    }
    
    // return x. the final value of x is the gcd
    return x;
}
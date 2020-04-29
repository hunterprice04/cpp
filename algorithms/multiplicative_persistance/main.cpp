#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

int mult_pers(ll n,int verbose){
    int i, num_steps = 0;
    string str_n;
    cout << "--------------------\n";
    while(n>10){
        if(verbose)cout << n << endl;
        str_n = to_string(n);
        n = 1;
        for(i = 0 ; i < str_n.length() ; i++){
            n *= stoi(to_string(str_n[i])) - '0';
        }
        num_steps++;
    }   
    if(verbose)cout << n << endl;
    cout << "--------------------\n";
    return num_steps;
}

int main(){
    string str;
    ll n;
    cout << "Enter a number to find its multipilcative persistance\n";
    cout << "q or Q to quit\n";
    cout << "====================\n";
    while (cin >> str){
        if(str == "q"||str == "Q")break;
        try{
            n = stoi(str);
            int steps = mult_pers(n,1);
            cout << "num steps = "<< steps<< endl;
        }catch(...){
            cout << "Enter a valid number\n";
        }
        cout << "====================\n";
    }
}
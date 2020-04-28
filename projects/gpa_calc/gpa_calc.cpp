#include <iostream>
#include <unordered_map>
#include <sstream>
#include <fstream>
using namespace std;

int main(int argc, char **argv){
    stringstream ss;
    unordered_map <string, double> gpa_scale;
    string line,letter_grade,file_name;
    double credit_hour,letter_worth,total_points,total_credit_hours;
    ifstream fin;

    if(argc!=2){
        cout << "USAGE : MISSING FILE NAME\n";
        return 1;
    }
    ss.clear();
    ss.str(argv[1]);
    ss>>file_name;

    fin.open("gpa_scale.txt");
    while(getline(fin,line)){
        ss.clear();
        ss.str(line);
        ss >> letter_grade >> letter_worth;
        gpa_scale[letter_grade] = letter_worth;
    }
    fin.close();

    fin.open(file_name.c_str());
    if(!fin.is_open()){
        cout << "USAGE : BAD FILE NAME\n";
        return 0;
    }
    total_points=total_credit_hours=0;
    while(getline(fin,line)){
        ss.clear();
        ss.str(line);
        ss>>credit_hour>>letter_grade;
        if(letter_grade=="NC")continue;
        total_credit_hours+=credit_hour;
        total_points += credit_hour * gpa_scale[letter_grade];
    }
    cout <<"TOTAL CREDIT HOURS :: "<< total_credit_hours << '\n';
    cout <<"TOTAL POINTS :: "<< total_points << '\n';
    cout << "GPA :: "<<total_points/total_credit_hours << '\n';
    fin.close();
}
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

void a04(){
    fstream a04a, a04b, a04c, a04T;
    string line;
    
    a04T.open("a04T.txt", ios::out);
    if(a04T.is_open()){
        a04a.open("a04a.txt", ios::in);
        if (a04a.is_open()){
            while (getline(a04a, line)){
                a04T << line << "_";
            }
            a04a.close();
        }
        a04b.open("a04b.txt", ios::in);
        if (a04b.is_open()){
            while (getline(a04b, line)){
                a04T << line << "_";
            }
            a04b.close();
        }
        a04c.open("a04c.txt", ios::in);
        if (a04c.is_open()){
            while (getline(a04c, line)){
                a04T << line << "_";
            }
            a04a.close();
        }
        a04T.close();
    }
    
}





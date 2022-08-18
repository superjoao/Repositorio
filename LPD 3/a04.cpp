#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

void a04(){
    fstream a04a, a04b, a04c;
    string line;
    a04a.open("a04a.txt", ios::in);
    if (a04a.is_open()){
        while (getline(a04a, line)){
            cout << line;
        }
        a04a.close();
    }
    if (a04b.is_open()){
        while (getline(a04b, line)){
            cout << line;
        }
        a04b.close();
    }
    if (a04c.is_open()){
        while (getline(a04c, line)){
            cout << line;
        }
        a04a.close();
    }
}

int main(int argc, char const *argv[])
{
    a04();
    return 0;
}

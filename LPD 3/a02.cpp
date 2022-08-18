#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
void a02 (){

    fstream a02;
    string line;
    char tmp1 [30];
    int tmp = 0;

    a02.open("a02.txt", ios::in);

    if (a02.is_open()){
        
        while (getline(a02, line, ' ')){
            cout << line << endl;
            int size1 = line.length();
            if (size1 > tmp){
                tmp = size1;
                line.copy(tmp1,line.length());
            }
        }
        a02.close();
    }
    cout << "O comprimento da palavra de maior tamanho é: " << tmp << endl << "que é: ";
    for (int i = 0; i < strlen(tmp1); i++){
        cout << tmp1[i];
    }   
}

int main(int argc, char const *argv[])
{
    a02();
    return 0;
}
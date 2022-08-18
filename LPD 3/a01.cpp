#include <iostream>
#include <fstream>
#include <cstdio>

using namespace std;


void a01 (){
    fstream fileA01;
    char caracter;
    
    int total=0, totalLetras=0;

    cout << "Digite a frase: \n";
    fileA01.open ("a01.txt", ios:: out);
    if (fileA01.is_open()){
        while ((caracter = getchar()) != '\n'){
            fileA01 << caracter;
            if (caracter >= 'A' && caracter <= 'Z' || caracter >= 'a' && caracter <= 'z')
            {
                totalLetras++;
            }
            total++; 
        }
        fileA01.close();
    }
    
    cout << "O total de caracter é de: " << total << endl << "O total de letras é de: " << totalLetras << endl;
}
int main(int argc, char const *argv[])
{
    a01 ();
    return 0;
}
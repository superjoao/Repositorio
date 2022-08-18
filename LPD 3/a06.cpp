#include <iostream>
#include <cstring>
#include <fstream>


using namespace std;

void a06 (){
    fstream a06;
    string line, word;
    int count=0, num=0;
    a06.open("a06.txt", ios::in);
    if (a06.is_open()){
        cout << "Digite a palavra que procura: ";
        getline (cin, word);
        while (getline(a06, line, ' ')){
            if (line == word){
                cout << "A palavra \"" << word << "\" esta contida no texto.";
                count ++;
            }         
        }
        if (count < 1){
            cout << "\nNão foi encontrada a palavra";
        }
        a06.close();
    }
}
int main(int argc, char const *argv[])
{
    a06();
    return 0;
}

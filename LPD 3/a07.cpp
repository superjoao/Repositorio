#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

void a07(){
    fstream a07, a07b;
    string line, word, coma = {',',' '};
    int j, k;
    a07.open("a07.txt",ios::in);
    if (a07.is_open()){
        a07b.open("a07b.txt", ios::out);
        if (a07b.is_open())
        {
            while(getline(a07, line)){

                /*Botar o sobrenome maiusculo primeiro.
                usando o char null ('\0) para parar no final da frase*/
                for (int i = 0; i<line.length()+1; i++){
                    j = i;
                    if (line[i] == '\0'){
                        //Rebobinar a var j até chegar no ultimo espaço.
                        while (line[j]!= ' '){
                            j--;   
                        }
                        // guarda o valor j (a posição onde encontra o sobrenome) em k.
                        k=j;

                        //escreve o sobrenome em mausculo.
                        if (line[j] == ' '){
                            for (j+=1; j < line.length(); j++){ 
                                a07b << char(toupper(line[j]));
                            }
                        }
                    }  
                }
                //separar por virgula.
                a07b << coma;

                // colocar o nome depois, utilizando var k como ponto final.
                for (int i = 0; i<k; i++){
                    a07b << line[i];
                }
                a07b << '\n';
            }
            a07b.close();
        }
        a07.close();
    }
}
int main(int argc, char const *argv[])
{
    a07();
    return 0;
}

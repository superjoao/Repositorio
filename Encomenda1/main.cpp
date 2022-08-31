#include "cheque.h"
#include "cheque.cpp"

int main(int argc, char const *argv[])
{
    string *arquivo = new string[50];
    if (arquivo == NULL)
    {
        cout << "Erro de alocacao";
        exit (1);
    }else{
        readFile (arquivo);
    }
    delete [] arquivo;
    return 0;
}
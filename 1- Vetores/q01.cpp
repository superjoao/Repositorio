#include <iostream>
#include <cstdlib>

#define ARR_LEN 10
using namespace std;

void insertQ01 (){
    int *tempArr;
    //reserva memória para vetor temp
    tempArr = new int[ARR_LEN];

    //Verifica se há suficiente memória.
    if (tempArr == NULL)
    {
        cout << "Não é possivel alocar memoria\n";
        exit (1);
    }
    cout << "tamanho do vetor: " << ARR_LEN << endl;

    // se o valor de x for par entrega-o para o vetor temp
    int x, j=0;
    while (j < ARR_LEN)
    {
        if ( (x=rand() %10) %2 !=0)
        {
            tempArr[j] = x;
            j++;
        }
    }
    cout << "A lista de impares é:\n{";
    for (int i=0; i< ARR_LEN-1; i++){
        cout << tempArr[i] << ", ";
    }
    cout << tempArr[ARR_LEN-1]<< "}";
    delete [] tempArr;

}




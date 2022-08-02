#include <iostream>
#include <cstdlib>
#define AR_LEN 20
using namespace std;

int* ar; 

void print (int x[]){
    
    for (int i = 0; i < AR_LEN; i++)
    {
        cout << x[i] << " ";
    }
}
void mergeEvenOddQ04(){
    //reserva memória.
    ar = new int [AR_LEN];

    //verifica se há suficente memória.
    if (ar == NULL)
    {
        cout << "Não é possivel alocar memoria\n";
        exit (1);
    }
    int ar1[AR_LEN], ar2 [AR_LEN];

    // Sorteia os números para ar1 e ar2
    for (int i = 0; i < AR_LEN; i++)
    {
        ar1[i] = rand() %10; 
        ar2[i] = rand() %10;         
    }
    //imprimi os dois vetores
    cout << "\nVetor ar1:\n\n";
    print(ar1);

    cout << "\nVetor ar2:\n\n";
    print(ar2);

    //Libera posição par e impar dos vetores ar1&2 para o vetor ar.
    for (int i = 0; i < AR_LEN; i++)
    {
        (i%2 ==0)? ar[i] = ar1[i] : ar[i]= ar2[i];
    }
    cout << "\n\nVetor posição par e impar:\n";
    print(ar);
    //Libera memória.
    delete []ar;
}




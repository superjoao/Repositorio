#include <iostream>
#include <stdlib.h>

#define ARR_LEN1 40

using namespace std;


int *arr, even;

void oddEvenQ03 (){
    //Alloca memória para variavel arr.
    arr = new int[ARR_LEN1];

    //Arr recebe elementos sorteados.
    for (int i = 0; i < ARR_LEN1; i++)
    {
        arr[i] = rand() %10;
    }

    //imprimi os elementos pares tem arr
    cout << "\nContar e escrever quantos valores pares possui:\n";
    cout << "{";
    for (int i = 0; i < ARR_LEN1; i++)
    {
        if (arr[i] %2 == 0 )
        {
            even += 1;
            cout << arr[i] << ", ";
        }  
    } 
    cout << "\b\b}"<< endl;
    cout << "Par: "<< even << endl;
    delete [] arr;
}



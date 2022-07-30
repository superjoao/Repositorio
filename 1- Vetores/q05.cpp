#include <iostream>
#include <cstdlib>

#define AR_LEN1 10

using namespace std;

void print1 (int x[]){
    
    for (int i = 0; i < AR_LEN1; i++)
    {
        cout << x[i] << " ";
    }
}

void sort (int vector[], int rangeNum){
    for(int i = 0; i < AR_LEN1; i++){
        vector[i] = rand() %rangeNum;
    }
}
void sameValueQ05(int *ar){
    //Alocar memória.
    ar = new int [AR_LEN1];
    //Verificando se há.
    if (ar == NULL)
    {
        cout << "Não é possivel alocar memoria\n";
        exit (1);
    }
    sort (ar, 10);
    cout<< "\nValores do ar: \n";
    print1 (ar);
    
    cout<< "\nValores repitidos de ar: \n";
    for (int i = 0; i < AR_LEN1; i++)
    {   
        for (int j = i+1; j <AR_LEN1; j++){
            if (ar[i]== ar[j])
            {
                cout << ar[j] << " ";
            }  
        }
    }
    delete []ar;   
}
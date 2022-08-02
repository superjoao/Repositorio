#include <iostream>
#include <cstdlib>

#define ROWS1 5
#define COLS1 5
using namespace std;


void print2 (int **mat){
    for (int i = 0; i < ROWS1; i++){
        cout << endl;
        for (int j = 0; j < COLS1; j++){
            cout << mat [i][j] << " ";
        }    
    }
}

void matrixQ07 (int **mat){

    //Cria um vetor de ponteiro que aponta para outros vetores.
    mat = new int*[ROWS1];
    for (int i = 0; i< ROWS1; i++){
        mat[i] = new int[COLS1];
        for (int j = 0; j < COLS1; j++){
            if (i == j)
            {
                mat[i][j] = 1;
            }
            else
            {
                mat[i][j] = 0;
            }
            
            //Escolhe números aleatorios para a matriz.
             
        }
    }

    print2 (mat);

    //deleta cada sub vetor.
    for (int i=0; i< ROWS1; i++){
        delete [] mat[i];
    }
    
    //Retira o vetor de ponteiros.
    delete[] mat;
}
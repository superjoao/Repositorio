#include <iostream>
#include <cstdlib>

#define ROWS 10
#define COLS 10
using namespace std;


int biggerThen(int num1, int num2){
    return (num1 >= num2) ?num1 : num2;
}

void print (int **mat, int tmp){
    for (int i = 0; i < ROWS; i++){
        cout << endl;
        for (int j = 0; j < COLS; j++){
            cout << mat [i][j] << " ";
        }    
    }
    cout << endl << endl;
    for (int i = 0; i < ROWS; i++){
        for (int j = 0; j < COLS; j++){
            
            if (tmp == mat[i][j]){
                cout << "[" << i << "]"<< "[" << j << "]" << " = " << tmp << endl;
            }
        }
    }
}

void largestNumQ06 (int **mat){

    //Cria um vetor de ponteiro que aponta para outros vetores.
    mat = new int*[ROWS];
    for (int i = 0; i< ROWS; i++){
        mat[i] = new int[COLS];
        for (int j = 0; j < COLS; j++){

            //Escolhe números aleatorios para a matriz.
            mat[i][j] = rand() %10;
        }
    }

    //cria uma variável temporaria para receber o inicio de var mat.
    int tmp = **mat;

    //verifica qual é o maior numero.
    for (int i = 0; i < ROWS; i++){
        for (int j = 0; j < COLS; j++){
            tmp = biggerThen(tmp, mat[i][j]);
        }
    }
    print (mat, tmp);

    //deleta cada sub vetor.
    for (int i=0; i< ROWS; i++){
        delete [] mat[i];
    }
    
    //Retira o vetor de ponteiros.
    delete[] mat;
}


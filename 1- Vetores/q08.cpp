#include <iostream>
#include <cstdlib>

using namespace std;

void matrixQ08 (int *vect){
    
    int mat2[6][6] = {{0,63,210,190,0,190},{63,0,160,150,95,0},{210,160,0,10,0,0},{190,150,10,0,0,0},{0,95,0,0,0,80},{190,0,0,0,80,0}};
    vect = new int [5];
    vect [0] = mat2[2][3];
    vect [1] = mat2[3][1];
    vect [2] = mat2[1][4];
    vect [3] = mat2[4][5];
    vect [4] = mat2[5][0];
    int soma;
    for (int i = 0; i< 5; i++){
        soma += vect[i];
    }
    cout << soma << endl;
    
    //Retira o vetor de ponteiros.
    delete[] vect;
}
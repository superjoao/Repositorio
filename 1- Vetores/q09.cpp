#include <iostream>
#include <cstdlib>

#define ROWS2 100
#define COLS2 10

using namespace std;

void print3 (char **mat){
    for (int i = 0; i < ROWS2; i++){

        cout << i+1 <<"º Aluno: ";
        for (int j = 0; j < COLS2; j++){
            cout << mat [i][j] << " ";
        } 
        cout<< endl;   
    }
}
void insertQ09 (char **mat){
    
    int vector[ROWS2];
    char a[1] = {'a'}, b[1] = {'b'},c[1] = {'c'}, d[1] = {'d'};
    char templante [COLS2] = {'a', 'b', 'c', 'd','a', 'b', 'c', 'd', 'd', 'd'};
    mat = new char* [ROWS2];
    for (int i = 0; i < ROWS2; i++)
    {
        mat[i] = new char[COLS2];
        for (int j = 0; j<COLS2; j++){
            int tmp = (rand()% 4)+1;
            switch (tmp){
        
            case 1:
                mat [i][j] = *a;
                break;
            case 2:
                mat [i][j]= *b;
                break;
            case 3:
                mat [i][j]= *c;
                break;
            case 4:
                mat [i][j]= *d;
                break;
        
            default:
                break;
            }
        }   
    }
    for (int i = 0; i < ROWS2; i++)
    {   
        int v=0;
        for (int j = 0; j<COLS2; j++){
            
            vector[i]=(mat[i][j]== templante[j])?v+=1 :v;   
        }
    }
    print3(mat);
    cout<< "\nRespostas por aluno: " <<endl;
    for (int i = 0; i < ROWS2; i++){
        cout << i+1 << "º Aluno, nota: " << vector[i] << endl;
    }


    for (int i= 0; i < ROWS2; i++){
        delete []mat[i];
    }
    delete [] mat;
}
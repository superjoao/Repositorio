#include <iostream>

using namespace std;

void matrixPy1(){

    int i=0, j, n =5;
    // a)
    while (i<n){
        i++;
        j=1;
        cout << endl;
        while (j <=i){   
            cout<< "\t" <<j;
            j++;
        }    
    }
    cout << endl;
}
void matrixPy2(){

    int i=1, j, n =6;
    // b)
    while (i<n){
        i++;
        j=1;
        cout << endl;
        while (j<i){   
            cout<< "\t" <<i-j;
            j++;
        }    
    }
    cout << endl;
}
void matrixPy3(){

    int i=0, j, n =5;
    // c)
    while (i<n){
        i++;
        j=1;
        cout << endl;
        while (j <=i){   
            cout<< "\t" <<i;
            j++;
        }    
    }
    cout << endl;
}




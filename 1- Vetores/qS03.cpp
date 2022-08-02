#include <iostream>
#include <iomanip>

#define N3 1

using namespace std;

typedef struct node3{
    char name3[30];
    float cost3;
    int code3;
}goods;

void insertQS03(goods *p){
    p[N3];
    
    for (int i = 0; i<N3; i++){
        
        cout << "Nome do produto: ";
        cin.getline (p[i].name3,30);
        cout << "Custo: ";
        cin >> p[i].cost3;
        cout << "Codigo: ";
        cin >> p[i].code3;
        cout << endl;
    }
    int tmp;
    cout << "qual o codigo do prudoto: "<<endl;
    cin >> tmp;
    
    for (int i = 0; i<N3; i++){
        if(p[i].code3 == tmp){
            cout << "o produto:  "<< p[i].name3<< endl;
            cout << fixed <<setprecision(2)<<"Custa: " << p[i].cost3<<endl; 
        }
        else{
            cout << "produto não encontrado.";
        }    
    }  
}
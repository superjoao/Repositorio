#include <iostream>

#define N2 1

using namespace std;

typedef struct node2{
    char name2[30];
    float hight2;
    int wheight2;
    int ssn2;
    char gender2[1];
}person1;

void insertQS02(person1 *p){
    p[N2];
    
    for (int i = 0; i<N2; i++){
        
        cout << "Nome da pessoa: ";
        cin.getline (p[i].name2,30);
        cout << "Altura: ";
        cin >> p[i].hight2;
        cout << "peso: ";
        cin >> p[i].wheight2;
        cout << "CPF: ";
        cin >> p[i].ssn2;
jump:        
        cout << "sexo:\n [m] - Masculino\n [f] - Feminino\n";        
        cin >> p[i].gender2;
        p[i].gender2[0] = towlower (p[i].gender2[0]);
        if (p[i].gender2[0] != 'm' && p[i].gender2[0] != 'f'){
            printf ("Digito invalido.\n");
            goto jump;
        }
        cout << endl;
    }
    int tmp;
    cout << "Localize atravez do CPF: "<<endl;
    cin >> tmp;
    
    for (int i = 0; i<N2; i++){
        if(p[i].ssn2 == tmp){
            cout << "O IMC é: "<< endl;
            cout << p[i].wheight2/(p[i].hight2 *p[i].hight2)<<endl; 
        }
        else{
            cout << "CPF não encontrado.";
        }
          
    }  
}
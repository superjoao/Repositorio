#include <iostream>
#include <iomanip>

#define N4 1

using namespace std;

typedef struct node4{
    char name4[30];
    char job4 [30];
    float hight4;
    int age4;
    int ssn4;
    char birthDay4[10];
    int code4;
    char gender4[1];
    float wage4;
}employee;

void printQS04(employee *p){
    
    for (int i = 0; i<N4; i++){
                
        cout << "Dados do empregado: "<< endl;
        cout << "Nome: "<< p[i].name4 << "\nCargo: " << p[i].job4 << "\nAltura: "<< p[i].hight4 << "\nIdade: "<< p[i].age4 << "\nCPF: " << p[i].ssn4 << "\nData de aniversario: "<< p[i].birthDay4 << "\nCodigo: "<< p[i].code4 << "\nGenero: " << toupper(p[i].gender4[0]) << "\nSalario R$: "<< fixed << setprecision(2)<< p[i].wage4 << "\n "<<endl;
          
    }
}
void insertQS04(employee *p){
    p[N4];
    for (int i = 0; i<N4; i++){
        cout << "Nome do funcionario: ";
        cin.getline (p[i].name4,30);
        cout << "Cargo: ";
        cin.getline (p[i].job4,30);
        cout << "Altura: ";
        cin >> p[i].hight4;
        cout << "idade: ";
        cin >> p[i].age4;
        cout << "CPF: ";
        cin >> p[i].ssn4;
        cout << "data de aniversario dd/mm/aaaa: ";
        cin >> p[i].birthDay4;
leap:        
        cout << "Setor onde trabalha (0 -99)";
        cin >> p[i].code4;
        if (p[i].code4 <0 && p[i].code4 > 99){
            printf ("Setor invalido, tente outra vez\n");
            goto leap;
        }
jump:        
        cout << "sexo:\n [m] - Masculino\n [f] - Feminino\n";        
        cin >> p[i].gender4;
        p[i].gender4[0] = towlower (p[i].gender4[0]);
        if (p[i].gender4[0] != 'm' && p[i].gender4[0] != 'f'){
            printf ("Digito invalido.\n");
            goto jump;
        }
        cout << "Salario: ";
        cin >> p[i].wage4;
        cout << endl;
    }
    printQS04(p);  
}
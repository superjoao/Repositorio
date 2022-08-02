#include "menu.h"

void menu (){
    
    int item=1;

    do{
        
        
        cout << "MENU: \n [1]- Vetores\n [2]- Structs\n [0]- Sair\n";
        cin >> item;
        // Limpa == cls.
        cout<< "\e[1;1H\e[2J";

        switch (item)
        {
        case 1:

            do{
                
                cout << "MENU VETORES: \n [1]- q01\n [2]- q02\n [3]- q03\n [4]- q04\n [5]- q05\n [6]- q06\n [7]- q07\n [8]- q08\n [9]- q09\n [10]- q010\n [0]- Sair\n";
                cin >> item;
                // Limpa == cls.
                cout<< "\e[1;1H\e[2J";
                switch (item)
                {
                case 0:
                    cout << "Obrigado por usar este programa! Tchau.";
                    break;
                case 1:
                    insertQ01();
                    cout << "\nDigite qualquer tecla para continuar...\n";
                    getch();
                    cout<<endl;
                    break;
                case 2:
                    insertQ02();
                    cout << "\nDigite qualquer tecla para continuar...\n";
                    getch();
                    cout << endl;
                    break;
                case 3:
                    oddEvenQ03();
                    cout << "\nDigite qualquer tecla para continuar...\n";
                    getch();
                    cout << endl;
                    break;
                case 4:
                    mergeEvenOddQ04();
                    cout << "\nDigite qualquer tecla para continuar...\n";
                    getch();
                    cout << endl;
                    break;
                case 5:
                    int* d, ar1;
                    sameValueQ05(d);
                    cout << "\nDigite qualquer tecla para continuar...\n";
                    getch();
                    cout << endl;
                    break;
                case 6:
                    int** mat1;
                    largestNumQ06(mat1);
                    cout << "\nDigite qualquer tecla para continuar...\n";
                    getch();
                    cout << endl;
                    break;
                case 7:
                    int** mat2;
                    matrixQ07(mat2);
                    cout << "\nDigite qualquer tecla para continuar...\n";
                    getch();
                    cout << endl;
                    break;
                case 8:
                    int* mat3;
                    matrixQ08(mat3);
                    cout << "\nDigite qualquer tecla para continuar...\n";
                    getch();
                    cout << endl;
                    break;
                case 9:
                    char** mat4;
                    insertQ09 (mat4);
                    cout << "\nDigite qualquer tecla para continuar...\n";
                    getch();
                    cout << endl;
                    break;
                case 10:
                    matrixPy1();
                    matrixPy2();
                    matrixPy3();
                    cout << "\nDigite qualquer tecla para continuar...\n";
                    getch();
                    cout << endl;
                    break;
                default:
                    cout << "Digito invalido\n";
                    getch();
                    break;
                }
            }while(item != 0);
            break;
            case 2:

            do{
                
                cout << "MENU VETORES: \n [1]- qS01\n [2]- qS02\n [3]- qS03\n [4]- qS04\n [0]- Sair\n";
                cin >> item;
                cin.ignore();
                // Limpa == cls.
                cout<< "\e[1;1H\e[2J";
                switch (item)
                {
                case 0:
                    cout << "Obrigado por usar este programa! Tchau.";
                    break;
                case 1:
                    person p1;
                    insertQS01 (&p1);
                    item = 1;
                    cout << "\nDigite qualquer tecla para continuar...\n";
                    getch();
                    cout<<endl;
                    break;
                case 2:
                    person1 p2;
                    insertQS02 (&p2);
                    cout << "\nDigite qualquer tecla para continuar...\n";
                    getch();
                    cout<<endl;
                    break;
                case 3:
                    goods p3;
                    insertQS03 (&p3);
                    cout << "\nDigite qualquer tecla para continuar...\n";
                    getch();
                    cout<<endl;
                    break;
                case 4:
                    employee p4;
                    insertQS04 (&p4);
                    cout << "\nDigite qualquer tecla para continuar...\n";
                    getch();
                    cout<<endl;
                    break;
                default:
                    cout << "Digito invalido\n";
                    getch();
                    break;
                }
            }while(item != 0);
            break;
        case 0:
            break;    
        default:
            cout << "\nDigito invalido\n";
            cout << "Digite qualquer tecla para continuar...\n";
            getch();
            break;
        }
    }while(item != 0);
}   

int main(int argc, char const *argv[])
{
    menu();
    return 0;
}

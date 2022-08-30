//menu.cpp
#include "menu.h"


void menu (){

    int item = 1;

    do{

        cout << "MENU: \n [1]- Strings\n [2]- algotitmos especiais\n [0]- Sair\n";

        cin >> item;
        // Limpar == cls.
        cout<< "\e[1;1H\e[2J";
        switch (item)
        {
        case 1:

            do{

                cout << "MENU VETORES: \n [1]- q01\n [2]- q02\n [3]- q03\n [4]- q04\n [5]- q05\n [6]- q06\n [7]- q07\n [0]- Sair\n";
                cin >> item;
                cin.ignore();
                switch (item)
                {
                case 0:
                    cout << "Obrigado por usar este programa! Tchau.";
                    break;

                case 1:
                    a01();
                    cout << "\nDigite qualquer tecla para continuar...\n";
                    getch();
                    cout<<endl;
                    break;

                case 2:
                    a02();
                    cout << "\nDigite qualquer tecla para continuar...\n";
                    getch();
                    cout << endl;
                    break;

                case 3:
                {
                    char s1 [] = "abacatada light";
                    int num1 = 3;
                    codificar (s1, num1);
                    cout << "\nDigite qualquer tecla para continuar...\n";
                    getch();
                    cout << endl;
                }break;
                
                    
                case 4:
                    a04();
                    cout << "\nDigite qualquer tecla para continuar...\n";
                    getch();
                    cout << endl;
                    break;
                    
                case 5:
                {       
                    char login[15], password[15];
                    strcpy(p[0].login, "Joao"); 
                    strcpy(p[0].password, "123");
                    int num2 = 3;
                    codificar1 (p, num2);
                    cout << "\nDigite qualquer tecla para continuar...\n";
                    getch();
                    cout << endl;
                }break;
                    
                case 6:
                    a06();
                    cout << "\nA casa do cavalo é branco.\n";
                    cout << "\nDigite qualquer tecla para continuar...\n";
                    getch();
                    cout << endl;
                    break;

                case 7:
                    a07();
                    cout << "\nDigite qualquer tecla para continuar...\n";
                    getch();
                    cout << endl;
                    break;

                default:
                    cout << "Digito invalido\n";
                    getch();
                    break;
                }
                // Limpa == cls.
                cout<< "\e[1;1H\e[2J";
            }while(item != 0);
            break;
        case 2:

            do{

                cout << "MENU VETORES: \n [1]- qS01\n [2]- qS02\n [3]- qS03\n [4]- qS04\n [5]- qS05\n [0]- Sair\n";

                cin >> item;
                cin.ignore();
                
                switch (item)
                {
                case 0:
                    cout << "Obrigado por usar este programa! Tchau.";
                    break;

                case 1:
                {
                    int ar[5] = {1,2,3,4,5};
                    int size1 = sizeof(ar)/ sizeof(*ar);
                    b01(ar, size1);
                    cout << "\nDigite qualquer tecla para continuar...\n";
                    getch();
                    cout<<endl;
                }break;

                case 2:
                {
                    int ar1[] = {3,7,5,9,6};
                    int size2 = sizeof(ar1)/sizeof(*ar1);
                    cout << "3, 7, 5, 9, 6";
                    b02 (ar1, size2);
                    cout << "\nDigite qualquer tecla para continuar...\n";
                    getch();
                    cout<<endl;
                }break;

                case 3:
                    b03();
                    cout << "\nDigite qualquer tecla para continuar...\n";
                    getch();
                    cout<<endl;
                    break;

                case 4:
                {
                    int moedas[] = {1, 2, 5 ,10, 20};
                    int size = sizeof(moedas)/ sizeof (*moedas);
	                int troco = 26;
	                cout << "Numero de moedas: " << num_moedas(moedas, troco, size);
                    cout << "\nDigite qualquer tecla para continuar...\n";
                    getch();
                    cout<<endl;
                }break;

                case 5:
                {
                    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
						{ 4, 0, 8, 0, 0, 0, 0, 11, 0 },
						{ 0, 8, 0, 7, 0, 4, 0, 0, 2 },
						{ 0, 0, 7, 0, 9, 14, 0, 0, 0 },
						{ 0, 0, 0, 9, 0, 10, 0, 0, 0 },
						{ 0, 0, 4, 14, 10, 0, 2, 0, 0 },
						{ 0, 0, 0, 0, 0, 2, 0, 1, 6 },
						{ 8, 11, 0, 0, 0, 0, 1, 0, 7 },
						{ 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

	                dijkstra(graph, 0);
                    cout << "\nDigite qualquer tecla para continuar...\n";
                    getch();
                    cout<<endl;
                }break;

                default:
                    cout << "Digito invalido\n";
                    getch();
                    break;
                }
                // Limpa == cls.
                cout<< "\e[1;1H\e[2J";
            }while(item != 0);
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
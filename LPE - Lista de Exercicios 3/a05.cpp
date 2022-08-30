#include <iostream>
#include <cstring>
#include <cstdlib>

typedef struct{
    char login[15]; 
    char password[15]; 
} user; user p[1];

using namespace std;

void gate (user *u,int const n){
    char a[15] ={'\0'}, b [15] ={'\0'};
    do
    {
        cout << "\nDigite o login: ";
        cin >> b;
        cout << "\nDigite a senha: ";
        cin >> a;
        for (int i = 0; i < strlen(a); i++){
            if (a[i] != ' '){
                a[i]= char(a[i]+n);
            }else{
                a [i]= a[i];
            }
        }
        
    } while (strcmp(a, u[0].password)!= 0 ||  strcmp(b, u[0].login) != 0);
    


    cout << "logon.";
}

void codificar1 (user *u, int const n){
    
    
    for (int i = 0; i < strlen(u[0].password); i++){
        if (u[0].password[i] != ' '){
            u[0].password[i] = char(u[0].password[i]+n);
            
        }else{
            u[0].password[i] = u[0].password[i];
             
        }
    }
    gate (u, n);  
}
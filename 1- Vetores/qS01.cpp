#include <iostream>

#define N 3

typedef struct node{
    char name[30];
    char address [100];
    char phone[11];
}person;

void insertQS01(person *q){
    q[N];
    
    for (int i = 0; i<N; i++){
        
        cout << "Nome da pessoa: ";
        cin.getline (q[i].name,30);
        cout << "Endereço: ";
        cin.getline (q[i].address, 100);
        cout << "Telefone: ";
        cin.getline (q[i].phone, 11);
        cout << endl;
    }
    person tmp;
    
    for (int i = 0; i<N; i++){
        if ((int)tolower(q[i].name[0])>=(int)tolower(q[i+1].name[0]))
        {   
            if (i+1 <N)
            {
                tmp = q[i];
                q[i] = q[i+1];
                q[i+1] = tmp;
            }
        }
    }  
    for (int i=0; i<N; i++){
        cout << q[i].name << "\n" << q[i].address << "\n"<< q[i].phone << "\n "<<endl;
    }
}

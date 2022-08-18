#include <iostream>
#include <cstring>

using namespace std;

void codificar (char s[], int n){

    string a, b, c;
    
    cout << "\n senha é : " << endl;
    for (int i = 0; i < strlen(s); i++){
        if (s[i] != ' '){
            c[i] = char(s[i]+n);
            cout << char(s[i]+n);
        }else{
            c[i] = s[i];
            cout << s[i];
            
        }
    }
    cout << c.length();
    do
    {
        int i = 0;
        cout << "\nDigite a senha: ";
        getline(cin, a);
    
        if (a[i] != ' '){
            b[i]= char(a[i]+n);
        }else{
            b [i]= a[i];
        }
        i++;
    } while (!c.compare(b));
    


    cout << "senha correta.";
        
}

int main(int argc, char const *argv[])
{
    char password [] = "bananna";
    int num = 3;
    codificar (password, num);
    return 0;
}

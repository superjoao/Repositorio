#include <iostream>
#include <cstring>

using namespace std;

void codificar (char s[], int n){

    for (int i = 0; i < strlen(s); i++){
        if (s[i] != ' '){
            cout << char(s[i]+n);
        }else{
            cout << s[i];
        }
    }
}

int main(int argc, char const *argv[])
{
    char s1 [] = "abacatada light";
    int num = 3;
    codificar (s1, num);
    return 0;
}

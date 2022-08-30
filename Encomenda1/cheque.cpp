#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

using namespace std;
int main(int argc, char const *argv[])
{
    
    string unidade []= {"\0", "um", "dois", "tres", "quatro", "cinco", "seis", "sete", "oito", "nove"};
    string dezena [] = {"\0", "\0" "vinte", "trinta", "quarenta", "cinquenta", "sessenta", "setenta", "oitenta", "noventa"};
    string dezenaAlt [] = {"dez", "onze", "doze", "treze", "quatorze", "quinze", "dezeseis", "dezessete", "dezoito", "dezenove"};
    string centena [] = {"\0", "cem ", "duzentos ", "trezentos", "quatrocentos", "quinhentos", "seiscentos", "setessentos", "oitocentos", "novecentos"};
    string centenaAlt [] = {"\0", "cento e "};
    string milhar [] = {"\0", "mil e "};
    string milhao [] = {"\0", " milhao e ", " milhoes e "};
    
    
    
    int cD, cU, u, d, c, m, mC, mD, mU, mi;
    double num;
    
    cout << "Qual o valor?";
    cin >> num;//1.231.121,23

    // Milhão
    mi = num /1000000;
    num = num - (mi*1000000);
    cout << "milhao " << mi << endl;

    //milhar
    m = num /1000;
    double num1 = num/1000;
    cout << "milhar " << m << endl;

    mC = num1/100;
    cout << "Milhar centena " << mC << endl;

    num1 = num1 - (mC*100);
    mD = num1/10;
    cout << "Milhar dezena " << mD << endl;

    mU = num1 - (mD*10);
    cout << "Milhar unidade " << mU << endl;

    // centena
    num = num -(m*1000);
    c = num/100;
    cout << "centena " << c << endl;

    //dezena
    num = num -(c*100);
    d = num/10;
    cout << "dezena " << d << endl;

    //unidade
    num = num -(d*10);
    u = num;
    cout << "unidade " << u << endl;

    // centavos
    num = (num -u)*10;
    cD = num;
    cout << "centavos dezena " << cD << endl;
    num = (num - cD)*10;
    cU = int(num);
    cout << "centavos unidade " << cU << endl;
    cout << num << endl;

    if (mi)
    {
        cout << unidade[mi];
        if (mi>1){
            cout << milhao[2];
        }else{
            cout << milhao[1];
        } 
    }
    
    
    if(m){
        (mC == 1)? cout << centenaAlt [1] : cout << centena [mC];
        (mD == 1)? cout << dezenaAlt[mU] :cout << dezena [mD] << unidade [mU];
        cout << " " << milhar[1];
    }
    (c == 1)? cout << centenaAlt [1] : cout << centena [c];
    (d==1)? cout << dezenaAlt [u] : cout << dezena[d] << unidade [u]; 
    cout << " Reais";
    
    if (cD){
        cout << " e ";
        (cD==1)? cout << dezenaAlt [cU] : cout << dezena[cD] << unidade[cU];
        cout << " Centavos" << endl;
    }
    return 0;
}

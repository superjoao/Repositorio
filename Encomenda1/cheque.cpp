#include "cheque.h"

//função para calcular e imprimir o cheque.
void chequeCal(string unidade[], string dezenaAlt[], string dezena[],string centena[], string centenaAlt[], string milhar[], string milhao[]){
    double tmp;
    cout << "Qual o valor?";
    cin >> tmp;
    int cD, uC, u, d, c, m, mC, mD, mU, mi;
    string zero;
    
    int num = tmp *100; 
    // Milhão
    mi = num /100000000;
    num = num - (mi*100000000);
    cout << "milhao " << mi << endl;

    //milhar
    m = num/100000;
    double num1 = num/100000;
    cout << "milhar " << m << endl;

    mC = num1/100;
    cout << "Milhar centena " << mC << endl;

    num1 = num1 - (mC*100);
    mD = num1/10;
    cout << "Milhar dezena " << mD << endl;

    mU = num1 - (mD*10);
    cout << "Milhar unidade " << mU << endl;

    // centena
    num = num -(m*100000);
    c = num/10000;
    cout << "centena " << c << endl;

    //dezena
    num = num -(c*10000);
    d = num/1000;
    cout << "dezena " << d << endl;

    //unidade
    num = num -(d*1000);
    u = num/100;    
    cout << "unidade " << u << endl;

    // centavos
    num = num -(u*100);
    cD = num/10;
    cout << "centavos dezena " << cD << endl;
    num = num - (cD*10);
    uC = num;
    cout << "centavos unidade " << uC << endl;
    cout << "Resposta por extenso: " << endl;
    
    //Imprimir cheque.
    switch (mi)
    {
    case 0:
        
        break;
    case 1:
        cout << unidade[mi] << " " << milhao[1]<< " e ";
        break;
    case 2:
        cout << unidade[mi] << " " << milhao[2] << " e ";
        break;
    default:

        break;
    }
    
    switch (m)
    {
    case 0:
        break;
    
    default:
        switch (mC)
        {
        case 0:
            break;
        default:
            (mC == 1)? cout << centenaAlt [1] : cout << centena [mC] << " e ";
            break;
        }
        if (mD || mD != 0)
        {   
            (mD == 1)? cout << dezenaAlt[mU] :cout << dezena [mD] << " e ";
        }
        
        if(mU){
            cout << unidade[mU] << " e ";
        }
        cout << "\b\b " << milhar[1] << " e ";
        break;
    }

    switch (c)
    {
    case 0:
        break;
    default :
        (c == 1)? cout << centenaAlt [1] << " e " : cout << centena [c] << " e ";
        break;
    }
    
    switch (d)
    {
    case 0:
        
        break;
    
    default:
        (d==1)? cout << dezenaAlt [u] << "  " : cout << dezena[d] << " e ";
        break;
    }
    
    switch (u)
    {
    case 0:
        
        break;
    
    default:
         cout << unidade[u] << " e ";
        break;
    }
    
    if (u == 1 && !mi && !m && !c && !d)
    {
        cout << " Real";
    }else if (u == 0 && !mi && !m && !c && !d)
    {
        cout << "zero Real";
    }else{
        cout << "\b\b Reais";
    }
    
    switch (cD)
    {
    case 0:
        
        break;
    
    default:
        cout << " e ";
        (cD==1)? cout << dezenaAlt [uC] : cout << dezena[cD];
        break;
    }
    
    switch (uC)
    {
    case 0:
        
        break;
    
    default:
        cout << " e " << unidade[uC];
        break;
    }
    
    if (uC || cD){
        cout << " Centavos" << endl;
    }
}

//função para dividir o arquivo em partes menores.
void fileToString (string arquivo[]){
    string unidade[10], dezenaAlt[10], dezena[10], centena[10], centenaAlt[2], milhar[2], milhao[3];
    for (int i = 0; i < 10; i++){
        unidade[i] = arquivo[i];
        dezenaAlt [i] = arquivo [i+10];
        dezena [i] = arquivo [i+20];
        centena [i] = arquivo [i+30];
        
    }
    for (int i = 0; i < 2; i++){
        centenaAlt [i] = arquivo [i+40];
        milhar [i] = arquivo [i+42];
    }
    for (int i = 0; i < 3; i++){
        milhao [i] = arquivo [i+44];
    }
    chequeCal (unidade, dezenaAlt, dezena, centena, centenaAlt, milhar, milhao);
}

//função para transferir o conteudo do arquivo para a string.
void readFile (string arquivo[]){

    fstream file;
    string line;
    int fileSize;
    file.open("arquivo.txt", ios:: in);
    if(file.is_open()){
        while(getline(file, line, '\n')){
            arquivo[fileSize] = line;
            fileSize++;
        }
        file.close();
    }
    fileToString(arquivo);
}


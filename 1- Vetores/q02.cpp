#include <iostream>

using namespace std;


bool insertQ02 (){

    int arr[]= {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16}, *tempArr;
    int arrSize = sizeof(arr)/sizeof(*arr);

    //Aloca memória.
    tempArr = new int [arrSize];

    //Verifica se é possivel.
    if (tempArr == NULL)
    {
        cout << "Não é possivel alocar memoria\n";
        exit (1);
    }

    // Copia ao revez os elementos de arr para Temp.
    for (int i = 0; i < arrSize/2; i++)
    {
        tempArr[i] = arr[i+8];
        tempArr[i+8]= arr[i];
    }

    // Arr recebe os valores de temp
    for (int i = 0; i < arrSize; i++)
    {
        arr[i] = tempArr[i];
    }

    //print.
    cout << "A troca dos 8 primeiros elementos pelos 8 ultimo fica: \n{";
    for (int i = 0; i<arrSize; i++){
        cout << arr[i] << ", ";
    }
    cout << "\b\b}";
    //Desaloca memória.
    delete []tempArr;
    return true;
}
    
/*int main(int argc, char const *argv[])
{
    insertQ02();
    return 0;
}*/
#include <iostream>

using namespace std;

void b01 (const int arr[], const int size){
    int num, count = 0, *numF = NULL;
    cout << "procurar no vetor pelo numero: ";
    cin >> num;
    for (int i=0; i<size; i++){
        if (arr[i] == num)
        {
            count++;
            numF = &num;
        }  
    }
    if (numF != NULL){
        cout << "O numero "<< num << " foi enocontrado " << count << endl;
    }else{
        cout << "O numero não foi encontrado no vetor";
    }
     

}
int main(int argc, char const *argv[])
{
    int ar[5] = {1,2,3,4,5};
    int size1 = sizeof(ar)/ sizeof(*ar);
    b01(ar, size1);
    return 0;
}

#include <iostream>

using namespace std;

void b02(int arr[], int const size){
    
    int tmp;
    for (int i = 1; i <size; i++){
        
        for (int j = 0; j <size; j++){
            
            if(arr[j]> arr[i]){
                tmp = arr[j];
                arr[j]= arr[i];
                arr[i] = tmp;
            }
        }
    }
    for (int i = 0; i <size; i++){
        cout << arr[i] << " ";
    }
}

int main(int argc, char const *argv[])
{
    int ar[] = {3,7,5,9,6};
    int size1 = sizeof(ar)/sizeof(*ar);
    b02 (ar, size1);
    return 0;
}

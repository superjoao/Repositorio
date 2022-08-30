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

#include <iostream>

using namespace std;

void merge(int array[], int const left, int const mid, int const right)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;
 
    // Cria ponteiros de vetores temporarios.
    auto *leftArray = new int[subArrayOne], *rightArray = new int[subArrayTwo];
 
    // copia os elementos para os respectivos vetores temporarios.
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];
    
    // indice dos subvetores 1, 2 e merged 
    auto l = 0, r = 0; 
    int m = left; 
 
    // fundi os vetores temporarios ao vetor.
    while (l < subArrayOne && r < subArrayTwo) {
        if (leftArray[l] <= rightArray[r]) {
            array[m] = leftArray[l];
            l++;
        }
        else {
            array[m] = rightArray[r];
            r++;
        }
        m++;
    }
    // Copia os elementos que sobram da esquerda.
    while (l < subArrayOne) {
        array[m] = leftArray[l];
        l++;
        m++;
    }
    // copia os elementos que sobraram da direita.
    while (r < subArrayTwo) {
        array[m] = rightArray[r];
        r++;
        m++;
    }
    delete[] leftArray;
    delete[] rightArray;
}
void mergeSort(int arr[], int const begin, int const end){
    if (begin >= end){return;}

    auto mid = begin + (end - begin)/2;
    mergeSort (arr, begin, mid);
    mergeSort (arr, mid +1, end);
    merge (arr, begin, mid, end);
    
}

int binarySearch(int const a[], int item, int low, int high)
{
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (item == a[mid]){
            cout << "\nO numero "<< item;
            return mid;
            
        }else if (item > a[mid]){
            return binarySearch(a, item, low, mid-1);
        }else{
            return binarySearch(a, item, mid+1, high);
        }
        
    }
    cout << "não encontrado";
    return 0;
}

void printArray(int const a[], int const size){
    for(int i = 0; i <size; i++){
        cout << a[i] << " ";
    }
}
void b03()
{
    int ar[] = {12, 11, 13, 5, 6, 7}, item;
    int size = sizeof(ar)/ sizeof(*ar);

    cout << "O vetor é:\n";
    printArray(ar, size);

    mergeSort(ar, 0, size -1);

    cout << "\nO vetor ordenado fica: \n";
    printArray(ar, size);

    cout << "\nQual numero voce pretende buscar? \n";
    cin >> item;
    binarySearch(ar, item, 0, size-1);

}
int main(int argc, char const *argv[])
{
    b03();
    return 0;
}


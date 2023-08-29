#include <iostream>
#include <string>
using namespace std;

void reverseArray(int arr[], int arrSize);
void removeOdd(int arr[], int& arrSize);
void splitParity(int arr[], int arrSize);
void printArray(int arr1[], int arr1Size);

int main () {
    int arr1[10] = {9, 2, 14, 12, -3};
    int arr1Size = 5;

    int arr2[10] = {21, 12, 6, 7, 14};
    int arr2Size = 5;

    int arr3[10] = {3, 6, 4, 1, 12};
    int arr3Size = 5;

    reverseArray(arr1, arr1Size);
    printArray(arr1, arr1Size);

    removeOdd(arr2, arr2Size);
    printArray(arr2, arr2Size);

    splitParity(arr3, arr3Size);
    printArray(arr3, arr3Size);

    return 0;
}

void printArray(int arr[], int arrSize){
    int i;

    for (i = 0; i < arrSize; i++) {
        cout<<arr[i]<<' ';
    }
    cout<<endl;
}

void reverseArray(int arr[], int arrSize) {
    int temp, i;

    for ( i = 0 ; i < arrSize/2 ; i++ ) {
        temp = arr[i];
        arr[i] = arr[arrSize - ( 1 + i)];
        arr[arrSize - ( 1 + i)] = temp;
    }
}

void removeOdd(int arr[], int& arrSize) {
    int temp, i;

    for ( i = 0 ; i < arrSize ; i++ ) {
        if ( arr[i] % 2 == 1 ) {
            cout<<"arr[i] "<<arr[i]<<endl;
            temp = arr[i];
            arr[i] = arr[arrSize - ( 1 + i)];
            cout<<"arr[i]2 "<<arr[i]<<endl;
            cout<<"arr[arrSize - ( 1 + i)] "<<arr[arrSize - ( 1 + i)]<<endl;
            arr[arrSize - ( 1 + i)] = temp;
            cout<<"arr[arrSize - ( 1 + i)]2 "<<arr[arrSize - ( 1 + i)]<<endl;
            arrSize--;
        }
    }
}

void splitParity(int arr[], int arrSize) {

}
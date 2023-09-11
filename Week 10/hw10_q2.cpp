#include <iostream>
using namespace std;
//Declare functions
int* findMissing(int arr[], int n, int& resArrSize);
//Precondition: An array filled with valid, non-negative integers of size n. The range of values is n+1
//Postcondition: Integers not in the array will be updated and the size of the array changed
bool nonNegative(int arr[], int arrSize);
//Precondition: An array filled with valid, non-negative integers of size n
//Postcondition: Will return false if their exists a non-negative number
void printArray(int* arr, int arrSize);

const int FIRSTARRAYSIZE = 6;

int main() {
    int arr[FIRSTARRAYSIZE] = {3, 1, 3, 0, 6, 4};
    int newArrSize = 0;
    int* arr2 = new int[FIRSTARRAYSIZE];

    if ( !nonNegative(arr, FIRSTARRAYSIZE) ) {
        cout<<"There is a negative number in the array"<<endl;
        return 0;
    }

    arr2 = findMissing(arr, FIRSTARRAYSIZE, newArrSize);

    cout<<"There were "<<newArrSize<<" missing numbers in the sequence and they were: ";

    printArray(arr2, newArrSize);
    delete [] arr2;
    arr2 = nullptr;
    return 0;
}
//Simple function to print an array
void printArray(int* arr, int arrSize) {
    for ( int i = 0; i < arrSize; i++ ) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int* findMissing(int arr[], int n, int& resArrSize) {
    int resSizedArr = 0;
    int* arr2 = new int[n + 1]{0};

    for ( int i = 0; i < n ; i++ ) {
        arr2[arr[i]]++;
    }
    int k = 0;
    for ( int i = 0; i < n + 1; i++ ) {
        if ( arr2[i] == 0 ) {
            k++;
        }
    }
    int* temp = new int[k]{0};
    int j = 0;
    for ( int i = 0; i < n + 1; i++ ) {
        if ( arr2[i] == 0 ) {
            temp[j] = i;
            j++;
        }
    }
    resArrSize = j;
    cout<<resArrSize<<endl;
    printArray(temp, resArrSize);
    
    delete [] arr2;
    arr2 = nullptr;
    return temp;
}

bool nonNegative(int arr[], int arrSize) {
    for ( int i = 0; i < arrSize; i++ ) {
        if ( arr[i] < 0 ) {
            return false;
        }
    }
    return true;
}
#include <iostream>
#include <string>
//Declare functions
int* findMissing(int arr[], int n, int& resArrSize);
//Precondition: An array filled with valid, non-negative integers of size n
//Postcondition: Integers not in the 
void printArray(int arr, int arrSize);

const int FIRSTARRAYSIZE = 6;

int main() {
    int arr[FIRSTARRAYSIZE] = {3, 1, 3, 0, 6, 4};
    int newArrSize = 0;
    int* arr2[newArrSize];

    arr2[newArrSize] = findMissing(arr, FIRSTARRAYSIZE, newArrSize);

    std::cout<<"There were "<<newArrSize<<" missing numbers in the sequence and they were: ";

    for ( int i = 0; i < newArrSize; i++ ) {
        std::cout<<arr2[i]<<" ";
    }
   
}
//Simple function to print an array
void printArray(int* arr, int arrSize) {
    for ( int i = 0; i < arrSize; i++ ) {
        std::cout<<arr[i]<<" ";
    }
    std::cout<<std::endl;
}

int* findMissing(int arr[], int n, int& resArrSize) {
    int resSizedArr = 0;
    int* arrPtr[resArrSize];
    std::string stringArr[n];

    for ( int i = 0; i < n ; i++ ) {
        stringArr[i] = std::to_string(arr[i]);
    }

    for ( int i = 0; i < n; i++ ) {
        std::cout<<stringArr[i]<<" ";
    }

    return arrPtr[resArrSize];
}
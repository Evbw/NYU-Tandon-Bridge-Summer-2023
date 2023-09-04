#include <iostream>
using namespace std;

//Declare functions
int* getPosNums1(int* arr, int arrSize, int& outPosArrSize);
int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr);
void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize);
void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr);
void printArray(int* arr, int arrSize);

const int ARRAYSIZE = 6;

int main() {
    
    int arr[ARRAYSIZE] = {3, -1, -3, 0, 6, 4};
    
    int* posNumsPtr1;
    int posNumsSize1 = 0;
    int* posNumsPtr2;
    int* posNumsPtr3;
    int* posNumsPtr4;

    posNumsPtr1 = getPosNums1(arr, ARRAYSIZE, posNumsSize1);
    
    printArray(posNumsPtr1, posNumsSize1);
}

void printArray(int* arr, int arrSize) {
    for ( int i = 0; i < arrSize; i++ ) {
        cout<<arr[i]<<endl;
    }
}

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize) {
    
    int tempSize = 0;
    int j = 0;

    for ( int i = 0; i < arrSize; i++ ) {
        if ( arr[i] > 0 ) {
            tempSize++;
        }
    }

    int *temp = new int[tempSize];

    for ( int i = 0; i < arrSize; i++ ) {
        if ( arr[i] > 0 ) {
            temp[j] = arr[i];
            j++;
        }
    }
    
    return temp;
}

int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr) {

    return arr;
}

void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize) {
    
    arrSize = outPosArrSize;
}

void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr) {
    outPosArrPtr;
    arrSize = *outPosArrSizePtr;
}
#include <iostream>
using namespace std;

//Declare functions
int* getPosNums1(int* arr, int arrSize, int& outPosArrSize);
int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr);
void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize);
void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr);

const int ARRAYSIZE = 6;

int main() {
    
    int arr[ARRAYSIZE] = {3, -1, -3, 0, 6, 4};
    int outPosArrSize = 0;
    int* posNums1;
    int* posNums2;
    int* posNums3;
    int* posNums4;

    posNums1 = getPosNums1(arr, ARRAYSIZE, outPosArrSize);

    for ( int i = 0; i < outPosArrSize; i++ ) {
        cout<<posNums1[i]<<endl;
    }
}

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize) {
    
    for ( int i = 0; i < arrSize; i++ ) {
        if ( arr[i] > 0 ) {
            outPosArrSize++;
        }
    }
    
    int *temp = new int[outPosArrSize];

    for ( int i = 0; i < arrSize; i++ ) {
        if ( arr[i] > 0 ) {
            temp[i] = arr[i];
        }
    }
    delete[] arr;
    arr = temp;
    return arr;
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
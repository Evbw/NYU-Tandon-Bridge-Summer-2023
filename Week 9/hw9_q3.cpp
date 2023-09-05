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
    int* posNumsSize2 = 0;
    int* posNumsPtr3;
    int posNumsSize3 = 0;
    int** posNumsPtr4;
    int* posNumsSize4;

    posNumsPtr1 = getPosNums1(arr, ARRAYSIZE, posNumsSize1);
    
    printArray(posNumsPtr1, posNumsSize1);
    delete [] posNumsPtr1;
    posNumsPtr1 = nullptr;

    posNumsPtr2 = getPosNums2(arr, ARRAYSIZE, posNumsSize2);
    
    printArray(posNumsPtr2, *posNumsSize2);
    delete [] posNumsPtr2;
    posNumsPtr2 = nullptr;

    // getPosNums3(arr, ARRAYSIZE, posNumsSize3);
    
    // printArray(posNumsPtr1, posNumsSize1);
    // delete [] posNumsPtr1;
    // posNumsPtr1 = nullptr;

    getPosNums4(arr, ARRAYSIZE, posNumsPtr4, posNumsSize4);
}

void printArray(int* arr, int arrSize) {
    for ( int i = 0; i < arrSize; i++ ) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize) {
    
    int tempSize = 0;
    int j = 0;

    for ( int i = 0; i < arrSize; i++ ) {
        if ( arr[i] > 0 ) {
            tempSize++;
        }
    }
    outPosArrSize = tempSize;
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
    
    int j = 0;

    for ( int i = 0; i < arrSize; i++ ) {
        if ( arr[i] > 0 ) {
            *outPosArrSizePtr++;
        }
    }

    int *temp = new int[*outPosArrSizePtr];

    for ( int i = 0; i < arrSize; i++ ) {
        if ( arr[i] > 0 ) {
            temp[j] = arr[i];
            j++;
        }
    }
    return temp;
}

void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize) {
    
    arrSize = outPosArrSize;
}

void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr) {
    // outPosArrPtr;
    // arrSize = *outPosArrSizePtr;

    //    int *outPosArr = new int[arrSize];
    //    outPosArrPtr = &outPosArr;
    // *outPosArrPtr = new int [arrSize];

    // int count = 0;
    // for (int i = 0; i < arrSize; ++i) {
    //     if (arr[i] > 0){
    //         (*outPosArrPtr)[count] = arr[i];
    //         count++;
    //     }
    // }
    // *outPosArrSizePtr = count;

    // printArray(*outPosArrPtr, *outPosArrSizePtr);
    // delete [] *outPosArrPtr;
    // *outPosArrPtr = nullptr;
}
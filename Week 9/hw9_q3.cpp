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
    int* posNumsSize2 = new int;

    int* posNumsArray3 = new int;
    int posNumsSize3 = 0;

    int* posNums4 = nullptr;
    int** posNumsPtr4 = &posNums4;
    int* posNumsSize4 = new int;
 
    posNumsPtr1 = getPosNums1(arr, ARRAYSIZE, posNumsSize1);
    
    cout<<"a) ";
    printArray(posNumsPtr1, posNumsSize1);
    delete [] posNumsPtr1;
    posNumsPtr1 = nullptr;

    posNumsPtr2 = getPosNums2(arr, ARRAYSIZE, posNumsSize2);
    
    cout<<"b) ";
    printArray(posNumsPtr2, *posNumsSize2);
    delete [] posNumsPtr2;
    posNumsPtr2 = nullptr;

    getPosNums3(arr, ARRAYSIZE, posNumsArray3, posNumsSize3);

    getPosNums4(arr, ARRAYSIZE, posNumsPtr4, posNumsSize4);

}

void printArray(int* arr, int arrSize) {
    for ( int i = 0; i < arrSize; i++ ) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize) {
    
    int count = 0;
    int j = 0;

    for ( int i = 0; i < arrSize; i++ ) {
        if ( arr[i] > 0 ) {
            count++;
        }
    }
    outPosArrSize = count;
    int *temp = new int[count];

    for ( int i = 0; i < arrSize; i++ ) {
        if ( arr[i] > 0 ) {
            temp[j] = arr[i];
            j++;
        }
    }

    return temp;
}

int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr) {
    
    int count = 0;
    int j = 0;

    for ( int i = 0; i < arrSize; i++ ) {
        if ( arr[i] > 0 ) {
            count++;
        }
    }

    int *temp = new int[count];
    *outPosArrSizePtr = count;

    for ( int i = 0; i < arrSize; i++ ) {
        if ( arr[i] > 0 ) {
            temp[j] = arr[i];
            j++;
        }
    }

    return temp;
}

void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize) {
    
    int count = 0;
    for ( int i = 0; i < arrSize; i++ ) {
        if ( arr[i] > 0 ) {
            count++;
        }
    }

    int* newPosArr = new int[count];

    int j = 0;
    for ( int i = 0; i < arrSize; i++ ) {
        if (arr[i] > 0){
            newPosArr[j] = arr[i];
            j++;
        }
    }
    outPosArr = newPosArr;
    outPosArrSize = count;
    
    cout<<"c) ";
    printArray(newPosArr, outPosArrSize);
    delete [] newPosArr;
    newPosArr = nullptr;
}

void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr) {

    int count = 0;
    for ( int i = 0; i < arrSize; i++ ) {
        if ( arr[i] > 0 ) {
            count++;
        }
    }

    int *outPosArr = new int[count];
    *outPosArrPtr = new int[count];

    int j = 0;
    for ( int i = 0; i < arrSize; i++ ) {
        if (arr[i] > 0){
            (*outPosArrPtr)[j] = arr[i];
            j++;
        }
    }
    *outPosArrSizePtr = count;

    cout<<"d) ";
    printArray(*outPosArrPtr, *outPosArrSizePtr);
    delete [] *outPosArrPtr;
    *outPosArrPtr = nullptr;
}
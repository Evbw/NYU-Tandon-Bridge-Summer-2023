#include <iostream>
using namespace std;

//Declare functions
int* getPosNums1(int* arr, int arrSize, int& outPosArrSize);
int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr);
void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize);
void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr);
void printArray(int* arr, int arrSize);
//Declare constant array size
const int ARRAYSIZE = 6;

int main() {
    //Declare array of ARRAYSIZE
    int arr[ARRAYSIZE] = {3, -1, -3, 0, 6, 4};
    //Instantiate pointer and size variable for function 1
    int* posNumsPtr1;
    int posNumsSize1 = 0;
    //Instantiate pointer and size pointer for function 2
    int* posNumsPtr2;
    int* posNumsSize2 = new int;
    //Instantiate pointer array and size variable for function 3
    int* posNumsArray3 = new int;
    int posNumsSize3 = 0;
    //Instantiate pointer, double pointer referencing first pointer, and size pointer for function 4
    int* posNums4 = nullptr;
    int** posNumsPtr4 = &posNums4;
    int* posNumsSize4 = new int;
    //Call first function and assign it to first pointer
    posNumsPtr1 = getPosNums1(arr, ARRAYSIZE, posNumsSize1);
    //Print first function
    cout<<"a) ";
    printArray(posNumsPtr1, posNumsSize1);
    //Delete the pointer now that we're done with it, then point it to nullptr
    delete [] posNumsPtr1;
    posNumsPtr1 = nullptr;
    //Call second function and assign it to second pointer
    posNumsPtr2 = getPosNums2(arr, ARRAYSIZE, posNumsSize2);
    //Print second function
    cout<<"b) ";
    printArray(posNumsPtr2, *posNumsSize2);
    //Delete the pointer now that we're done with it, then point it to nullptr
    delete [] posNumsPtr2;
    posNumsPtr2 = nullptr;
    //Call third function
    getPosNums3(arr, ARRAYSIZE, posNumsArray3, posNumsSize3);
    //Call fourth function
    getPosNums4(arr, ARRAYSIZE, posNumsPtr4, posNumsSize4);
}
//Simple function to print output
void printArray(int* arr, int arrSize) {
    for ( int i = 0; i < arrSize; i++ ) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize) {
    //Declare variables to count the number of positive numbers and a secondary one to properly update the array
    int count = 0;
    int j = 0;
    //Increment the count for every positive number
    for ( int i = 0; i < arrSize; i++ ) {
        if ( arr[i] > 0 ) {
            count++;
        }
    }
    //Set the pass-by-reference size to the new count
    outPosArrSize = count;
    //Create new temporary array to the size of the number of existing positive numbers
    int *temp = new int[count];
    //Populate the new array with only positive numbers from the old array. Using the secondary counter will keep the appropriate index
    for ( int i = 0; i < arrSize; i++ ) {
        if ( arr[i] > 0 ) {
            temp[j] = arr[i];
            j++;
        }
    }

    return temp;
}

int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr) {
    //Declare variables to count the number of positive numbers and a secondary one to properly update the array
    int count = 0;
    int j = 0;
    //Increment the count for every positive number
    for ( int i = 0; i < arrSize; i++ ) {
        if ( arr[i] > 0 ) {
            count++;
        }
    }
    //Create new temporary array to the size of the number of existing positive numbers
    int *temp = new int[count];
    //Set the dereferenced size pointer to the new count
    *outPosArrSizePtr = count;
    //Populate the new array with only positive numbers from the old array. Using the secondary counter will keep the appropriate index
    for ( int i = 0; i < arrSize; i++ ) {
        if ( arr[i] > 0 ) {
            temp[j] = arr[i];
            j++;
        }
    }

    return temp;
}

void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize) {
    //Declare variables to count the number of positive numbers and a secondary one to properly update the array
    int count = 0;
    int j = 0;
    //Increment the count for every positive number
    for ( int i = 0; i < arrSize; i++ ) {
        if ( arr[i] > 0 ) {
            count++;
        }
    }
    //Create new temporary array to the size of the number of existing positive numbers
    int* temp = new int[count];    
    //Populate the new array with only positive numbers from the old array. Using the secondary counter will keep the appropriate index
    for ( int i = 0; i < arrSize; i++ ) {
        if (arr[i] > 0){
            temp[j] = arr[i];
            j++;
        }
    }
    //Set the pass-by-reference array to the new array
    outPosArr = temp;
    //Set the pass-by-reference size to the new count
    outPosArrSize = count;
    //Print array and delete the new array
    cout<<"c) ";
    printArray(temp, outPosArrSize);
    delete [] temp;
    temp = nullptr;
}

void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr) {
    //Declare variables to count the number of positive numbers and a secondary one to properly update the array
    int count = 0;
    int j = 0;
    //Increment the count for every positive number
    for ( int i = 0; i < arrSize; i++ ) {
        if ( arr[i] > 0 ) {
            count++;
        }
    }
    //Sett thed array double pointer to the size of the number of existing positive numbers
    *outPosArrPtr = new int[count];
    //Populate the new array with only positive numbers from the old array. Using the secondary counter will keep the appropriate index
    for ( int i = 0; i < arrSize; i++ ) {
        if (arr[i] > 0){
            (*outPosArrPtr)[j] = arr[i];
            j++;
        }
    }
    //Set the dereferenced size pointer to the new count
    *outPosArrSizePtr = count;
    //Print array and delete the new array
    cout<<"d) ";
    printArray(*outPosArrPtr, *outPosArrSizePtr);
    delete [] *outPosArrPtr;
    *outPosArrPtr = nullptr;
}
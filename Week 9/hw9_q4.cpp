#include <iostream>
using namespace std;

void oddsKeepEvensFlip(int arr[], int arrSize);
const int ARRAYSIZE = 6;

int main() {
    int arr[] = {5, 2, 11, 7, 6, 4};

    oddsKeepEvensFlip(arr, ARRAYSIZE);
}

void oddsKeepEvensFlip(int arr[], int arrSize) {
    
    int zeroindex = 0;
    int lastindex = arrSize - 1;
    int temp[arrSize] = {};

    for ( int i = 0; i < arrSize; i++ ) {
        if ( arr[i] % 2 == 1 ) {
            temp[zeroindex] = arr[i];
            zeroindex++;
        }
        else {
            temp[lastindex] = arr[i];
            lastindex--;
        }
    }

    for ( int i = 0; i < arrSize; i++ ) {
        arr[i] = temp[i];
    }

    for ( int i = 0; i < arrSize; i++ ) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
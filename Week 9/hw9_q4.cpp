#include <iostream>
using namespace std;
//Instantiate the requested function
void oddsKeepEvensFlip(int arr[], int arrSize);
//Instantiate a const int array size
const int ARRAYSIZE = 6;

int main() {
    //Declare an array with the appropriate array size and populate it with sample numbers
    int arr[ARRAYSIZE] = {5, 2, 11, 7, 6, 4};
    //Call function using the array and its size
    oddsKeepEvensFlip(arr, ARRAYSIZE);
    return 0;
}

void oddsKeepEvensFlip(int arr[], int arrSize) {
    //Declare variables for the first index, last index, and a new empty array of the same size
    int zeroindex = 0;
    int lastindex = arrSize - 1;
    int temp[arrSize] = {};
    //Loop through the array and if an element is odd, move it to the front of the temporary array and increase index counter
    for ( int i = 0; i < arrSize; i++ ) {
        if ( arr[i] % 2 == 1 ) {
            temp[zeroindex] = arr[i];
            zeroindex++;
        }
    //If the element is even, move it to the back of the array and decrease the counter
        else {
            temp[lastindex] = arr[i];
            lastindex--;
        }
    }
    //Reassign the numbers in the array
    for ( int i = 0; i < arrSize; i++ ) {
        arr[i] = temp[i];
    }
    //Print the array elements
    for ( int i = 0; i < arrSize; i++ ) {
        cout<<arr[i]<<" ";
    }
}
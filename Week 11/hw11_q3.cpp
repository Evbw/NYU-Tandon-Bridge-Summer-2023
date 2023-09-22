#include <iostream>
using namespace std;

int minInArray1(int arr[], int arrSize);
//Precondition: arr is filled with valid integers of arrSize
//Postcondition: The minimum value element will be returned
int minInArray2(int arr[], int low, int high);
//Precondition: arr is filled with valid integers and a low point of the array and a high point of the array to check
//Postcondition: The minimum value element will be returned

int main() {
    int arr[10] = {9, -2, 14, 12, 3, 6, 2, 1, -9, 15};
    int res1, res2, res3, res4;

    res1 = minInArray1(arr, 10);
    res2 = minInArray2(arr, 0, 9);
    cout<<res1<<" "<<res2<<endl; //should both be -9

    res3 = minInArray2(arr, 2, 5);
    res4 = minInArray1(arr+2, 4); //arr+2 is equivalent to &(arr[2])
    cout<<res3<<" "<<res4<<endl; //should both be 3

    return 0;
}

int minInArray1(int arr[], int arrSize) {
    //Declare a variable of the lowest amount. I'm moving through the array backwards, so currently the minimum
    //is the last element in the array
    int min = arr[arrSize - 1];
    //Base case. If we reach the first element of the array, return it
    if ( arrSize == 1 ) {
        return arr[0];
    }
    else {
        //If the current minimum is smaller than the element before it, return it. Otherwise, return the other one
        if ( min < arr[arrSize - 2] ) {
            return min;
        }
        else {
            return arr[arrSize - 2];
        }
        //We return the smallest value through multiple recursive calls
        min = minInArray1 (arr, arrSize - 1);
    }
    //Return the minimum value
    return min;
}

int minInArray2(int arr[], int low, int high) {
    //Declare a variable of the lowest amount. I'm moving through the array from the front, so I set it to the lowest
    //element in the array
    int min = arr[low];
    //Base case. If the low value climbs higher than the high, then return the last element in the array
    if ( low >= high ) {
        return arr[high - 1];
    }
    //Otherwise, we go to the front of the array to find the smallest value. If that's smaller than the next element
    //return it. Otherwise we return the next value, as it is smaller
    else {
        min = minInArray2(arr, low + 1, high);
        if ( min < arr[low + 1] ) {
            return min;
        }
        else {
            return arr[low + 1];
        }
    }
    //Return the minimum value
    return min;
}

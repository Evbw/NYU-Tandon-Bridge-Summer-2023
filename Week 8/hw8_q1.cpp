#include <iostream>
using namespace std;
//Initialize constant
const int ARRAYSIZE = 20;
//Initialize functions
int minInArray(int arr[ARRAYSIZE], int arrSize);
//Precondition: The array is correctly filled with int values.
//Postcondition: The smallest integer is determined and returned.
void indexLocations(int arr[ARRAYSIZE], int num, int indexLocation);
//Precondition: The array is correctly filled with int values and num and smol are ints.
//Postcondition: The index values of the smallest integer is determined and returned.

int main () {
    //Initialize main function variables
    int arr[ARRAYSIZE];
    int arrSize = ARRAYSIZE, i = 0, minInput = 0;
    int smol = 0;
    //Request user input
    cout<<"Please enter 20 integers separated by a space:"<<endl;
    //Cycle through the user input for each element in the array
    while ( i < ARRAYSIZE ) {
        cin>>arr[i];
        i++;
    }
    //Call minInput function
    minInput = minInArray(arr, arrSize);
    //Display output
    cout<<"The minimum value is "<<minInput<<", and it is located in the following indices:";
    //Call indexLocations function as part of the print
    indexLocations(arr, minInput, smol);
    cout<<endl;
}

int minInArray(int arr[], int arrSize) {
    //Initialize variables, one for loop and one to return
    int smallArr = 0, i;
    //Begin loop to determine the smallest element of the array
    for ( i = 0; i < arrSize; i++ ) {
        if ( i == 0 ) {
            smallArr = arr[i];
        }
        else if ( arr[i] < smallArr ) {
            smallArr = arr[i];
        }
    }
    //Return the smallest element of the array
    return smallArr;
}

void indexLocations(int arr[], int num, int indexLocation) {
    //Begin loop to print the locations of the element
    for ( int i = 0; i < ARRAYSIZE; i++ ) {
        if ( arr[i] == num ) {
            cout<<" "<<i;
        }
    }
}
#include <iostream>
using namespace std;

const int ARRAYSIZE = 20;

int minInArray(int arr[ARRAYSIZE], int arrSize);
void indexLocations(int arr[ARRAYSIZE], int num, int indexLocation);

int main () {
    int arr[ARRAYSIZE];
    int arrSize = ARRAYSIZE, i = 0, minInput = 0;
    int smol = 0;

    cout<<"Please enter 20 integers separated by a space:"<<endl;
    
    while ( i < ARRAYSIZE ) {
        cin>>arr[i];
        i++;
    }

    minInput = minInArray(arr, arrSize);

    cout<<"The minimum value is "<<minInput<<", and it is located in the following indices:";
    indexLocations(arr, minInput, smol);
    cout<<endl;
}

int minInArray(int arr[], int arrSize) {
    int smallArr = 0, i;
    
    for ( i = 0; i < arrSize; i++ ) {
        if ( i == 0 ) {
            smallArr = arr[i];
        }
        else if ( arr[i] < smallArr ) {
            smallArr = arr[i];
        }
    }
    return smallArr;
}

void indexLocations(int arr[], int num, int indexLocation) {

    for ( int i = 0; i < ARRAYSIZE; i++ ) {
        if ( arr[i] == num ) {
            cout<<" "<<i;
        }
    }
}
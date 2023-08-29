#include <iostream>
using namespace std;

const int ARRAYSIZE = 20;

int minInArray(int arr[ARRAYSIZE], int arrSize);
void indexLocations(int arr[ARRAYSIZE], int num, int indexLocation);

int main () {
    int arr[5];
    int arrSize = 5, i = 0, minInput = 0;
    int indices;
    int smol = 0, temp = 0;

    cout<<"Please enter 20 integers separated by a space:"<<endl;
    
    while ( i < 5 ) {
        cin>>arr[i];
        i++;
    }

    minInput = minInArray(arr, arrSize);

    cout<<"The minimum value is "<<minInput<<", and it is located in the following indices:"<<indexLocations(arr, minInput, smol)<<endl;

}

int minInArray(int arr[], int arrSize) {
    int smallArr = 0, i = 0;
    
    for ( i = 0; i < arrSize; i++ ) {
        if ( i == 0 ) {
            smallArr = arr[i];
        }
        else if ( arr[i] < arr[i-1] ) {
            smallArr = arr[i];
        }
    }

    return smallArr;
}

// int minimumFinder(int min, int indexLocation, int& temp) {

//     if ( indexLocation == 0 ) {
//         temp = min;
//         cout<<temp<<endl;
//     }
//     else if ( min < temp ) {
//         temp = min;
//     }

//     return temp;
// }

void indexLocations(int arr[], int num, int indexLocation) {

    for ( int i = 0; i < 5; i++ ) {
        if ( arr[i] == num ) {
            cout<<" "<<i;
        }
    }
}
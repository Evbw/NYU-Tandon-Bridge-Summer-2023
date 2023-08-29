#include <iostream>
#include <string>
using namespace std;

int minInArray(int arr[20], int arrSize);
int indexLocation(int min, string& location);

int main () {
    int arr[20];
    int arrSize = 20, i = 0, minInput = 0;
    int indices;
    string location;

    cout<<"Please enter 20 integers separated by a space:"<<endl;
    
    while ( i < 20 ) {
        cin>>arr[i];
        i++;
    }

    minInput = minInArray(arr, arrSize);

}

int minInArray(int arr[], int arrSize) {
    int smallArr;

    for ( int i = 0; i < arrSize; i++ ) {
        if ( i = 0 ) {
            smallArr = arr[i];
            indexLocation(min,location);
        }
        else if ( arr[i] < arr[i-1] ) {
            smallArr = arr[i];
            indexLocation(min,location);
        }
    }

    return smallArr;
}

int indexLocation(int min, string& location) {

}
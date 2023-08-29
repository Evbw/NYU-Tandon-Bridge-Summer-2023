#include <iostream>
#include <string>
using namespace std;

int minInArray(int arr[3], int arrSize);
int minimumFinder(int min, int& newMin);

const int ARRSIZE = 20;

int main () {
    int arr[5];
    int arrSize = 5, i = 0, minInput = 0;
    int indices;
    int smol = 0;
    int test1 = 45, test2 = 5, test3 = 5, test4 = 99, test5 = 5;

    cout<<"Please enter 20 integers separated by a space:"<<endl;
    
    while ( i < 5 ) {
        cin>>arr[i];
        i++;
    }

    for ( i = 0; i < 5; i++ ) {
        smol = minimumFinder(arr[i], i);
    }

    // minInput = minInArray(arr, arrSize);

    cout<<"The minimum value is "<<minInput<<", and it is located in the following indices: 45"<<endl;

}

int minInArray(int arr[], int arrSize) {
    int smallArr = 0, i = 0;
    string str;

    for ( i = 0; i < arrSize; i++ ) {
        if ( i == 0 ) {
            smallArr = arr[i];
            // str = to_string(i);
            // minimumFinder(smallArr, str);
        }
        else if ( arr[i] < arr[i-1] ) {
            smallArr = arr[i];
            // str = to_string(i);
            // minimumFinder(smallArr, str);
        }
    }

    return smallArr;
}

int minimumFinder(int min, int& newMin) {
    int temp = 0;

    if ( newMin == temp ) {
        newMin = min;
    }
    else if ( min < newMin ) {
        newMin = min;
    }

    return newMin;
}
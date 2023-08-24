#include <iostream>
using namespace std;

int search ( int array[10], int size, int x );

int main() {
    int arr[9] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    int x;
    cout<<"Please enter a number to see if it exists in the array: "<<endl;
    cin>>x;

    cout<<search(arr, sizeof(arr)/sizeof(arr[0]), x)<<endl;
    return 0;
}

int search ( int array[9], int size, int x) {
    int low = 0;
    int high = size - 1;

    while ( low <= high ) {
        int mid = ( low + high ) / 2;
        if ( x == array[mid] ) {
            return mid;
        }
        else if ( x > array[mid] ) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1;  
}
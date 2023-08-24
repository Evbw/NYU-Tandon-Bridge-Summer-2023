#include <iostream>
using namespace std;

int search ( int array[10], int size, int x );

int main() {
    int arr[10] = {10, 20, 5, -5, 6, 7, 25, 61, 9, 15};
    int x;
    cout<<"Please enter a number to see if it exists in the array: "<<endl;
    cin>>x;

    cout<<search(arr, sizeof(arr)/sizeof(arr[0]), x)<<endl;
    return 0;
}

int search ( int array[10], int size, int x) {
    
    for ( int i = 0; i < size; i++ ) {
        if ( x == array[i] ) {
            return i;
        }
    }
    return -1;
    
}
#include <iostream>
#include <string>
using namespace std;

int minInArray(int arr[3], int arrSize);
int indexLocation(int min, string& location);

int main () {
    int arr[3];
    int arrSize = 20, i = 0, minInput = 0;
    int indices;
    string location;

    cout<<"Please enter 20 integers separated by a space:"<<endl;
    
    while ( i < 3 ) {
        cin>>arr[i];
        i++;
    }

    minInput = minInArray(arr, arrSize);

    cout<<"The minimum value is "<<minInput<<", and it is located in the following indices: 1 3 6 14"<<endl;

}

int minInArray(int arr[], int arrSize) {
    int smallArr, i = 0;
    string str;

    smallArr = arr[i];

    // if ( i = 0 ) {
    //     smallArr = arr[i];
    // }
    // else if ( arr[i] < arr[i-1] ) {
    //     smallArr = arr[i];
    // }

    // for ( i = 0; i < arrSize; i++ ) {
    //     // if ( i = 0 ) {
    //     //     smallArr = arr[i];
    //     //     // str = to_string(i);
    //     //     // indexLocation(smallArr, str);
    //     // }
    //     // else if ( arr[i] < arr[i-1] ) {
    //     //     smallArr = arr[i];
    //     //     // str = to_string(i);
    //     //     // indexLocation(smallArr, str);
    //     // }
    // }

    return smallArr;
}

// int indexLocation(int min, string& location) {
//     int newMin = 0;
//     string temp;

//     if ( min == newMin ) {
//         temp = to_string(min);
//         location = location + " " + temp;
//     }
//     else if ( min < newMin ) {
//         temp = to_string(min);
//         location = "";
//         location = temp;
//     }

//     return location;
// }
#include <iostream>
using namespace std;

int jumpIt (int arr[], int arrSize);

const int ARRSIZE = 6;
const int ARRSIZE2 = 9;

int main() {
    int arr[ARRSIZE] = {0, 3, 80, 6, 57, 10};
    int arr2[ARRSIZE2] = {0, 3, 80, 100, 100, 100, 6, 57, 10};
    int n;

    n = jumpIt (arr, ARRSIZE);
    cout<<n<<endl;
    n = jumpIt (arr2, ARRSIZE2);
    cout<<n<<endl;
}

int jumpIt (int arr[], int arrSize) {
    int jump = 0;

    if ( arrSize <= 1 ) {
        return arr[0];
    }
    else {
        if ( (arr[arrSize - 1] + arr[arrSize - 2]) < (arr[arrSize - 1] + arr[arrSize - 3])) {
            jump = arr[arrSize - 1] + jumpIt(arr, arrSize - 1);
        }
        else {
            jump = arr[arrSize - 1] + jumpIt(arr, arrSize - 2);
        }
    }
    return jump;
}
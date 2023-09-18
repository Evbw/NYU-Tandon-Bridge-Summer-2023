#include <iostream>
using namespace std;

int jumpIt (int arr[], int arrSize);

const int ARRSIZE = 6;

int main() {
    int arr[ARRSIZE] = {0, 3, 80, 6, 57, 10};
    int n;

    n = jumpIt (arr, ARRSIZE);

    cout<<n<<endl;
}

int jumpIt (int arr[], int arrSize) {
    int temp = 0;
    int index = 0;

    if ( temp >= arrSize ) {
        return arr[arrSize -1];
    }
    else if ( arr[index + 1] < arr[index + 2])  {
        temp = jumpIt(arr+1, arrSize);
        index++;
        return arr[index + 1];
    }
    else if ( arr[index + 2] < arr[index + 1])  {
        temp = jumpIt(arr+2, arrSize);
        index++;
        return arr[index + 2];
    }
    return temp;
}
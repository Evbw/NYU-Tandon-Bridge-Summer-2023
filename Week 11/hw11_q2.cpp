#include <iostream>
using namespace std;

int sumOfSquares(int arr[], int arrSize);
// bool isSorted(int arr[], int arrSize);

int main() {
    int arr[4] = {2, -1, 3, 10};
    int sum = 0;
    sum = sumOfSquares(arr, 4);
    cout<<sum<<endl;

}

int sumOfSquares(int arr[], int arrSize) {
    int sum = 0;

    if (arrSize == 1) {
        return arr[0]*arr[0];
    }
    else {
        sum += sumOfSquares (arr, arrSize - 1);
        sum += arr[arrSize-1]*arr[arrSize-1];
    }
    return sum;
}

// bool isSorted(int arr[], int arrSize) {
    
// }

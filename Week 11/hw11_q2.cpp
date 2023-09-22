#include <iostream>
using namespace std;

int sumOfSquares(int arr[], int arrSize);
bool isSorted(int arr[], int arrSize);

int main() {
    int arr[4] = {2, -1, 3, 10};
    int arr2[8] = {-200, -150, -43, 3, 10, 11, 11, 84};
    int sum = 0;
    
    sum = sumOfSquares(arr, 4);
    cout<<sum<<endl;

    sum = sumOfSquares(arr2, 8);
    cout<<sum<<endl;

    if (isSorted(arr, 4)) {
        cout<<"good job"<<endl;
    }
    else {
        cout<<"aww beans"<<endl;
    }

    if (isSorted(arr2, 8)) {
        cout<<"good job"<<endl;
    }
    else {
        cout<<"aww beans"<<endl;
    }

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

bool isSorted(int arr[], int arrSize) {
    bool truthiness;

    if ( arrSize == 1 ){
        return true;
    }
    else {
        if ( arr[arrSize-1] < arr[arrSize-2] ) {
            return false;
        }
        truthiness = isSorted(arr, arrSize - 1);
    }

    return truthiness;
}

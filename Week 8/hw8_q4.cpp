#include <iostream>
using namespace std;

const int PIN[5] = {2, 1, 1, 3, 5};

void encryptedPIN (int arr[], int arrSize);
int getRandom(int arr[], int arrSize);

int main () {
    int num[10];
    int digits[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int numSize = 10, digitsSize = 10;
    srand(time(0));

    num[10] = getRandom(num, numSize);

    cout<<"PIN:\t";
    for ( int i = 0; i < digitsSize; i++ ) {
        cout<<digits[i]<<'\t';
    }

}

int getRandom(int arr[], int arrSize) {
    for ( int i = 0; i < arrSize; i++ ) {
        arr[i] = ( rand() % 3 ) + 1;
    }
    return arr[10];
}
#include <iostream>
using namespace std;

const int PIN[5] = {2, 1, 1, 3, 5};

void encryptedPIN (int arr[], int arrSize);
int getRandom(int arr[], int arrSize);

int main () {
    int num[10];
    int numSize = 10;
    srand(time(0));

    num[10] = getRandom(num, numSize);

    for ( int i = 0; i < numSize; i++ ) {
        cout<<num[i]<<"\t";
    }

}

int getRandom(int arr[], int arrSize) {
    for ( int i = 0; i < arrSize; i++ ) {
        arr[i] = ( rand() % 3 ) + 1;
    }
    return arr[10];
}
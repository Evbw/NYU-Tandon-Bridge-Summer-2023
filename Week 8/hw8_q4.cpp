#include <iostream>
using namespace std;

const int PIN = {2, 1, 1, 3, 5}

void encryptedPIN (int arr[], int arrSize);

int main () {
    int num[10];
    int numSize = 10;
    srand(time(0));

    for ( int i = 0; i < numSize; i++ ) {
        num[i] = rand() % 4;
    }

}
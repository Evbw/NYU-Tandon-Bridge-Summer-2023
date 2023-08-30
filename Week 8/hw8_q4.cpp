#include <iostream>
using namespace std;

const int PIN[5] = {2, 6, 1, 3, 5};
const int PINSIZE = 5;

void encryptedPIN (int arr[], int arr2[], int arr3[], int arrSize, int arrSize2, int arrSize3);
int getRandom(int arr[], int arrSize);
void splitEntry(int arr[], int num, int arrSize);

int main () {
    int num[10];
    int digits[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int entry[5];
    int numSize = 10, digitsSize = 10, entrySize = 5;  
    int input;  
    srand(time(0));

    num[10] = getRandom(num, numSize);

    cout<<"Please enter your PIN according to the following mapping:"<<endl;
    cout<<"PIN:\t";
    for ( int i = 0; i < digitsSize; i++ ) {
        cout<<digits[i]<<" ";
    }
    cout<<endl;
    cout<<"NUM:\t";
    for ( int i = 0; i < numSize; i++ ) {
        cout<<num[i]<<" ";
    }
    cout<<endl;
    cin>>input;

    splitEntry(entry, input, entrySize);

    encryptedPIN (num, digits, entry, numSize, digitsSize, entrySize);

}

int getRandom(int arr[], int arrSize) {
    for ( int i = 0; i < arrSize; i++ ) {
        arr[i] = ( rand() % 3 ) + 1;
    }
    return arr[10];
}

void splitEntry(int arr[], int num, int arrSize) {

    for ( int i = arrSize - 1; i > 0 ; i-- ) {
        arr[i] = num % 10;
        num /= 10;
        if ( num < 10 ) {
            arr[i-1] = num;
        }
    }

}

void encryptedPIN (int arr[], int arr2[], int arr3[], int arrSize, int arrSize2, int arrSize3) {
    int pin = 0;

    for ( int i = 0; i < arrSize1; i++ ) {
        for ( int j = 0; j < arrSize2; j++ ) {
            if ( i == j && PIN[i] == arr2[j] ) {
                pin = 10 * pin + PIN[i];
            }
        }
    }
    cout<<pin<<endl;
}
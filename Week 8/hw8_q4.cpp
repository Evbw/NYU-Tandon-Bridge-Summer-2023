#include <iostream>
using namespace std;

const int PIN[5] = {9, 9, 9, 9, 9};
const int PINSIZE = 5;

void encryptedPIN (int arr[], int arr2[], int arr3[], int arrSize, int arrSize2, int arrSize3);
int getRandom(int arr[], int arrSize);
void splitEntry(int arr[], int num, int arrSize);

int main () {
    int num[10];
    int digits[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int entry[5];
    int array[5];
    int numSize = 10, digitsSize = 10, entrySize = 5, arraySize = 5;
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

    if ( input > 99999 ) {
        cout<<"Your PIN is not correct"<<endl;
        return 0;
    }

    splitEntry(entry, input, entrySize);

    encryptedPIN (num, digits, entry, numSize, digitsSize, entrySize);

    return 0;
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
    int PINcheck[5];
    int PINchecksize = 5;

    for ( int i = 0; i < PINchecksize; i++ ) {
        pin = 10 * pin + arr[PIN[i]];
    }
    cout<<pin<<endl;
    for ( int i = 0; i < arrSize; i++ ) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    splitEntry(PINcheck, pin, PINchecksize);

    for ( int i = 0; i < PINchecksize; i++ ) {
        cout<<PINcheck[i]<<" ";
    }
    cout<<endl;
    if ( PIN[0] == PINcheck[0] && PIN[1] == PINcheck[1] && PIN[2] == PINcheck[2] && PIN[3] == PINcheck[3] && PIN[4] == PINcheck[4] ) {
        cout<<"Your PIN is correct"<<endl;
    }
    else {
        cout<<"Your PIN is not correct"<<endl;
    }
}
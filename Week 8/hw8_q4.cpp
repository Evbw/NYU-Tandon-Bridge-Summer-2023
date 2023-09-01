#include <iostream>
using namespace std;
//Initialize PIN as a constant array and its size as a constant int
const int PIN[5] = {1, 2, 3, 4, 5};
//Initialize functions
void encryptedPIN (int arr[], int userInput, int arrSize);
//Precondition: The array is filled with valid values
//Postcondition: The user's input is matched against the positions of the array
int getRandom(int arr[], int arrSize);
//Precondition: The array is filled with valid values
//Postcondition: The user's input is matched against the positions of the array

int main () {
    //Initialize arrays for random numbers and the digits 0-9
    int randomNum[10];
    int digits[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    //Initialize array sizes
    int randomNumSize = 10, digitsSize = 10;
    //Initialize variable for user input
    int input;
    //Start random time function
    srand(time(0));
    //Populate the random number array with random numbers 1-3
    randomNum[10] = getRandom(randomNum, randomNumSize);
    //Request user input and display possible values for 0-9 as encrypted input
    cout<<"Please enter your PIN according to the following mapping:"<<endl;
    cout<<"PIN:\t";
    for ( int i = 0; i < digitsSize; i++ ) {
        cout<<digits[i]<<" ";
    }
    cout<<endl;
    cout<<"NUM:\t";
    for ( int i = 0; i < randomNumSize; i++ ) {
        cout<<randomNum[i]<<" ";
    }
    cout<<endl;
    //Get input
    cin>>input;
    //Handle edge case where the PIN is more than 4 digits.
    if ( input > 99999 ) {
        cout<<"Your PIN is not correct"<<endl;
        return 0;
    }
    //Check the input and confirm if it is correct
    encryptedPIN (randomNum, input, randomNumSize);
    return 0;
}

int getRandom(int arr[], int arrSize) {
    //Begin loop to randomize elements to between 1 and 3
    for ( int i = 0; i < arrSize; i++ ) {
        arr[i] = ( rand() % 3 ) + 1;
    }
    //Return the array
    return arr[10];
}

void encryptedPIN (int arr[], int userInput, int arrSize) {
    //Initialize variable to check values for the pin
    int pin = 0;
    //Begin loop. We check for the value of the PIN once per loop and use that value as the index for the array.
    //Multiply the pin by 10 and add the new number to get a matching input (if the pin is correct)
    for ( int i = 0; i < arrSize/2; i++ ) {
        pin = 10 * pin + arr[PIN[i]];
    }
    //Print output if the pin and the input match
    if ( pin == userInput ) {
        cout<<"Your PIN is correct"<<endl;
    }
    else {
        cout<<"Your PIN is not correct"<<endl;
    }
}
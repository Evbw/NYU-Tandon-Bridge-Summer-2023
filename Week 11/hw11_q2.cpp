#include <iostream>
using namespace std;
//Initialize functions
int sumOfSquares(int arr[], int arrSize);
//Precondition: arr is filled with valid integers of arrSize
//Postcondition: The squares of every individual element will be added together
bool isSorted(int arr[], int arrSize);
//Precondition: arr is filled with valid integers of arrSize
//Postcondition: The function will return a true/false statement depending on if the elements are in ascending order

int main() {
    //Declare arrays, one sorted for testing the isSorted function
    int arr[4] = {2, -1, 3, 10};
    int arr2[8] = {-200, -150, -43, 3, 10, 11, 11, 84};
    //Print out the results of the sumOfSquares function
    cout<<sumOfSquares(arr, 4)<<endl;
    cout<<sumOfSquares(arr2, 8)<<endl;
    //Print out the results of the isSorted function
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
    //Declare variable for returning the sums of the squares
    int sum = 0;
    //Base case. If we're on the last element, multiply it by itself
    if (arrSize == 1) {
        return arr[0]*arr[0];
    }
    //Otherwise we add the results of the recursive call to sum and then add the sum of the following two elements squared
    else {
        sum += sumOfSquares (arr, arrSize - 1);
        sum += arr[arrSize-1]*arr[arrSize-1];
    }
    //Return the value
    return sum;
}

bool isSorted(int arr[], int arrSize) {
    //Declare a variable to hold the boolean value
    bool truthiness;
    //Base case. If the size is 1, then we got here by everything else being sorted
    if ( arrSize == 1 ){
        return true;
    }
    //Otherwise, we see if the the value of the last element in the array is smaller than the element preceeding it
    else {
        if ( arr[arrSize-1] < arr[arrSize-2] ) {
            return false;
        }
        //If it's not, then we recall the function again
        truthiness = isSorted(arr, arrSize - 1);
    }
    //Return the value
    return truthiness;
}

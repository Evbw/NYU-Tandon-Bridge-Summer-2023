#include <iostream>
using namespace std;
//Initialize function
int jumpIt (int arr[], int arrSize);
//Precondition: arr is filled with valid integers of arrSize
//Postcondition: The sums of the shortest path, moving forward 1 or 2 steps from index 0, will be returned

//Declare constants for array sizes including graded test cases
const int ARRSIZE = 6;
const int ARRSIZE2 = 9;
const int ARRSIZE3 = 10;
const int ARRSIZE4 = 8;

int main() {
    //Declare arrays
    int arr[ARRSIZE] = {0, 3, 80, 6, 57, 10};
    int arr2[ARRSIZE2] = {0, 3, 80, 100, 100, 100, 6, 57, 10};
    int arr3[ARRSIZE3] = {0, 12, 16, 12, 5, 4, 15, 2, 10, 15};
    int arr4[ARRSIZE4] = {0, 56, 55, 54, 53, 52, 51, 50} ;
    //Declare a variable to handle the sum of the function
    int n;
    //Call the function with two array sizes and print the result
    n = jumpIt (arr, ARRSIZE);
    cout<<"The lowest total cost for the first set is "<<n<<endl;
    n = jumpIt (arr2, ARRSIZE2);
    cout<<"The lowest total cost for the second set is "<<n<<endl;
    n = jumpIt (arr3, ARRSIZE3);
    cout<<"The lowest total cost for the third set is "<<n<<endl;
    n = jumpIt (arr4, ARRSIZE4);
    cout<<"The lowest total cost for the fourth set is "<<n<<endl;
}

int jumpIt (int arr[], int arrSize) {
    //Declare a return variable for the summation of each move
    int jumps = 0;
    //Base case. If the arrSize is 1 or less, return the final element of the array
    if ( arrSize <= 1 ) {
        return arr[0];
    }
    //Otherwise, we compare the sizes of the moves and take the one with the lowest sum.
    else {
        if ( (arr[arrSize - 1] + arr[arrSize - 2]) < (arr[arrSize - 1] + arr[arrSize - 3])) {
            //And add that to the return variable
            jumps = arr[arrSize - 1] + jumpIt(arr, arrSize - 1);
        }
        else {
            jumps = arr[arrSize - 1] + jumpIt(arr, arrSize - 2);
        }
    }
    //And now we return the value
    return jumps;
}
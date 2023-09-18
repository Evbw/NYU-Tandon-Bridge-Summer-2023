#include <iostream>
using namespace std;

int jumpIt (int arr[], int arrSize);

const int ARRSIZE = 6;

int main() {
    int arr[ARRSIZE] = {0, 3, 80, 6, 57, 10};
    int n;

    n = jumpIt (arr, ARRSIZE);
    
    cout<<n<<endl;
}

int jumpIt (int arr[], int arrSize) {
    int temp = 0;
    int count = 0;

    if ( temp >= arrSize ) {
        return arr[arrSize -1];
    }
    else if ( arr[count + 1] < arr[count + 2])  {
        temp = jumpIt(arr+1, arrSize);
        count++;
        return temp;
    }
    else if ( arr[count + 2] < arr[count + 1])  {
        temp = jumpIt(arr+2, arrSize);
        count++;
        return temp;
    }
    return temp;
}
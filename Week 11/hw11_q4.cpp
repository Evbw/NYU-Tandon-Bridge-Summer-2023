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
    int jump = 0;

    if ( arrSize <= 2 ) {
        cout<<"arrSize "<<arrSize<<endl;
        return arr[0];
    }
    else {
        if ( (arr[arrSize - 1] + arr[arrSize - 2]) < (arr[arrSize - 1] + arr[arrSize - 3])) {
            // jump = arr[arrSize - 1] + arr[arrSize - 2];
            jump = arr[arrSize - 1] + jumpIt(arr, arrSize - 2);
            cout<<"jumpif "<<jump<<endl;
        }
        else {
            // jump = arr[arrSize - 1] + arr[arrSize - 3];
            jump = arr[arrSize - 1] + jumpIt(arr, arrSize - 3);
            cout<<"jumpelse "<<jump<<endl;
        }
    }
    return jump;
}
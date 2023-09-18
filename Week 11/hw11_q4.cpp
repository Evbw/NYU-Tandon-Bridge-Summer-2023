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
    int temp = arr[arrSize - 1];
    int index = arrSize - 1;

    if ( arr[index - 2] < 0 ) {
        return arr[index - 1];
    }

    if ( arr[arrSize] == 1 ) {
        return arr[0];
    }
    else if ( arr[index - 1] < arr[index - 2])  {
        cout <<"first else if "<<arr[index - 1]<<endl;
        cout <<"first else if "<<arr[index - 2]<<endl;
        temp += jumpIt(arr, arrSize - 1);
        index++;
        return temp;
    }
    else if ( arr[index - 2] < arr[index - 1])  {
        cout <<"second else if "<<arr[index - 1]<<endl;
        cout <<"second else if "<<arr[index - 2]<<endl;
        temp += jumpIt(arr, arrSize - 2);
        cout <<"second else if "<<temp<<endl;
        index++;
        return temp;
    }
    return temp;
}
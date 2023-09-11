#include <iostream>
#include <vector>
using namespace std;

int main1();
int main2();
void printArray(int* arr, int arrSize);

const int ARRAYSIZE = 10;

int main() {

    cout<<"Non-vector version: "<<endl;
    main1();

    // cout<<"Vector version: "<<endl;
    // main2();
}

int main1() {
    int n, searchn;
    int* arr = new int[ARRAYSIZE]();
    int* searchArr = new int[ARRAYSIZE]();
    int newArraySize = 1;

    cout<<"Please enter a sequence of positive integers, each in a separate line."<<endl;
    cout<<"End you input by typing -1."<<endl;
    cin>>n;

    int i = 0;
    while ( n > -1 ) {
        arr[i] = n;
        cin>>n;
        i++;
        newArraySize++;       
    }

    cout<<"Please enter a number you want to search."<<endl;
    cin>>searchn;

    int j = 0;

    for ( int i = 0; i < newArraySize; i++ ) {
        if ( searchn == arr[i] ) {
            searchArr[j] = i + 1;
            j++;
        }
    }

    cout<<searchn<<"shows in lines ";
    for ( int i = 0; i < j; i++ ) {
        if ( i = j - 1 ) {
            cout<<searchArr[i]<<".";    
        }
        cout<<searchArr[i]<<", ";
    }

    return 0;
}

void printArray(int* arr, int arrSize) {
    for ( int i = 0; i < arrSize; i++ ) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
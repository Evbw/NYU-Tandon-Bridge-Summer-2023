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

    cout<<"Vector version: "<<endl;
    main2();
}

int main1() {
    int n, searchN;
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
    cin>>searchN;

    int j = 0;

    for ( int i = 0; i < newArraySize; i++ ) {
        if ( searchN == arr[i] ) {
            searchArr[j] = i + 1;
            j++;
            cout<<j<<endl;
        }
    }

    cout<<searchN<<" shows in lines ";
    for ( int i = 0; i < j; i++ ) {
        if ( i == j - 1 ) {
            cout<<searchArr[i]<<".";    
        }
        else { 
            cout<<searchArr[i]<<", ";
        }   
    }
    return 0;
}

int main2() {
    int n, searchN;
    vector<int> v;
    vector<int> searchV;

    cout<<"Please enter a sequence of positive integers, each in a separate line."<<endl;
    cout<<"End you input by typing -1."<<endl;
    cin>>n;

    while ( n > -1 ) {
        v.push_back(n);
        cin>>n;  
    }

    cout<<"Please enter a number you want to search."<<endl;
    cin>>searchN;

    for ( int i = 0; i < v.size(); i++ ) {
        if ( searchN == v[i] ) {
            searchV.push_back(i + 1);
        }
    }

    cout<<searchN<<" shows in lines ";
    for ( int i = 0; i < searchV.size(); i++ ) {
        if ( i == searchV.size() - 1 ) {
            cout<<searchV[i]<<".";    
        }
        else { 
            cout<<searchV[i]<<", ";
        }   
    }
    return 0;
}

void printArray(int* arr, int arrSize) {
    for ( int i = 0; i < arrSize; i++ ) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
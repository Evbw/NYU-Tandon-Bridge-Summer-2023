#include <iostream>
#include <vector>
using namespace std;
//Initialize main1 and main2 functions
int main1();
int main2();
//Initialize an array size, because arrays are whiners
const int ARRAYSIZE = 10;
//Call main function
int main() {

    cout<<"Dynamic array version: "<<endl;
    main1();
    cout<<endl;
    cout<<"Vector version: "<<endl;
    main2();
}

void resizeArray(int*& arr, int& capacity) {
    capacity *= 2;
    int* newArr = new int[capacity];
    for (int i = 0; i < capacity / 2; i++) {
        newArr[i] = arr[i];
    }
    delete[] arr;
    arr = newArr;
}

int main1() {
    //Declare variables for user input
    int n, searchN;
    //Declare a pointer array for user input and an array for the target number
    int* arr = new int[ARRAYSIZE]();
    int* searchArr = new int[ARRAYSIZE]();
    //Declare an integer for the array size
    int newArraySize = 1;
    int capacity = ARRAYSIZE;
    //Request user input
    cout<<"Please enter a sequence of positive integers, each in a separate line."<<endl;
    
    cout<<"End your input by typing -1."<<endl;
    cin>>n;
    //Declare variable i for while loop iteration
    
    while (cin >> n && n != -1) {
        // Check if the array is full and resize if necessary
        if (newArraySize == capacity) {
            resizeArray(arr, capacity);
            resizeArray(searchArr, capacity);
        }
        
        // Assign input to elements of an array
        arr[newArraySize] = n;
        newArraySize++;
    }
    //Request a variable to search for inside the array
    cout<<"Please enter a number you want to search."<<endl;
    cin>>searchN;
    //Declare variable for the new dynamic array to index properly
    int j = 0;
    //Loop to find the indices of every occurence of the number the user wishes to search for
    for ( int i = 0; i < newArraySize; i++ ) {
        if ( searchN == arr[i] ) {
            searchArr[j] = i + 1;
            j++;
        }
    }
    //Begin output. If the number doesn't appear in the list, note it
    if ( j == 0 ) {
        cout<<searchN<<" does not appear in the list of numbers."<<endl;
        return 0;
    }

    cout<<searchN<<" shows in lines ";
    for ( int i = 0; i < j; i++ ) {
        //If it's the last number in the sequence, end with a period
        if ( i == j - 1 ) {
            cout<<searchArr[i]<<".";    
        }
        //Otherwise, display the number with a comma and a space
        else { 
            cout<<searchArr[i]<<", ";
        }
    }
    cout<<endl;

    delete[] arr;
    delete[] searchArr;
    
    return 0;
}

int main2() {
    //Declare variables for user input
    int n, searchN;
    //Declare a vector for input and vector for the target number
    vector<int> v;
    vector<int> searchV;
    //Request user input
    cout<<"Please enter a sequence of positive integers, each in a separate line."<<endl;
    cout<<"End your input by typing -1."<<endl;
    cin>>n;
    //Being loop to add elements to the vector
    while ( n > -1 ) {
        v.push_back(n);
        cin>>n;  
    }
    //Request a variable to search for inside the vector
    cout<<"Please enter a number you want to search."<<endl;
    cin>>searchN;
    //Loop to find the indices of every occurence of the number the user wishes to search for
    for ( int i = 0; i < v.size(); i++ ) {
        if ( searchN == v[i] ) {
            searchV.push_back(i + 1);
        }
    }
    //Begin output. If the number doesn't appear in the list, note it
    if ( searchV.size() == 0 ) {
        cout<<searchN<<" does not appear in the list of numbers."<<endl;
        return 0;
    }
    cout<<searchN<<" shows in lines ";
    for ( int i = 0; i < searchV.size(); i++ ) {
        //If it's the last number in the sequence, end with a period
        if ( i == searchV.size() - 1 ) {
            cout<<searchV[i]<<".";    
        }
        //Otherwise, display the number with a comma and a space
        else { 
            cout<<searchV[i]<<", ";
        }   
    }
    cout<<endl;
    return 0;
}
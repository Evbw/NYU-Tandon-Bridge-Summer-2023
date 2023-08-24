#include <iostream>
using namespace std;

int main() {
    int input;   

    cout<<"Please enter a positive number: "<<endl;
    cin>>input;

    for(int i = input - 1; i > 0; i--) {
        for(int j = 0; j < input - (i + 1); j++) {
            cout<<" ";
        }
        for(int j = 0; j < 2 * (i + 1) - 1; j++) {
            cout<<"*";
        }
        cout<<endl;
    }
   
    for(int i = 0; i < input; i++) {
        for(int j = 0; j < input - (i + 1); j++) {
            cout<<" ";
        }
        for(int j = 0; j < 2 * (i + 1) - 1; j++) {
            cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}
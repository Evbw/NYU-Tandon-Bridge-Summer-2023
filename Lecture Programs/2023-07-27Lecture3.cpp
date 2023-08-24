#include <iostream>
using namespace std;

int main() {

    int n;

    cout<<"Please enter a positive integer:";
    cin>>n;

    for (int i = 1; i <= n ; i++) {
        for (int j = 1; j <= i ; j++ ) {
            cout<<" ";
        }
        for (int j = i; j < n ; j++ ) {
            cout<<"*";
        }
        for (int j = i; j <= n ; j++ ) {
            cout<<"*";
        }
        cout<<endl;
    }
    
    for (int i = (n - 1); i > 0 ; i--) {
        for (int j = 1; j <= i ; j++ ) {
            cout<<" ";
        }
        for (int j = i; j < n ; j++ ) {
            cout<<"*";
        }
        for (int j = i; j <= n ; j++ ) {
            cout<<"*";
        }
        cout<<endl;
    }

}
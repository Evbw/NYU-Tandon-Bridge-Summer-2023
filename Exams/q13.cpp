// Everett Bowline eb111
#include <iostream>
using namespace std;

int main() {
    int n;

    cout<<"Please enter a positive integer: "<<endl;
    cin>>n;

    for ( int i = 1; i <= n; i++ ) {
        for ( int j = i; j <= n; j++ ){
            cout<<" ";
        }
        for ( int j = 1; j <= i; j++ ){
            cout<<"*";
        }
        for ( int j = 1; j < i; j++ ){
            cout<<"*";
        }
        cout<<endl;
        // for ( int j = i; j <= n; j++ ){
        //     cout<<" ";
        // }
    }
    for( int i = 1; i <= ( (2*n) + 1 ); i++) {
        cout<<"*";
    }
    cout<<endl;
    for ( int i = 1; i <= n; i++ ) {
        for ( int j = 1; j <= i; j++ ){
            cout<<" ";
        }
        for ( int j = i; j <= n; j++ ){
            cout<<"*";
        }
        for ( int j = i; j < n; j++ ){
            cout<<"*";
        }
        cout<<endl;
        // for ( int j = i; j <= n; j++ ){
        //     cout<<" ";
        // }
    }
}
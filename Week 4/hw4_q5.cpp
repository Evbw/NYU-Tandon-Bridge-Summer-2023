#include <iostream>
using namespace std;

int main() {
    // Initialize input variable
    int n;
    // Request input
    cout<<"Please enter a positive integer:"<<endl;
    cin>>n;
    // Begin outer loop for the rows. Initialize i at 1 and count up to n times
    for (int i = 1; i <= n ; i++) {
        // Begin inner loop. Add spaces dependant on the row count
        for (int j = 1; j <= i ; j++ ) {
            cout<<" ";
        }
        // Add stars based on iterations through the loop until input is reached
        for (int j = i; j < n ; j++ ) {
            cout<<"*";
        }
        // Finish adding stars
        for (int j = i; j <= n ; j++ ) {
            cout<<"*";
        }
        // Move on to next row
        cout<<endl;
    }
    // Put that thang down, flip it, and reverse it
    for (int i = n; i > 0 ; i--) {
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
#include <iostream>
using namespace std;

int main() {
    // Initialize integers
    int n, evenno;
    // Request input
    cout<<"Please enter a positive integer: ";
    cin>>n;

    cout<<"section a"<<endl;
    // Initialize variable for the while loop and set it equal to input
    int i = n;
    // Set the while loop in motion
    while ( i > 0 ) {
        // Set evenno variable to 2 then print
        evenno +=2;
        cout<<evenno<<endl;
        // iteration step
        i--;
    }

}
// Imagine all the comments above for the for loop below
// int main() {
//     int n, evenno;

//     cout<<"Please enter a positive integer: ";
//     cin>>n;

//     cout<<"section b"<<endl;
//     evenno = 0;
//     for (int i = n; i > 0; i--) {
//         evenno +=2;
//         cout<<evenno<<endl;
//     }
// }
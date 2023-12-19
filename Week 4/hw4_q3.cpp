#include <iostream>
using namespace std;

int main() {

    // int digit = 0;
    double z, twoexp = 1;

    cout<<"Enter decimal number: "<<endl;
    cin>>z;

    cout<<"\n"<<"The binary representation of "<<z<<" is ";
    
    // Find the power of 2 greater than the input
    while (twoexp <= z) {
        twoexp *= 2;
    }
    // Make the power of 2 less than the input for use in the subtraction method
    twoexp = twoexp/2;
    
    // Begin the loop
    while ( twoexp > 0 ) {
        // Start printing the binary representation
        if ( twoexp <= z ) {
            cout<<1;
            // Reduce the value of the input to continue the subtraction method
            z -= twoexp;
            // Reduce the value of the exponent to continue the subtraction method
            twoexp = twoexp/2;
        }
        else if ( twoexp > z ) {
            cout<<0;
            // Reduce the value of the exponent to continue the subtraction method
            twoexp = twoexp/2;            
        }
        // Finalize the output
        else if ( z == 1 ) {
            cout<<1<<endl;
            z -= 1;
        }
        // Eliminate the possibility of fractional exponent and infinite loop
        if (twoexp < 1) {
            twoexp = 0;
        }
    }
}
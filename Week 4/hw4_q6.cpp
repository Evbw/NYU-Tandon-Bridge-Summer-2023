#include <iostream>
using namespace std;

int main() {
    // Initialize variables
    int temp, odd, even, n = 0, m = 0;
    // Request input
    cout<<"Please enter a positive integer: ";
    cin>>n;
    // Begin loop. Starting at 2 since we're printing only even integers and counting up to input
    for ( int i = 2; i <= n; i++ ) {
        // Initialize inner variables. m = i so we can compare individual digits. Odd and even counts need to be reset to 0 through each iteration
        m = i, odd = 0, even = 0;
        // Begin while loop. We'll reduce the value of m until it is 0 so we can begin the next iteration of the for loop
        while ( m > 0 ) {
            // Separate digits for comparison to see if they're odd or even
            temp = m % 10;
            // Check digits. Add counts for each
            if ( temp % 2 == 0 ) {
                even += 1;
            }
            else {
                odd +=1;
            }
            // Reduce the value of m so we can check the next digit
            m /= 10;
        }
        // If there are more even digits in the number than odd, print number
        if ( odd < even ) {
            cout<<i<<endl;
        }
    }
    return 0;
}
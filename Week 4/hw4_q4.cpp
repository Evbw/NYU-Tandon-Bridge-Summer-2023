#include <iostream>
#include <cmath>
using namespace std;

int main() {

    cout<<"section a"<<endl;
    // Initialize variables
    double n, input, sequence;
    double geomean;
    // Request input from the user
    cout<<"Please enter the length of the sequence: ";
    cin>>input;
    cout<<"Please enter your sequence: "<<endl;
    // Initialize sequence and iterate
    for ( int i = 0; i < input; i++) {
        // Accept numbers in the sequence
        cin>>sequence;
        // Realize I could have set n = 1 and not use the if statement, then get bored and ignore it
        if (i == 0) {
            n = sequence;
        }
        if (i > 0) {
            n = n * sequence;
        }
    }
    //Calculate the geometric mean the only way I know how
    geomean = pow (n, (1.0/input));
    // Render output
    cout<<"The geometric mean is: "<<geomean<<endl;
}
// Imagine all the comments above for the while loop below
// int main() {

//     cout<<"section b"<<endl;
//     double nb = 0, sequenceb = 0, j = 0;
//     double geomeanb;

//     cout<<"Please enter a non-empty sequence of positive integers, each one in a separate line. End your sequence by typing -1:"<<endl;
    
//     do {
//         cin>>sequenceb;

//         if (j == 0 && sequenceb > -1) {
//             nb = sequenceb;
//             j++;
//         }
        
//         if (j > 1 && sequenceb > -1) {
//             nb = nb * sequenceb;  
//         }
//             j++;
//     } while ( sequenceb > -1);     

//     j = j - 2;

//     geomeanb = pow (nb, (1.0/j));

//     cout<<"The geometric mean is: "<<geomeanb<<endl;
// }
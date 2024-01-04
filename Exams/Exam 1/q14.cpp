// Everett Bowline eb111
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n = 0, m = 0, x = 0, y = 0, z = 0, perfSquare = 0, perfNum = 0;

    std::cout<<"Please enter a sequence of integers (with at least 1-digit and at most 9- digits), each one in a separate line. End your sequence by typing -1: "<<endl;
    cin>>n;
    m = sqrt(n) / 1;
    x = n;

    while ( n > -1 ) {
        if ( sqrt(n) == m ) {
            perfSquare++;
        }
            while ( x > 0) {
                if ( ( n % x == 0) ) {
                    if ( x % 2 == 1) {
                        x++;
                    }
                    y += ( x / 2 );
                }
                x = x / 2;
                if ( x == 1) {
                        break;
                }
                
            }
            if ( n == y) {
                perfNum++;
            }
        cin>>n;
        m = sqrt(n) / 1;
        x = n;
        y = 0;
    }

    cout<<"Total count of Perfect Squares in the given sequence: "<<perfSquare<<endl;
    cout<<"Total count of Perfect Numbers in the given sequence: "<<perfNum<<endl;
}
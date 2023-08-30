#include <iostream>
#include <string>
using namespace std;

int main() {
    string line;

    cout<<"Please enter a line of text: "<<endl;
    getline(cin, line);

    for ( int i = 0; i < ( line.length() - 1) ; i++ ) {
        if ( 58 > line[i] && line[i] > 46 ) {
            if ( line[i - 1] != 32 ) {
                continue;
            }
            line[i] = 120;
        }
    }
    
    cout<<line;
}
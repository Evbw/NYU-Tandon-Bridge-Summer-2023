#include <iostream>
#include <string>
using namespace std;

int main() {
    string line, word;
    int j = 0;

    cout<<"Please enter a line of text: "<<endl;
    getline(cin, line);

    for ( int i = 0; i < ( line.length() - 1 ) ; i++ ) {
        if ( line[i] == 32 ) {
            word = line.substr(j, line[i-1] - j);
            cout<<line.substr(j, line[i-1] - j)<<endl;
            j = line[i] + 1;

        }
    }
}
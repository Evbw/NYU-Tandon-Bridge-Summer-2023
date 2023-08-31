#include <iostream>
#include <string>
using namespace std;

int main() {
    string line, word;
    int j = 0;

    cout<<"Please enter a line of text: "<<endl;
    getline(cin, line);

    for ( int i = 0; i <= ( line.length() - 1 ) ; i++ ) {
        if ( line[i] == 32 ) {
            word = line.substr(j, i - j);
            j = i + 1;
            cout<<word<<endl;
        }
        if ( i == line.length() - 1 ) {
            word = line.substr(j, ( i + 1 ) - j);
            cout<<word<<endl;
        }
    }
}
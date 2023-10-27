#include <iostream>
#include <string>
#include <fstream>
#include <stack>
using namespace std;

void openInputFile(ifstream& inFile) {
    string filename;
    cout<<"Enter the filename: "<<endl;
    cin>>filename;
    inFile.open(filename);
    while (!inFile) {
        cout<<"File failed to open."<<endl;
        cout<<"Enter the filename: "<<endl;
        cin>>filename;
        inFile.clear();
        inFile.open(filename);
    }
}

bool scale(ifstream& inFile) {
    string input;
    stack<char> symbol;

    while ( getline(inFile, input) ) {
        for ( size_t i = 0; i < input.size(); i++ ) {
            char c = input[i];
            if ( c == 'b' && input.substr(i, 5) == "begin" ) {
                symbol.push('B');
                cout<<"pushed begin"<<endl;
                i += 4;
            }
            if ( c == 'e' && input.substr(i, 3) == "end" ) {
                if ( !symbol.empty() && symbol.top() == 'B') {
                    symbol.pop();
                    cout<<"popped begin"<<endl;
                    i += 2;
                }
                else {
                    return false;
                }
            }
            switch (c) {
                case '(':
                    cout<<"push ("<<endl;
                    symbol.push('(');
                    cout<<"symbol size after ( push "<<symbol.size()<<endl;
                    break;
                case '[':
                    cout<<"push ["<<endl;
                    symbol.push('[');
                    cout<<"symbol size after [ push "<<symbol.size()<<endl;
                    break;
                case '{':
                    cout<<"push {"<<endl;
                    symbol.push('{');
                    cout<<"symbol size after { push "<<symbol.size()<<endl;
                    break;
                case '}':
                    if ( !symbol.empty() && symbol.top() == '{') {
                        symbol.pop();
                        cout<<"pop ("<<endl;
                        cout<<"symbol size after { pop "<<symbol.size()<<endl;
                    }
                    else {
                        return false;
                    }
                    break;
                case ']':
                    if ( !symbol.empty() && symbol.top() == '[') {
                        symbol.pop();
                        cout<<"pop ["<<endl;
                        cout<<"symbol size after [ pop "<<symbol.size()<<endl;
                    }
                    else {
                        return false;
                    }
                    break;
                case ')':
                    if ( !symbol.empty() && symbol.top() == '(') {
                        symbol.pop();
                        cout<<"pop ("<<endl;
                        cout<<"symbol size after ( pop "<<symbol.size()<<endl;
                    }
                    else {
                        return false;
                    }
                    break;
            }
        }
    }
    return symbol.empty();
}

int main() {
    ifstream inFile;
    openInputFile(inFile);

    if(scale(inFile)) {
        cout<<"You're cool"<<endl;
    }
    else {
        cout<<"Beans"<<endl;
    }
    return 0;
}
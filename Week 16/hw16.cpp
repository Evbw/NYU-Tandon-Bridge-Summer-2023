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
    stack<string> beginAndEnd;
    stack<char> symbol;

    while (getline(inFile, input)) {
        cout<<"in while"<<endl;
        for (char c : input) {
            cout<<"in for"<<endl;
            switch (c) {
                case '(':
                    cout<<"push ("<<endl;
                    symbol.push('(');
                    break;
                case '[':
                    cout<<"push ["<<endl;
                    symbol.push('[');
                    break;
                case '{':
                    cout<<"push {"<<endl;
                    symbol.push('{');
                    break;
                case '}':
                    if ( !symbol.empty() && symbol.top() == '{') {
                        symbol.pop();
                        cout<<"pop ("<<endl;
                    }
                    else {
                        return false;
                    }
                    break;
                case ']':
                    if ( !symbol.empty() && symbol.top() == ']') {
                        symbol.pop();
                        cout<<"pop ["<<endl;
                    }
                    else {
                        return false;
                    }
                    break;
                case ')':
                    if ( !symbol.empty() && symbol.top() == ')') {
                        symbol.pop();
                        cout<<"pop ("<<endl;
                    }
                    else {
                        return false;
                    }
                    break;
            }
            if (c == 'b' || c == 'e') {
                cout<<"in if"<<endl;
                size_t pascalBegin = input.find("begin");
                if ( pascalBegin != string::npos ) {
                    beginAndEnd.push("begin");
                    cout<<"pushed begin"<<endl;
                }
                size_t pascalEnd = input.find("end");
                if ( pascalEnd != string::npos ) {
                    if ( !beginAndEnd.empty() && beginAndEnd.top() == "begin") {
                        beginAndEnd.pop();
                        cout<<"popped begin"<<endl;
                    }
                }
            }
            cout<<"beginAndEnd size"<<beginAndEnd.size()<<endl;
            if ( beginAndEnd.empty() && symbol.empty()) {
                return true;
            }
        }
    }
    return false;
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
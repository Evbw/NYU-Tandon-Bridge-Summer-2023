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
                i += 4;
            }
            if ( c == 'e' && input.substr(i, 3) == "end" ) {
                if ( !symbol.empty() && symbol.top() == 'B') {
                    symbol.pop();
                    i += 2;
                }
                else {
                    return false;
                }
            }
            switch (c) {
                case '(':
                    symbol.push('(');
                    break;
                case '[':
                    symbol.push('[');
                    break;
                case '{':
                    symbol.push('{');
                    break;
                case '}':
                    if ( !symbol.empty() && symbol.top() == '{') {
                        symbol.pop();
                    }
                    else {
                        return false;
                    }
                    break;
                case ']':
                    if ( !symbol.empty() && symbol.top() == '[') {
                        symbol.pop();
                    }
                    else {
                        return false;
                    }
                    break;
                case ')':
                    if ( !symbol.empty() && symbol.top() == '(') {
                        symbol.pop();
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
        cout<<"The file is balanced!"<<endl;
    }
    else {
        cout<<"Did you ever hear the Tragedy of Darth Plagueis the Wise? - No. - I thought not. It's not a story the Jedi would tell you. It's a Sith legend. Darth Plagueis was a Dark Lord of the Sith, so powerful and so wise he could use the Force to influence the midichlorians to create life… He had such a knowledge of the dark side that he could even keep the ones he cared about from dying. The dark side of the Force is a pathway to many abilities some consider to be unnatural. He became so powerful… the only thing he was afraid of was losing his power, which eventually, of course, he did. Unfortunately, he taught his apprentice everything he knew, then his apprentice killed him in his sleep. Ironic. He could save others from death, but not himself."<<endl;
    }
    return 0;
}
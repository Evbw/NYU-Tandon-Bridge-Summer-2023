#include <iostream>
#include <cstdlib>
#include <cctype>
#include <string>

std::string digitChecker(std::string word);

int main() {
    std::string line, word;
    int j = 0;

    std::cout<<"Please enter a line of text: "<<std::endl;
    getline(std::cin, line);

    for ( int i = 0; i <= ( line.length() ) ; i++ ) {
        if ( line[i] == 32 || i == line.length() ) {
            word = line.substr(j, i - j);
            j = i + 1;
            digitChecker(word);
        }
    }
}

std::string digitChecker(std::string word) {
    for ( int i = 0; i <= word.length(); i++ ) {
        if ( isdigit(word[i] ) ) {
            
        }
    }
    
    for ( int i = 0; i <= word.length(); i++ ) {
        word[i] = 79;
    }

    return word;
}
//Everett Bowline eb111

#include <iostream>
#include <vector>
#include <string>

int binaryBois(std::string str);

int main() {
    std::vector<std::string> digits;
    std::string userInput;
    int nonBinaryCount = 0;

    std::cout<<"Please enter a non-empty sequence of Strings. Each string should "<<std::endl;
    std::cout<<"be in a separate line and consists of only decimal digit"<<std::endl;
    std::cout<<"characters. To indicate the end of the input, enter an empty"<<std::endl;
    std::cout<<"string in one line."<<std::endl;
    getline(std::cin, userInput);

    while ( userInput != "" ) {

        nonBinaryCount += binaryBois(userInput);
        if ( binaryBois(userInput) == 0 ) {
            digits.push_back(userInput);
        }

        getline(std::cin, userInput);
    }

    for ( int i = 0; i < digits.size(); i++ ) {
        std::cout<<digits[i]<<std::endl;
    }

    std::cout<<"Number of Strings in the input sequence that get deleted for containing"<<std::endl;
    std::cout<<"at least one character which is not 0 or 1: "<<nonBinaryCount<<std::endl;

}

int binaryBois(std::string str) {
    int n;

    for ( int i = 0; i < str.length(); i++ ) {
        if ( str[i] < '0' || str[i] > '1' ) {
            return 1;
        }
    }
    
    return 0;
}
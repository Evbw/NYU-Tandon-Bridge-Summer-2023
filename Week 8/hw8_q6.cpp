#include <iostream>
#include <cstdlib>
#include <cctype>
#include <string>
//Omitted using namespace because it conflicted with the cctype library and I needed the isalpha function
//Initialize digitCheck function to use strings
std::string digitChecker(std::string word);
//Precondition: Input is a string
//Postcondition: If the word string is made entirely of digits, it will convert all of those digits to xes

int main() {
    //Initialized string variables, one for input and one for individual words after I split them apart
    std::string line, word;
    //Initialized another variable for the start of the word
    int j = 0;
    //Request user input
    std::cout<<"Please enter a line of text: "<<std::endl;
    getline(std::cin, line);
    //Take that line of text begin loop break it down into single words
    for ( int i = 0; i <= ( line.length() ) ; i++ ) {
        //Check if the element of the string is a space or the end of the line
        if ( line[i] == 32 || i == line.length() ) {
            word = line.substr(j, i - j);
            j = i + 1;
            //Call digitChecker function. It will reprint the line
            std::cout<<digitChecker(word)<<" ";
        }
    }
}

std::string digitChecker(std::string word) {
    //Beging for loops to check for alphabetical character in a word
    for ( int i = 0; i <= word.length(); i++ ) {
        //Check condition to see if there's an alphabetical character and return the word if so
        if ( isalpha ( word[i] ) ) {
            return word;
        }
        //Otherwise fall into a loop to replace all of the numbers with xes
        else {
            for ( int i = 0; i <= word.length(); i++ ) {
                word[i] = 120;
            }
        }
    }
    //If the there are only digits, they will all be replaced and the word will be returned for printing.
    return word;
}
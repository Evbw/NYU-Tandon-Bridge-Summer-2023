#include <iostream>
#include <string>
#include <vector>

//Instantiate compareAnagram function to include both strings
bool compareAnagram (std::string str, std::string str2);
//Instantiate const int for the alphabet
const int ALPHABET = 26;

int main() {
    //Instantiate input strings
    std::string line, line2;
    //request user input
    std::cout<<"Please enter a line of text: "<<std::endl;
    getline(std::cin, line);
    std::cout<<"and an another line to see if it's an anagram: "<<std::endl;
    getline(std::cin, line2);

    //Render output if the lines match
    if ( compareAnagram (line, line2)) {
        std::cout<<"Those are anagrams"<<std::endl;
    }
    else {
        std::cout<<"Those are not anagrams"<<std::endl;
    }
}

bool compareAnagram (std::string str, std::string str2) {
    
    //Initialize int variable for the loops and empty array for the alphabet
    int i = 0;
    int letterCount[ALPHABET] = {};
    int letterCount2[ALPHABET] = {};
    
    //If the letter is uppercase, make it lowercase
    for ( i = 0 ; i <= str.length() ; i++ ) {
       if ( str[i] >= 'A' && str[i] <= 'Z' ) {
            str[i] = str[i] + 32;
        }
    }

    for ( i = 0 ; i <= str2.size() ; i++ ) {
        if ( str2[i] >= 'A' && str2[i] <= 'Z' ) {
            str2[i] = str2[i] + 32;
        }
    }

    //Add a count for the appropriate index in the letter array if it exists in the string
    for ( i = 0; i < str.length(); i++ ) {
        if ( str[i] >= 'a' && str[i] <= 'z' ) {
            char c = str[i];
            int index = int (c - 'a');
            letterCount[index] = letterCount[index] + 1;
        }
    }

    for ( i = 0; i < str2.length(); i++ ) {
        if ( str2[i] >= 'a' && str2[i] <= 'z' ) {
            char c = str2[i];
            int index = int (c - 'a');
            letterCount2[index] = letterCount2[index] + 1;
        }
    }

    //Compare current vectors to see if they are anagrams and render output
    for ( i = 0; i < ALPHABET; i ++ ) {
        if ( letterCount[i] != letterCount2[i] ) {
            return false;
        }
    }
    return true;
}
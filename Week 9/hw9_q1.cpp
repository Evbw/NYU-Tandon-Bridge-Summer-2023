#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

void wordSplitter (std::string str);
const int ALPHABET = 26;

int main() {
    //Initialize string variables, one for input and one for individual words after I split them apart
    std::string line;
        
    //Request user input
    std::cout<<"Please enter a line of text: "<<std::endl;
    getline(std::cin, line);
    //Take that line of text begin loop break it down into single words. Print out individual letters
    wordSplitter (line);
}

void wordSplitter (std::string str) {
   
    //Initialize counters for the words and letters

    int letterCount[ALPHABET] = {};
    int wordcount = 1;

    
    //Begin loop to isolate individual letters
    for ( int i = 0 ; i <= str.length() ; i++ ) {
        //Check if the element of the string is a space. If so, increase wordcount        
        if ( str[i] == ' ' ) {
            wordcount++;
        }
        //If the letter is uppercase, make it lowercase
        if ( str[i] >= 'A' && str[i] <= 'Z' ) {
            str[i] = str[i] + 32;
        }
    }

    std::cout<<wordcount<<'\t'<<"words"<<std::endl;

    for ( int i = 0; i < str.length(); i++ ) {
        if ( str[i] >= 'a' && str[i] <= 'z' ) {
            char c = str[i];
            int index = int (c - 'a');
            letterCount[index] = letterCount[index] + 1;
        }
    }
    // for ( int i = 0; i < ALPHABET; i++ ) {
    //     std::cout<<letterCount[i];
    // }
    // std::cout<<std::endl;

    for ( int i = 0; i < ALPHABET; i++ ) {
        if ( letterCount[i] > 0 ) {
            std::cout<<letterCount[i]<<'\t'<<static_cast<char>(i + 'a')<<std::endl;
        }
    }
    
}
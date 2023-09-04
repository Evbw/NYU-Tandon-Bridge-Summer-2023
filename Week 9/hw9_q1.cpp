#include <iostream>
#include <string>
#include <vector>
//Initialize wordSplitter function
void wordSplitter (std::string str);
const int ALPHABET = 26;

int main() {
    //Initialize string variable for input
    std::string line;
    //Request user input
    std::cout<<"Please enter a line of text: "<<std::endl;
    getline(std::cin, line);
    //Take that line of text begin loop break it down into single words. Print out individual letters
    wordSplitter (line);
}

void wordSplitter (std::string str) {
    //Initialize array for the letters and counter for words
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
    //Begin for loop to find any characters between a-z and the comparable element in the letterCount array
    for ( int i = 0; i < str.length(); i++ ) {
        if ( str[i] >= 'a' && str[i] <= 'z' ) {
            char c = str[i];
            int index = int (c - 'a');
            letterCount[index] = letterCount[index] + 1;
        }
    }
    //Begin output
    std::cout<<wordcount<<'\t'<<"words"<<std::endl;
    //Begin loop to output the appropriate values for the indices
    for ( int i = 0; i < ALPHABET; i++ ) {
        //If the count for any individual letter is 0, ignore it
        if ( letterCount[i] > 0 ) {
            //Output the value for the index and compare it to the proper letter
            std::cout<<letterCount[i]<<'\t'<<static_cast<char>(i + 'a')<<std::endl;
        }
    }
    
}
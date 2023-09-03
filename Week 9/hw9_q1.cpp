#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

void wordSplitter (std::string str);

int main() {
    //Initialize string variables, one for input and one for individual words after I split them apart
    std::string line, word;
    
    //Request user input
    std::cout<<"Please enter a line of text: "<<std::endl;
    getline(std::cin, line);
    //Take that line of text begin loop break it down into single words. Print out individual letters
    wordSplitter (line);
}

void wordSplitter (std::string str) {
    //Initialize string variable for individual words after I split them apart
    std::string word;
    //Initialize vectors for the string
    std::vector<char> letters;
    //Initialize counters for the words and lettesr
    int wordcount = 1, lettercount = 0;
    //Populate letters vector based on input string
    for ( int i = 0 ; i <= str.length() ; i++ ) {
        letters.push_back(str[i]);
    }
    //Begin loop to isolate individual letters
    for ( int i = 0 ; i <= letters.size() ; i++ ) {
        //Check if the element of the string is a space. If so, increase wordcount        
        if ( letters[i] == 32 ) {
            wordcount++;
        }
        //If the letter is uppercase, make it lowercase
        if ( letters[i] >= 65 && letters[i] <= 90 ) {
            letters[i] = letters[i] + 32;
        }
    }
    //Sort the letters alphabetically
    std::sort(letters.begin(), letters.end());
    //Begin output. The word count will differentiate the total number of words
    std::cout<<wordcount<<'\t'<<"words"<<std::endl;
    //Begin loop to print out the letter count and the number of individual letters
    for ( int i = 0 ; i <= letters.size() ; i++ ) {
        //Since the letters are sorted, I can compare one element directly to the next
        if ( letters[i] != letters[i + 1] ) {
            //Confirming nothing unintended prints out
            if ( letters[i] < 97 || letters[i] > 122 ) {
                continue;
            }
            //Create output
            std::cout<<lettercount<<'\t'<<letters[i]<<std::endl;
            //Reset lettercount
            lettercount = 1;
        }
        //If they match, increase the letter count
        else {
            lettercount++;
        }
    }
    
}
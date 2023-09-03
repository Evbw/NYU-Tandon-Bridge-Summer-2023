#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

void compareAnagram (std::string str, std::string str2);
void stringLetters (std::vector<char> vector);

int main() {
    int textArrSize;
    int textArrPhysicalSize;
    bool seenEmptyLine;
    std::string line, line2;

    std::cout<<"Please a line of text: "<<std::endl;
    getline(std::cin, line);
    std::cout<<"and an anagram to compare it to: "<<std::endl;
    getline(std::cin, line2);

     compareAnagram (line, line2);
}

void compareAnagram (std::string str, std::string str2) {
    //Initialize string variable for individual words after I split them apart
    std::string word;
    //Initialize vectors for the string
    std::vector<char> letters;
    std::vector<char> letters2;
    //Initialize counters for the words and lettesr
    int wordcount = 1, lettercount = 0;
    //Populate letters vector based on input string
    for ( int i = 0 ; i <= str.length() ; i++ ) {
        letters.push_back(str[i]);
    }
    for ( int i = 0 ; i <= str2.length() ; i++ ) {
        letters2.push_back(str2[i]);
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

void stringLetters (std::vector<char> vector) {
    //Begin loop to isolate individual letters
    for ( int i = 0 ; i <= vector.size() ; i++ ) {
        //If the letter is uppercase, make it lowercase
        if ( vector[i] >= 65 && vector[i] <= 90 ) {
            vector[i] = vector[i] + 32;
        }
    }
    //Sort the vector alphabetically
    std::sort(vector.begin(), vector.end());
}
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

void compareAnagram (std::string str, std::string str2);

int main() {
    int textArrSize;
    int textArrPhysicalSize;
    bool seenEmptyLine;
    std::string line, line2;

    std::cout<<"Please enter a line of text: "<<std::endl;
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
    int wordcount = 1, lettercount = 0, i = 0;
    
    //Populate letters vector based on input string
    for ( i = 0 ; i <= str.length() ; i++ ) {
        letters.push_back(str[i]);
    }
    for ( i = 0 ; i <= str2.length() ; i++ ) {
        letters2.push_back(str2[i]);
    }

    for ( i = 0 ; i <= letters.size() ; i++ ) {
        //If the letter is uppercase, make it lowercase
        if ( letters[i] >= 65 && letters[i] <= 90 ) {
            letters[i] = letters[i] + 32;
        }
    }
    //Sort the vector alphabetically
    std::sort(letters.begin(), letters.end());
    
    for ( i = 0 ; i <= letters.size() ; i++ ) {
        //If the letter is uppercase, make it lowercase
        if ( letters[0] < 97 ) {
            letters.erase(letters.begin());
        }
    }

    for ( i = 0 ; i <= letters2.size() ; i++ ) {
        //If the letter is uppercase, make it lowercase
        if ( letters2[i] >= 65 && letters2[i] <= 90 ) {
            letters2[i] = letters2[i] + 32;
        }
    }
    //Sort the vector alphabetically
    std::sort(letters2.begin(), letters2.end());
    
    for ( i = 0 ; i <= letters2.size() ; i++ ) {
        //If the letter is uppercase, make it lowercase
        if ( letters2[0] < 97 ) {
            letters2.erase(letters2.begin());
        }
    }

    if ( letters == letters2 ) {
        std::cout<<"Yup, it's an anagram"<<std::endl;
    }
    else {
        std::cout<<"I have no idea what you're talking about"<<std::endl;
    }
    
}
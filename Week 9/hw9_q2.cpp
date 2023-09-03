#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
//Instantiate compareAnagram function to include both strings
void compareAnagram (std::string str, std::string str2);

int main() {
    //Instantiate input strings
    std::string line, line2;
    //request user input
    std::cout<<"Please enter a line of text: "<<std::endl;
    getline(std::cin, line);
    std::cout<<"and an another line to see if it's an anagram: "<<std::endl;
    getline(std::cin, line2);

    compareAnagram (line, line2);
}

void compareAnagram (std::string str, std::string str2) {
    
    //Initialize vectors for the strings
    std::vector<char> letters;
    std::vector<char> letters2;
    //Initialize int variable for the loops
    int i = 0;
    
    //Populate letters and letters2 vectors based on input strings
    for ( i = 0 ; i <= str.length() ; i++ ) {
        letters.push_back(str[i]);
    }
    for ( i = 0 ; i <= str2.length() ; i++ ) {
        letters2.push_back(str2[i]);
    }
    //If the letter is uppercase, make it lowercase
    for ( i = 0 ; i <= letters.size() ; i++ ) {
        if ( letters[i] >= 65 && letters[i] <= 90 ) {
            letters[i] = letters[i] + 32;
        }
    }

    for ( i = 0 ; i <= letters2.size() ; i++ ) {
        if ( letters2[i] >= 65 && letters2[i] <= 90 ) {
            letters2[i] = letters2[i] + 32;
        }
    }

    //Sort the vectors alphabetically
    std::sort(letters.begin(), letters.end());
    std::sort(letters2.begin(), letters2.end());

    //Remove characters that we're not directly comparing
    for ( i = 0 ; i <= letters.size() ; i++ ) {
        if ( letters[0] < 97 ) {
            letters.erase(letters.begin());
        }
    }
    for ( i = 0 ; i <= letters2.size() ; i++ ) {
        if ( letters2[0] < 97 ) {
            letters2.erase(letters2.begin());
        }
    }
    //Compare current vectors to see if they are anagrams and render output
    if ( letters == letters2 ) {
        std::cout<<"Those are anagrams"<<std::endl;
    }
    else {
        std::cout<<"Those are not anagrams"<<std::endl;
    }
    
}
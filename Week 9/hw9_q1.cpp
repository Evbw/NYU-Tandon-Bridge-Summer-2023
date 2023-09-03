#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

void wordSplitter (std::string str);
bool compareFunction (std::string a, std::string b) {return a<b;}

int main() {
    //Initialized string variables, one for input and one for individual words after I split them apart
    std::string line, word;
    
    //Request user input
    std::cout<<"Please enter a line of text: "<<std::endl;
    getline(std::cin, line);
    //Take that line of text begin loop break it down into single words
    wordSplitter (line);
}

void wordSplitter (std::string str) {
    //Initialized string variable for individual words after I split them apart
    std::string word;
    std::vector<char> letters;
    std::vector<char> lettercounter;
    int wordcount = 1, lettercount = 1;
    

    for ( int i = 0 ; i <= str.length() ; i++ ) {
        letters.push_back(str[i]);
    }

    for ( int i = 0 ; i <= letters.size() ; i++ ) {
        //Check if the element of the string is a space or the end of the line
        
        if ( letters[i] == 32 ) {
            wordcount++;
        }
        if ( letters[i] >= 65 && letters[i] <= 90 ) {
            letters[i] = letters[i] + 32;
        }
        if ( letters[i] >= 97 && letters[i] <= 122 ) {
            lettercounter.push_back(letters[i]);
        }
    }
    std::sort(lettercounter.begin(), lettercounter.end());

    std::cout<<wordcount<<'\t'<<"words"<<std::endl;

    for ( int i = 0 ; i <= lettercounter.size() ; i++ ) {
           
        if ( lettercounter[i] != lettercounter[i + 1] ) {
            if ( lettercounter[i] < 97 ) {
                continue;
            }
            std::cout<<lettercount<<'\t'<<lettercounter[i]<<std::endl;
            lettercount = 1;
        }
        else {
            lettercount++;
        }
    }
    
}
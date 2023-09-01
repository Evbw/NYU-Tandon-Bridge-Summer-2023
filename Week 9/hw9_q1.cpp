#include <iostream>
#include <string>
#include <vector>

void wordSplitter (std::string str);

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
    int count = 1;
    

    for ( int i = 0; i <= ( str.length() ) ; i++ ) {
        letters.push_back(str[i]);
    }
    for ( int i = 0; i <= ( letters.size() ) ; i++ ) {
        //Check if the element of the string is a space or the end of the line
        if ( letters[i] == 32 ) {
            count++;
        }
        if ( letters[i] < 65 || letters[i] > 122 ) {
            delete the letters!
            letters.size()--;
        }
        else if ( letters[i] > 90 && letters[i] < 97 ) {
            continue;
        }
        if ( letters[i] >= 65 && letters[i] <= 90 ) {
            letters[i] = letters[i] + 32;
        }
        if ( letters[i] >= 97 && letters[i] <= 122 ) {
            letters[i] = letters[i];
        }
    }

    std::cout<<count<<'\t'<<"words"<<std::endl;
}
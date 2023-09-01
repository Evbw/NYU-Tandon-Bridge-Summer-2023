#include <iostream>
#include <string>
#include <vector>

std::string wordSplitter (std::string str);

int main() {
    //Initialized string variables, one for input and one for individual words after I split them apart
    std::string line, word;
    
    //Request user input
    std::cout<<"Please enter a line of text: "<<std::endl;
    getline(std::cin, line);
    //Take that line of text begin loop break it down into single words
    wordSplitter (line);
}

std::string wordSplitter (std::string str) {
    //Initialized string variable for individual words after I split them apart
    std::string word;
    std::vector<char> letters;
    int count = 0;

    for ( int i = 0; i <= ( str.length() ) ; i++ ) {
        letters[i] = str[i];
    }
    for ( int i = 0; i <= ( letters.size() ) ; i++ ) {
        //Check if the element of the string is a space or the end of the line
        if ( letters[i] == 32 ) {
            count++;
        }
        if ( str[i] < 65 || str[i] > 122 ) {
            continue;
        }
        else if ( str[i] > 90 && str[i] < 97 ) {
            continue;
        }
        if ( str[i] >= 65 && str[i] <= 90 ) {
            str[i] = str[i] + 32;
        }
        if ( str[i] >= 97 && str[i] <= 122 ) {
            letters[i] = str[i];
        }
    }

    // cout<<count<<'\t'<<"words"<<endl;
    return str;
}
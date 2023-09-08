#include <iostream>
#include <string>

//Declare functions
std::string* createWordsArray(std::string sentence, int& outWordsArrSize);
void printArray(std::string* arr, int arrSize);

int main() {
    std::string line = "";
    int arrSize = 0;
    std::string* stringarr = new std::string;

    std::cout<<"Please enter a sentence: "<<std::endl;
    getline(std::cin, line);

    stringarr = createWordsArray(line, arrSize);

    printArray(stringarr, arrSize);
    
    delete [] stringarr;
    stringarr = nullptr;
}

void printArray(std::string* arr, int arrSize) {
    for ( int i = 0; i < arrSize; i++ ) {
        std::cout<<arr[i]<<" ";
    }
    std::cout<<std::endl;
}

std::string* createWordsArray(std::string sentence, int& outWordsArrSize) {
    std::string word;
    int wordcounter = 0;


    for ( int i = 0; i <= ( sentence.length() ); i++ ) {
        if ( sentence[i] == ' ' || i == sentence.length() ) {
            wordcounter++;
        }
    }

    std::string *temp = new std::string[wordcounter];
    outWordsArrSize = wordcounter;

    int j = 0;
    int w = 0;
    for ( int i = 0; i <= ( sentence.length() ); i++ ) {
        // std::cout<<i<<std::endl;
        if ( sentence[i] == ' ' || i == sentence.length() ) {
            // std::cout<<sentence.length()<<std::endl;
            // std::cout<<sentence.substr(i, (i-j))<<std::endl;
            temp[w] = sentence.substr(j, (i-j));
            j = ( i + 1 );
            w++;
        }
    }
    
    return temp;
}
#include <iostream>
#include <string>
//Declare functions
std::string* createWordsArray(std::string sentence, int& outWordsArrSize);
//Precondition: sentence is a valid string and outWordsArrSize is a valid integer
//Postcondition: A new array containing individual words will be returned
void printArray(std::string* arr, int arrSize);

int main() {
    //Declare variables: An input line, an array size that will be updated, and a dynamic array for strings
    std::string line = "";
    int arrSize = 0;
    std::string* stringarr = new std::string;
    //Request input
    std::cout<<"Please enter a sentence: "<<std::endl;
    getline(std::cin, line);
    //Call the createWordsArray to add the individual words as elements of an array
    stringarr = createWordsArray(line, arrSize);
    //No reason to have an array just hanging around, so we test it by printing
    std::cout<<"There were "<<arrSize<<" words in that sentence, so the array size is "<<arrSize<<"."<<std::endl;
    std::cout<<"The elements are:"<<std::endl;
    printArray(stringarr, arrSize);
    //And then we delete that pointer that's pointing to some random place in memory
    delete [] stringarr;
    stringarr = nullptr;
}
//Simple function to print an array
void printArray(std::string* arr, int arrSize) {
    for ( int i = 0; i < arrSize; i++ ) {
        std::cout<<arr[i]<<" ";
    }
    std::cout<<std::endl;
}

std::string* createWordsArray(std::string sentence, int& outWordsArrSize) {
    //Declare a variable for separating the words and counting the individual numbers of words
    std::string word;
    int wordcounter = 0;
    //Begin loop to count the number of words in the string
    for ( int i = 0; i <= ( sentence.length() ); i++ ) {
        if ( sentence[i] == ' ' || i == sentence.length() ) {
            wordcounter++;
        }
    }
    //Create new temporary dynamyic array the size of the nmber of words
    std::string *temp = new std::string[wordcounter];
    //Set the call-by-reference array size to the count
    outWordsArrSize = wordcounter;
    //Declare variable for properly tracking words. Reset wordcounter
    int j = 0;
    wordcounter = 0;
    //Begin loop to separate words and add them as elements to an array
    for ( int i = 0; i <= ( sentence.length() ); i++ ) {
        //Conditional to delimit words by a space or the end of the string.
        if ( sentence[i] == ' ' || i == sentence.length() ) {
            temp[wordcounter] = sentence.substr(j, (i-j));
            j = ( i + 1 );
            wordcounter++;
        }
    }
    //Return the temporary array
    return temp;
}
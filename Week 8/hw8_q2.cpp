#include <iostream>
#include <string>
using namespace std;
//Initialize function containing string
bool isPalindrome(string str);
//Precondition: The string variable is valid
//Postcondition: Determine if it's the string is a palindrome.
int main () {
    //Initialize variables
    string word;
    //Request user input
    cout<<"Please enter a word: ";
    cin>>word;
    //Use conditional checking bool function. If true, confirm word is a palindrome. Else state it is not
    if ( isPalindrome(word) ) {
        cout<<word<<" is a palindrome"<<endl;
    }
    else {
        cout<<word<<" is not a palindrome"<<endl;
    }

}

bool isPalindrome(string str) {
    //Initialize string variable
    string newword;
    //Begin loop to reverse the characters in the word
    for ( int i = str.length() - 1; i >= 0; i-- ) {
        newword += str[i];
    }
    //Check to see if the revsered word is the same as the input word
    if ( newword == str ) {
        return true;
    }
    else {
        return false;
    }

}
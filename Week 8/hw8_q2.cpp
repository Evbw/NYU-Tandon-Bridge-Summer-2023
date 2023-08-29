#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string str);

int main () {
    string word;

    cout<<"Please enter a word: ";
    cin>>word;
    
    if ( isPalindrome(word) ) {
        cout<<word<<" is a palindrome"<<endl;
    }
    else {
        cout<<word<<" is not a palindrome"<<endl;
    }

}

bool isPalindrome(string str) {
    int n, m;
    string newword;

    for ( n = str.length() - 1; n >= 0; n-- ) {
        newword += str[n];
    }

    if ( newword == str ) {
        return true;
    }
    else {
        return false;
    }

}
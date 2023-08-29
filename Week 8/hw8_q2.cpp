#include <iostream>
#include <string>
using namespace std;

void isPalindrome(string str);

int main () {
    string word;

    cout<<"Please enter a word: ";
    cin>>word;
    isPalindrome(word);
    
    // if (isPalindrome(word)) {

    //     cout<<word<<" is a palindrome"<<endl;

    // }    

}

void isPalindrome(string str) {
    int n;
    string newword;

    for ( n = str.length() - 1; n >= 0; n-- ) {
        cout<<str[n];
    }
}
#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string str);

int main () {
    string word;

    cout<<"Please enter a word: ";
    cin>>word;
    
    if (isPalindrome(word)) {

        cout<<word<<" is a palindrome"<<endl;

    }    

}

bool isPalindrome(string str) {

}
#include <iostream>
using namespace std;

bool palindrome(int n);

int main() {
    int n;
    bool isPalindrome;

    cout<<"Please enter a positive number: ";
    cin>>n;

    isPalindrome = palindrome(n);

    if ( isPalindrome == 1 ) {
        cout<<n<<" is a palindrome number."<<endl;
    }
    else {
        cout<<n<<" is not a palindrome number."<<endl;
    }

}

bool palindrome(int n) {
    int digit = n;
    int digit2 = 0;
        
    while ( digit > 0 ) {
        digit2 = (digit2 * 10) + (digit % 10);
        digit = digit / 10;        
    }
    return (digit2 == n);
}
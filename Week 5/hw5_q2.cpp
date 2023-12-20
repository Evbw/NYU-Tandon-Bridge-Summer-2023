#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main () {
    int x = 0, n = 0, guesses = 1;
    int toprange = 100, bottomrange = 1;

    srand(time(0));

    x = rand() % 100 + 1;

    cout<<"I thought of a number between 1 and 100! Try to guess it."<<endl;

    while ( guesses <= 5) {
        cout<<"Range: ["<<bottomrange<<", "<<toprange<<"], Number of guesses left: "<<( 6 - guesses )<<endl;
        cout<<"Your guess: "; 
        cin>>n;
        while ( n < bottomrange || n > toprange ) {
            cout<<"That number is outside of the range: ["<<bottomrange<<", "<<toprange<<"], Number of guesses left: "<<( 6 - guesses )<<endl;
            cout<<"Please guess again: "; 
            cin>>n;
        }
        if ( n == x ) {
            cout<<"Congrats! You guessed my number in "<<guesses<<" guesses.";
            return 0;
        }
        else if ( guesses < 5 && n > x) {
            cout<<"Wrong! My number is smaller."<<endl;
            toprange = n - 1;
            cout<<endl;
        }
        else if ( guesses < 5 && n < x) {
            cout<<"Wrong! My number is bigger."<<endl;
            bottomrange = n + 1;
            cout<<endl;
        }
        guesses++;
    }
    if ( guesses == 6 ) {
        cout<<"Out of guesses! My number is "<<x;
        return 0;
    }
    return 0;
}
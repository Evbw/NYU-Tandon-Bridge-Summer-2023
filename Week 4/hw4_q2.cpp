#include <iostream>
using namespace std;
// Initialize constants
const int INDIA = 1, VICTOR = 5, XRAY = 10, LIMA = 50, CHARLIE = 100, DELTA = 500, MIKE = 1000;

int main() {
    // Initialize strings. including the final output
    string i = "I", v = "V", x = "X", l = "L", c = "C", d = "D", m = "M", romannumber;
    // Initialize variables for conversion
    int decimal, n;
    int thou, fhun, hun, fif, ten, five, one;
    // Request input
    cout<<"Enter decimal number:";
    cin>>decimal;
    // Save input for final output
    n = decimal;
    // Begin calculations to extract the digits for the individual strings
    thou = decimal / MIKE;
    decimal = decimal % MIKE;
    // Add as many as needed
    for (int z = 0; z < thou; z++) {
        romannumber = romannumber + m;
    }
    // And repeat the process for each roman numeral
    fhun = decimal / DELTA;
    decimal = decimal % DELTA;

    for (int z = 0; z < fhun; z++) {
        romannumber = romannumber + d;
    }

    hun = decimal / CHARLIE;
    decimal = decimal % CHARLIE;

    for (int z = 0; z < hun; z++) {
        romannumber = romannumber + c;
    }

    fif = decimal / LIMA;
    decimal = decimal % LIMA;

    for (int z = 0; z < fif; z++) {
        romannumber = romannumber + l;
    }

    ten = decimal / XRAY;
    decimal = decimal % XRAY;

    for (int z = 0; z < ten; z++) {
        romannumber = romannumber + x;
    }

    five = decimal / VICTOR;
    decimal = decimal % VICTOR;

    for (int z = 0; z < five; z++) {
        romannumber = romannumber + v;
    }

    one = decimal / INDIA;
    decimal = decimal % INDIA;

    for (int z = 0; z < one; z++) {
        romannumber = romannumber + i;
    }
    // Final output
    cout<<n<<" is "<<romannumber<<endl;

}
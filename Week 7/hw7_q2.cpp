#include <iostream>
#include <cmath>
using namespace std;

void analyzeDivisors(int num, int& outCountDivs, int& outSumDivs);
bool isPerfect(int num);

int main() {
    //Variable declaration. I have a variety and I will need to use them
    int n, sumDivs = 0, secondSum = 0, countDivs, secondCount;
    //Request user input
    cout<<"Please enter a number >= 2: "<<endl;
    cin>>n;
    //Begin output line for perfect numbers
    cout<<"The perfect numbers in that range are: "<<endl;
    //Begin for loop for perfect numbers. As it iterates, it will determine all matching values up to n
    for (int i = 2; i <= n; i++ ) {
        //And print them if they match!
        if ( isPerfect( i ) ) {
            cout<<i<<endl;
        }
    }
    //Begin output line for amicable numbers
    cout<<"The pairs of amicable numbers in that range are: "<<endl;
    //Begin for loop to analyze the divisors to see if they're friendly. Start the loop at 2 because of the functions calculations
    for ( int i = 2; i <= n; i++ ) {
        //Run the analyzeDivisors through each iteration
        analyzeDivisors(i, countDivs, sumDivs);
        //And use the result of the sum of the divisors to get a new value for the variables I'll compare
        analyzeDivisors(sumDivs, secondCount, secondSum);
        //I check the number, i, against the result of the second call of the function. If they are equal
        //AND i is less than the result of the first function. This will prevent duplicates
        //I'll add a cap so we don't get results outside of the range (if n = 250, for example, 220, 284 would print)
        if ( i == secondSum && i < sumDivs && sumDivs >= 2 && sumDivs <= n ) {
            cout<<i<<", "<<sumDivs<<endl;
        }
    }
}

void analyzeDivisors(int num, int& outCountDivs, int& outSumDivs) {
    //Declare variables and set them to 1, otherwise false matches can occur
    int countDivs = 1, sumDivs = 1;
    //Begin loop. We need to start at 2, because starting at 1 would cause my calculation for summing the divisors to
    //miscalculate. Since we're only checking numbers greater than or equal to 2, this shouldn't cause any problems.
    for ( int i = 2; i <= sqrt(num); i++ ) {
        if ( num % i == 0 ) {
            countDivs++;
            sumDivs += ( i + ( num / i ) );
        }
    }
    //Set the call-by-reference variables to their respective values.
    outCountDivs = countDivs;
    outSumDivs = sumDivs;
}

bool isPerfect(int num) {
    //Declare a variable for iteration
    int d = 0;
    //Iteration through num's divisors. If anythin divides cleanly, add it to d.
    for( int i = 1 ; i <= num/2 ; i++ ) {
        if ( num % i == 0 ) {
            d += i;
        }
    }
    //And now we check to see if num is a perfect number.
    if ( d == num ) {
        return true;
    }
    else {
        return false;
    }
}
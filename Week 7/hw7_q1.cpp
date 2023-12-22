#include <iostream>
using namespace std;

int printMonthCalender(int numOfDays, int startingDay);
void printYearCalender(int year, int startingDay);
bool isALeapYear(int year);

const int JAN = 31, FEBNORM = 28, FEBLEAP = 29, MAR = 31, APR = 30, MAY = 31, JUN = 30, JUL = 31, AUG = 31, SEP = 30, OCT = 31, NOV = 30, DEC = 31;

int main() {

    int d, y;

    cout<<"Please enter a year and a starting day for January 1st ( 1 - 7, 1 being Monday and 7 being Sunday) separated by a space: "<<endl;
    cin>>d>>y;

   printYearCalender(d, y);

}

int printMonthCalender(int numOfDays, int startingDay) {
    //Declare variable for while loop
    int j = 1;
    //Display header line for days of the week
    cout<<"Mon"<<'\t'<<"Tue"<<'\t'<<"Wed"<<'\t'<<"Thu"<<'\t'<<"Fri"<<'\t'<<"Sat"<<'\t'<<"Sun"<<endl;
    //Begin main loop to increment the number of days
    for ( int i = 1; i <= numOfDays; i++ ){
        //The first line will need to have a certain number of blank spaces until we reach the starting day
        if ( i == 1 ) {
            //Start with i = 1, since that's guaranteed to be the first line. Then print spaces separated by tabs.
            while ( j < startingDay ) {
                cout<<" "<<'\t';
                j++;
            }
            //That was fun
        }
        //Now we beging the display of days
        cout<<i<<'\t';
        //Once we reach the end of the line for 7 days, we'll need to hit the end. The most reliable way is to see how many
        //blank spaces we have then add that to the day that's being printed (which is j - 1 , of course)
        //Check the remainder with modulo seven and separate the line
        if ( ( ( j + i ) - 1 ) % 7 == 0 ) {
            cout<<endl;
        }
    }
    //And now we return the final day as an int
    return ( ( numOfDays + j - 1 ) % 7 );
    
}

bool isALeapYear(int year) {
    //We need to calculate to see if the year is a leap year. If it's divisible by four-hundred, it's always a leap year
    if ( ( year % 400 ) == 0 ) {
        return true;
    }
    //If the year is divisible by 100, then it's not a leap year (unless it's divisible by 400, but we took care of that in the above conditional)
    if ( ( year % 4 == 0 ) && ( year % 100 == 0 ) ) {
        return false;
    }
    //Finally, if it's divisible by 4, it's a leap year
    if ( year % 4 == 0) {
        return true;
    }
    //An else statement to handle any edge cases
    else {
        return false;
    }

}

void printYearCalender(int year, int startingDay) {
    //I need a variable to handle the return result for each display of the month
    int lastDay = 0;
    //Format the display because even though I'm a mess I have taste
    cout<<'\t'<<'\t'<<"January "<<year<<endl;
    //I know how many days each month should have, so I enter that directly
    lastDay = printMonthCalender(JAN, startingDay);
    //I can't have a month start on the same day the previous month ended, so increment the day
    lastDay++;
    cout<<endl<<'\t'<<'\t'<<"February "<<year<<endl;
    //Account for leap years
    if ( isALeapYear(year) ) {
        lastDay = printMonthCalender(FEBLEAP, lastDay);
    }
    else {
        lastDay = printMonthCalender(FEBNORM, lastDay);
    }
    lastDay++;
    cout<<endl<<'\t'<<'\t'<<"March "<<year<<endl;
    lastDay = printMonthCalender(MAR, lastDay);
    lastDay++;
    cout<<endl<<'\t'<<'\t'<<"April "<<year<<endl;
    lastDay = printMonthCalender(APR, lastDay);
    lastDay++;
    cout<<endl<<'\t'<<'\t'<<"May "<<year<<endl;
    lastDay = printMonthCalender(MAY, lastDay);
    lastDay++;
    cout<<endl<<'\t'<<'\t'<<"June "<<year<<endl;
    lastDay = printMonthCalender(JUN, lastDay);
    lastDay++;
    cout<<endl<<'\t'<<'\t'<<"July "<<year<<endl;
    lastDay = printMonthCalender(JUL, lastDay);
    lastDay++;
    cout<<endl<<'\t'<<'\t'<<"August "<<year<<endl;
    lastDay = printMonthCalender(AUG, lastDay);
    lastDay++;
    cout<<endl<<'\t'<<'\t'<<"September "<<year<<endl;
    lastDay = printMonthCalender(SEP, lastDay);
    lastDay++;
    cout<<endl<<'\t'<<'\t'<<"October "<<year<<endl;
    lastDay = printMonthCalender(OCT, lastDay);
    lastDay++;
    cout<<endl<<'\t'<<'\t'<<"November "<<year<<endl;
    lastDay = printMonthCalender(NOV, lastDay);
    lastDay++;
    cout<<endl<<'\t'<<'\t'<<"December "<<year<<endl;
    lastDay = printMonthCalender(DEC, lastDay);
}
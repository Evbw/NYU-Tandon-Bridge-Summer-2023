#include <iostream>
using namespace std;

int main(){

    //Variable definition
    int timehours, timeminutes, callminutes;
    double primetime = 0.40, evening = 0.25, weekend = 0.15, callcost, cents = 100;
    string day;
    char colon;

    //Prepare for the proper digit output per the assignment document
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);

    //Request for input
    cout<<"Please enter day of the week long distance call is placed (Mo/Tu/We/Th/Fr/Sa/Su):"<<endl;
    cin>>day;
    cout<<"Please enter the start time of the long distance call, i.e. 1:30PM is input as 13:30: "<<endl;
    cin>>timehours>>colon>>timeminutes;
    cout<<"Please enter the length the long distance call in minutes only: "<<endl;
    cin>>callminutes;

    //Determine cost calculation
    if ( day == "Sa" || day == "sa" || day == "Su" || day == "su" ) {
        callcost = callminutes * weekend;
    }
    else if ( day == "Mo" || day == "mo" || day == "Tu" || day == "tu" || day == "We" || day == "we" || day == "Th" || day == "th" || day == "Fr" || day == "fr" ) {
        if ( timehours >= 8 && timehours <= 18 )
            callcost = callminutes * primetime;
        else {
            callcost = callminutes * evening;
        }
    }
    
    cout.precision(2);
    cout<<"The cost of the call is $"<<callcost<<endl;

    return 0;
}
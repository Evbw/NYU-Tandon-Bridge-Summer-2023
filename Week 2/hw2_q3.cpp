#include <iostream>
using namespace std;

int main(){

    int billdays, johndays, billhours, johnhours, billminutes, johnminutes, totaldays, totalhours, totalminutes;
    int hoursinday = 24, minutesinhour = 60;

    cout<<"Please enter the number of days John has worked:"<<endl;
    cin>>johndays;
    cout<<"Please enter the number of hours John has worked:"<<endl;
    cin>>johnhours;
    cout<<"Please enter the number of minutes John has worked:"<<endl;
    cin>>johnminutes;
    cout<<"\n";
    cout<<"Please enter the number of days Bill has worked:"<<endl;
    cin>>billdays;
    cout<<"Please enter the number of hours Bill has worked:"<<endl;
    cin>>billhours;
    cout<<"Please enter the number of minutes Bill has worked:"<<endl;
    cin>>billminutes; 

    totaldays = johndays + billdays;
    totalhours = johnhours + billhours;
    totalminutes = johnminutes + billminutes;

    totalhours += totalminutes / minutesinhour;
    totalminutes = totalminutes % minutesinhour;
    totaldays += totalhours / hoursinday;
    totalhours = totalhours % hoursinday;

    cout<<"The total time both of them worked together is: "<< totaldays<<" days, "<<totalhours<<" hours and "<<totalminutes<<" minutes."<<endl;

    return 0;
}
#include <iostream>

using namespace std;

int main(){

    int quarters, dimes, nickels, pennies, dollars = 0, cents = 0, odollars, ocents;
    int qval=25, dval=10, nval=5, dcrat=100;

    cout<<"Please enter your amount in the format of dollars and cents separated by a space:"<<endl;
    cin>>dollars>>cents;

    odollars = dollars;
    ocents = cents;

    dollars = (dollars * dcrat) + cents;
    quarters = dollars / qval;
    dollars = dollars % qval;
    dimes = dollars / dval;
    dollars = dollars % dval;
    nickels = dollars / nval;
    dollars = dollars % nval;
    pennies = dollars;

    cout<<odollars<<" dollars and "<<ocents<<" cents are:"<<endl;
    cout<<quarters<<" quarters, "<<dimes<<" dimes, "<<nickels<<" nickels and "<<pennies<<" pennies"<<endl;

    return 0;
}
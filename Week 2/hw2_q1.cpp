#include <iostream>

using namespace std;

int main(){


    int quarters, dimes, nickels, pennies, dollars = 0, cents = 0;
    int qval=25, dval=10, nval=5, pval=1, dcrat=100;

    cout<<"Please enter the number of coins:"<<endl;
    cout<<"# of quarters:"<<endl;
    cin>>quarters;
    cout<<"# of dimes:"<<endl;
    cin>>dimes;
    cout<<"# of nickels:"<<endl;
    cin>>nickels;
    cout<<"# of pennies:"<<endl;
    cin>>pennies;

    cents += quarters * qval;
    cents += dimes * dval;
    cents += nickels * nval;
    cents += pennies * pval;

    dollars = cents/dcrat;
    cents = cents%dcrat;

    cout<<"The total is "<<dollars<<" dollars and "<<cents<<" cents"<<endl;

    return 0;
}

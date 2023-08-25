#include <iostream>
using namespace std;

int main(){

    //Variable definition
    double item1 = 0, item2 = 0, discount = 0.5, clubcarddiscount = 0.1, tax, taxpercent = 100, baseprice, subtotal, total;
    string clubcard;

    //Prepare for the proper digit output per the assignment document
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);

    //Accept input from the user
    cout<<"Enter price of first item:"<<endl;
    cin>>item1;
    cout<<"Enter price of second item:"<<endl;
    cin>>item2;
    cout<<"Does customer have a club card? (Y/N):"<<endl;
    cin>>clubcard;
    cout<<"Enter tax rate, e.g. 5.5 for 5.5% tax:"<<endl;
    cin>>tax;

    //Calculate the values for output
    subtotal = item1 + item2;
    baseprice = subtotal;

    //Apply clubcard discount
    if (clubcard == "Yes" || clubcard == "yes" || clubcard == "y" || clubcard == "Y") {
        discount -= clubcarddiscount;
    }

    //Determine if there are two items, then take 50% off the cheaper item
    if (item1 > 0 && item2 > 0) {
        if (item1 >= item2) {
            subtotal = item1 + (item2 * discount);
        }
        else {
            subtotal = item2 + (item1 * discount);
        }
    }

    //Calculate total
    total = subtotal * (1 + (tax / taxpercent));

    cout.precision(1);
    cout<<"Base price: "<<baseprice<<endl;
    cout<<"Price after discounts: "<<subtotal<<endl;
    cout.precision(5);
    cout<<"Total price: "<<total<<endl;

    return 0;
}
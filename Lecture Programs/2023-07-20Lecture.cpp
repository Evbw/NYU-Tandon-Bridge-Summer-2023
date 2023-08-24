#include <iostream>
using namespace std;

int main() {
    int package;
    double total, price = 99, discount10 = 0.1, discount20 = 0.2, discount30 = 0.3, discount40 = 0.4, discounttotal;

    cout<<"Please enter number of packages purchased:"<<endl;
    cin>>package;

    if ( package <= 9 ) {
        total = package * price;
        cout<<"There is no discount. Your total is $"<<total<<"."<<endl;
    }
    else if ( package >= 10 && package < 19) {
        discounttotal = (package * price);
        total = (package * price) * discount10;
        discounttotal = discounttotal - total;
        cout<<"There is a $"<<discounttotal<<" discount! Your total is $"<<total<<"."<<endl;
    }
    else if ( package >= 20 && package < 49) {
        discounttotal = (package * price);
        total = (package * price) * discount20;
        discounttotal = discounttotal - total;
        cout<<"Hey! There is a $"<<discounttotal<<" discount! Your total is $"<<total<<"."<<endl;
    }
    else if ( package >= 50 && package < 99) {
        discounttotal = (package * price);
        total = (package * price) * discount30;
        discounttotal = discounttotal - total;
        cout<<"Alright! There is a $"<<discounttotal<<" discount!!!! Your total is $"<<total<<"."<<endl;
    }
    else if ( package >= 100 ) {
        discounttotal = (package * price);
        total = (package * price) * discount40;
        discounttotal = discounttotal - total;
        cout<<"!!!!!!!!!! There is a $"<<discounttotal<<" discount!!!!!!! Your total is $"<<total<<"."<<endl;
    }

    return 0;
}
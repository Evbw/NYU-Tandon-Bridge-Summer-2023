#include <iostream>
#include <cmath>
using namespace std;

int main(){

    //Variable definition
    double a, b, c, x1, x2;

    //Request for input
    cout<<"Please enter the value for a: "<<endl;
    cin>>a;
    cout<<"Please enter the value for b: "<<endl;
    cin>>b;
    cout<<"Please enter the value for c: "<<endl;
    cin>>c;

    //Create variables based on input
    double sqexpression = (b * b) - ( 4 * a * c );
    double fouracy = 4 * a * c;
    double tua = 2 * a;

    //Determine the number of solutions
    if ( a == 0 && b == 0 && c == 0 || a == 0) {
        cout<<"The equation has an infinite number of solutions"<<endl;
    }
    else if ( a == 0 && b == 0) {
        cout<<"The equation has no solution"<<endl;
    }
    else if ( b == 0 || sqexpression < 0 ) {
        cout<<"The equation has no real solution"<<endl;
    }
    //Begin the real calculations
    else if ( (b * b) == fouracy ) {
        x1 = (((-b) + (sqrt(sqexpression)))/tua);
        cout<<"The equation has one solution x="<<x1<<endl;
    }
    else {
        x1 = (((-b) + (sqrt(sqexpression)))/tua);
        x2 = (((-b) - (sqrt(sqexpression)))/tua);
        cout<<"The equation has two solutions x="<<x1<<" and x="<<x2<<endl;
    }

    return 0;
}
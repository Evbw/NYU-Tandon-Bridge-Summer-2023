#include <iostream>
using namespace std;

    //Constant definition
    const int FLOOR_ROUND = 1;
    const int CEILING_ROUND = 2;
    const int ROUND = 3;

int main(){

    //Variable definition
    double realnumber;
    int input = 0;

    //User input request
    cout<<"Please enter a Real number:"<<endl;
    cin>>realnumber;
    cout<<"Choose your rounding method: \n";
    cout<<"1. Floor round\n";
    cout<<"2. Ceiling round\n";
    cout<<"3. Round to the near whole number\n";
    cin>>input;

    switch (input) {
        case FLOOR_ROUND:
            if ( (realnumber - (int) realnumber) == 0 ) {
                cout<<realnumber<<endl;
            }
            else if ( (realnumber - (int) realnumber) > 0 ) {
                realnumber = (int) realnumber / one;
                cout<<realnumber<<endl;
            }
            else {
                realnumber = ( realnumber / one ) - one;
                cout<<realnumber<<endl;
            }
            break;
        case CEILING_ROUND:
            if ( (realnumber - (int) realnumber) == 0 ) {
                cout<<realnumber<<endl;
            }
            else if ( (realnumber - (int) realnumber) > 0 ) {
                realnumber = ((int) realnumber / one) + one;
                cout<<realnumber<<endl;
            }
            else {
                realnumber = ((int) realnumber / one);
                cout<<realnumber<<endl;
            }
            break;
        case ROUND:
            if ( realnumber > 0 && ( (realnumber - (int) realnumber) >= 0.5) ) {
                realnumber = ((int) realnumber / one) + one;
                cout<<realnumber<<endl;
            }
            else if ( realnumber > 0 && ( (realnumber - (int) realnumber) <= 0.5) ) {
                realnumber = ((int) realnumber / one);
                cout<<realnumber<<endl;
            }
            else if ( realnumber < 0 && ( (realnumber - (int) realnumber) <= -0.5) ) {
                realnumber = ((int) realnumber / one) - one;
                cout<<realnumber<<endl;
            }
            else if ( realnumber < 0 && ( (realnumber - (int) realnumber) >= -0.5) ) {
                realnumber = ((int) realnumber / one);
                cout<<realnumber<<endl;
            }
            break;
    }

    return 0;
}
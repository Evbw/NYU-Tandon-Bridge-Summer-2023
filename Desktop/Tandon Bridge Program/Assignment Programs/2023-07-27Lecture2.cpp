#include <iostream>
#include <string>
using namespace std;

int main() {

    int input_number;
    string binString = "";

    string x = "1", y = "0";
    int z;

    cout<<"Please enter a positive number:"<<endl;
    cin>>z;
    
    do
    {
        if ( z % 2 == 0 ) {

            binString = y + binString;

        }
        else if ( z % 2 == 1) {
        
            binString = x + binString;

        }

        z = z/2;


    } while ( z >= 0 && z != 1);

    if ( z == 1) {

        binString = x + binString;
    }

    cout<<binString<<endl;

}
#include <iostream>
using namespace std;

int main(){

    //Variable definition
    string name;
    int gradyear, currentyear;

    //Request for input
    cout<<"Please input your name: "<<endl;
    cin>>name;
    cout<<"Please input your graduation year: \n";
    cin>>gradyear;
    cout<<"Please input the current year: \n";
    cin>>currentyear;

    //Branching output
    if ( gradyear <= currentyear ) {
        cout<<name<<", you have Graduated"<<endl;
    }
    if ( ( gradyear - currentyear ) == 1 ) {
        cout<<name<<", you are a Senior"<<endl;
    }
    if ( ( gradyear - currentyear ) == 2 ) {
        cout<<name<<", you are a Junior"<<endl;
    }
    if ( ( gradyear - currentyear ) == 3 ) {
        cout<<name<<", you are a Sophomore"<<endl;
    }
    if ( ( gradyear - currentyear ) == 4 ) {
        cout<<name<<", you are a Freshman"<<endl;
    }
    if ( ( gradyear - currentyear ) >= 5 ) {
        cout<<name<<", you are not in college yet"<<endl;
    }
    
    return 0;
}
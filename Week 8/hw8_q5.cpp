#include <iostream>
#include <string>
using namespace std;

int main() {
    //Initialize strings for the first, middle, and last names
    string first, middle, last;
    //Request user input
    cout<<"Please input your first name, middle name, and last name: "<<endl;
    cin>>first>>middle>>last;
    //Print output
    cout<<last<<", "<<first<<" "<<middle[0]<<"."<<endl;
    return 0;
}
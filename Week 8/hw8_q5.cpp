#include <iostream>
#include <string>
using namespace std;

int main() {
    string first, middle, last;

    cout<<"Please input your first name, middle name, and last name: "<<endl;
    cin>>first>>middle>>last;

    cout<<last<<", "<<first<<" "<<middle[0]<<"."<<endl;
    
}
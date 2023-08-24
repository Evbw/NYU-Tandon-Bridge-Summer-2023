#include <iostream>
using namespace std;

int main(){

    double ftemp, ctemp;
    cout<<"Please enter the temperature in Fahrenheit:"<<endl;
    cin>>ftemp;

    ctemp = (ftemp - 32.0) * 5.0 / 9.0;

   cout<<ftemp<<" degrees Fahrenheit is "<<ctemp<<" degrees Celsius. "<<endl;
   return 0;
}
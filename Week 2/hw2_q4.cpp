#include <iostream>
using namespace std;

int main (){

    int value1, value2, add, subtract, multiply, div, modulo;
    float dividef;

    cout<<"Please enter two positive integers, separated by a space:";
    cin>>value1>>value2;

    add = value1 + value2;
    subtract = value1 - value2;
    multiply = value1 * value2;
    float v1 = value1;
    float v2 = value2;
    dividef = v1 / v2;
    div = value1 / value2;
    modulo = value1 % value2;

    cout<<value1<<" + "<<value2<<" = "<<add<<endl;
    cout<<value1<<" - "<<value2<<" = "<<subtract<<endl;
    cout<<value1<<" * "<<value2<<" = "<<multiply<<endl;
    cout<<value1<<" / "<<value2<<" = "<<dividef<<endl;
    cout<<value1<<" div "<<value2<<" = "<<div<<endl;
    cout<<value1<<" mod "<<value2<<" = "<<modulo<<endl;

    return 0;
}
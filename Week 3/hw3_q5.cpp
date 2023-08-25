#include <iostream>
using namespace std;

    const double POUND_KILO = 0.453592;
    const double INCH_METER = 0.0254;

int main(){

    //Variable definition
    double weight, height, bmi_ratio;
    double underweight = 18.5, normal = 25, overweight = 30;

    //Request input
    cout<<"Please enter weight (in pounds):"<<endl;
    cin>>weight;
    cout<<"Please enter height (in inches):"<<endl;
    cin>>height;

    weight = weight * POUND_KILO;
    height = height * INCH_METER;

    bmi_ratio = (weight/(height * height));

    if ( bmi_ratio <= underweight ) {
        cout<<"The weight status is: Underweight"<<endl;
    }
    else if ( bmi_ratio > underweight && bmi_ratio <= normal ) {
        cout<<"The weight status is: Normal"<<endl;
    }
    else if ( bmi_ratio > normal && bmi_ratio <= overweight ) {
        cout<<"The weight status is: Overweight"<<endl;
    }
    else {
        cout<<"The weight status is: Obese"<<endl;
    }

    return 0;
}
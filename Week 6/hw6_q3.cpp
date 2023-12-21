#include <iostream>
using namespace std;

double eApprox(int n);

int main() {
    cout.precision(30);

    for (int n = 1; n <= 15; n++) {
    cout<<"n = "<<n<<'\t'<<eApprox(n)<<endl;
    }

    return 0;
}

double eApprox(int n) {
    double factE = 1;
    double approxE = 1;

    for ( double i = 1; i <= n; i++ ) {
        factE *= i;
        approxE = approxE + ( 1 / ( factE ));   
    }

    return approxE;
}
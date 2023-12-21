#include <iostream>
using namespace std;

int fib(int n);

int main() {
    int num = 0, sequence;

    cout<<"Please enter a positive integer: ";
    cin>>num;

    sequence = fib(num);
    cout<<sequence;

}

int fib(int n) {
    int f1 = 1, f2 = 1, temp;

    if (n < 3) {
        return f2;
    }

    for ( int i = 3; i <= n; i++ ) {
        temp = f1;
        f1 = f2;
        f2 += temp;
    }
    return f2;
}
#include <iostream>
using namespace std;

int main() {

    int n = 0, m = 0, col = 1, row = 1;

    cout<<"Please enter a positive integer:"<<endl;
    cin>>n;

    for ( int i = 1; i <= n; i++) {
        
        row = i;

        for ( int j = 1; j <= n; j++){
            col = j;
            m = row * col;
            cout<<m<<'\t';
        }

        if ( col % n  == 0 ) {
            cout<<"\n";
        }
    }
}
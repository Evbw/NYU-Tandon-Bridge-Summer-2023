#include <iostream>
using namespace std;

void printShiftedTriangle(int n, int m, char symbol);
void printPineTree(int n, char symbol);

int main() {
    int n = 0, m = 0, option = 0;
    char symbol;

    cout<<"I have triangles shifted by a margin of your choosing (1) and pine trees (2). Which would you like? ";
    cin>>option;
    if ( option == 1 ) {
        cout<<"Enter the triangle height, the indent, and the symbol you'd like to build the triangle out of separated by a space: ";
        cin>>n;
        cin>>m;
        cin>>symbol;

        printShiftedTriangle( n, m, symbol);
    }
    else if ( option == 2 ) {
        cout<<"Enter a size for the tree and the symbol you'd like to use separated by spaces: ";
        cin>>n;
        cin>>symbol;

        printPineTree(n, symbol);
    }
    else {
        cout<<"I can only handle 1 or 2. Try again."<<endl;
    }

}

void printShiftedTriangle(int n, int m, char symbol) {
    for ( int i = 1; i <= n; i++ ) {
        for ( int j = 1; j < m; j++ ) {
            cout<<" ";
        }
        for ( int j = i; j <= n; j++ ) {
            cout<<" ";
        }
        for ( int j = 1; j <= i; j++ ) {
            cout<<symbol;
        }
        for ( int j = 1; j < i; j++ ) {
            cout<<symbol;
        }
        cout<<endl;
    }
}

void printPineTree(int n, char symbol) {
    int temp = n;
    
    for ( int pineLayer = 1; pineLayer <= n; pineLayer++ ) {

        printShiftedTriangle( ( pineLayer + 1 ), temp, symbol);
        temp--;
    }
}
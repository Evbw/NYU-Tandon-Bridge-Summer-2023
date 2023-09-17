#include <iostream>
using namespace std;

void printTriangle (int n);
void printOppositeTriangles (int n);
void printRuler (int n);


int main() {
    int size = 4;

    printTriangle (size);
    cout<<endl;
    printOppositeTriangles (size);
    cout<<endl;
    // printRuler (size);

}

void printTriangle (int n) {
    int temp = n;
    
    if ( n == 0 ) {
        return;
    }
    else {
        printTriangle(temp - 1);
        for ( int i = n; i > 0; i-- ) {
            cout<<"*";
        }
        cout<<endl;
        
    }
}

void printOppositeTriangles (int n) {
   
    if ( n == 1 ) {
        cout<<"*"<<endl;
    }
    else {
        for ( int i = 0; i < n; i++ ) {
            cout<<"*";
        }
        cout<<endl;
        printOppositeTriangles(n - 1);
    }
}

void printRuler (int n) {
    
}

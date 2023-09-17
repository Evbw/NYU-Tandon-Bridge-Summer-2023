#include <iostream>
using namespace std;

void printTriangle (int n);
void printOppositeTriangles (int n);
void printRuler (int n);


int main() {
    int size = 4;

    printTriangle (size);
    // printOppositeTriangles (size);
    // printRuler (size);

}

void printTriangle (int n) {

    if ( n == 1 ) {
        cout<<"*";
    }
    else {
        printTriangle(n - 1);
    }
}

void printOppositeTriangles (int n) {
    
}

void printRuler (int n) {
    
}

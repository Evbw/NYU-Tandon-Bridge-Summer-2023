#include <iostream>
using namespace std;

int main() 
{
    for (int i = 1; i <= 99 ; i = i + 2) {
        if (i == 13) {
            continue;
        }
        
        cout << i << endl;
    }

    return 0;
}
//Everett Bowline eb111

#include <iostream>
using namespace std;

int findOddIntegersAndSum(int S[], int length, int &sumOdds);

int main() {
    int arr[] = {10, -5, -20, 0, 7, -15, -5, -100};
    int arr2[] = {-1, -5, -70, -15, -26, -44, 0, 25, -14, -3};
    int arr3[] = {9, 0, 13, 17, 29, -14, -60, 9, -9};
    int arr4[] = {1, 5, 20, 0, -40};
    int sumOdds = 0;
    int oddCount = 0;

    oddCount = findOddIntegersAndSum(arr, 8, sumOdds);
    cout<<"There are "<<oddCount<<" odd numbers."<<endl;
    cout<<"Their total is "<<sumOdds<<"."<<endl;
    sumOdds = 0;

    oddCount = findOddIntegersAndSum(arr2, 10, sumOdds);
    cout<<"There are "<<oddCount<<" odd numbers."<<endl;
    cout<<"Their total is "<<sumOdds<<"."<<endl;
    sumOdds = 0;

    oddCount = findOddIntegersAndSum(arr3, 9, sumOdds);
    cout<<"There are "<<oddCount<<" odd numbers."<<endl;
    cout<<"Their total is "<<sumOdds<<"."<<endl;
    sumOdds = 0;

    oddCount = findOddIntegersAndSum(arr4, 5, sumOdds);
    cout<<"There are "<<oddCount<<" odd numbers."<<endl;
    cout<<"Their total is "<<sumOdds<<"."<<endl;
    sumOdds = 0;

}

int findOddIntegersAndSum(int S[], int length, int &sumOdds) {
    int temp = 0;

    if (length == 0) {
        return 0;
    }

    if ( S[length - 1] % 2 != 0 ) {
            sumOdds += S[length - 1];
            temp++;
    }
    
    temp += findOddIntegersAndSum(S, length - 1, sumOdds);
    
    return temp;
}
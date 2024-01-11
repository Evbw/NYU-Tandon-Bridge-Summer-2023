#include <iostream>
#include <vector>
using namespace std;

vector<int> minMax(vector<int>& v);
vector<int> minMax(vector<int>& v, int start, int end);

int main() {
    vector<int> testVector = {4, 6, 2, -50, 7, 1, 8, 0, 9};
        
    if (testVector.size() == 0) {
        cout<<"Vector is empty. No result.";
        return 0;
    }

    vector<int> minMaxResult = minMax(testVector);
    
    if ( minMaxResult[0] > minMaxResult[1] ) {
        cout<<"The maximum number is "<<minMaxResult[0]<<"."<<endl;
        cout<<"The minimum number is "<<minMaxResult[1]<<"."<<endl;
    }
    else {
        cout<<"The maximum number is "<<minMaxResult[1]<<"."<<endl;
        cout<<"The minimum number is "<<minMaxResult[0]<<"."<<endl;
    }
    return 0;
}

vector<int> minMax(vector<int>& v) {
    return minMax(v, 0, v.size()-1);
}

vector<int> minMax(vector<int>& v, int start, int end) {
    vector<int> returnVector;
    vector<int> leftVector;
    vector<int> rightVector;

    if (start == end) {
        returnVector.push_back(v[start]);
        returnVector.push_back(v[start]);    
        return returnVector;
    }
    else {
        int mid = (start + end)/2;
        leftVector = minMax(v, 0, mid);
        rightVector = minMax(v, mid+1, end);
        if ( leftVector[0] <= rightVector[0] ) {
            returnVector.push_back(leftVector[0]);
        }
        else {
            returnVector.push_back(rightVector[0]);
        }
        if ( leftVector[1] >= rightVector[1] ) {
            returnVector.push_back(leftVector[1]);
        }
        else {
            returnVector.push_back(rightVector[1]);
        }
    }
    
    return returnVector;
}
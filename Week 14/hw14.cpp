#include <iostream>
#include <vector>
using namespace std;

vector<int> minMax(vector<int>& v);
vector<int> minMax(vector<int>& v, int start, int end);

int main() {
    vector<int> testVector = {9, 0, 8, 1, 7, -50, 2, 6, 4};
        
    if (testVector.size() == 0) {
        cout<<"Vector is empty. No result.";
        return 0;
    }

    vector<int> minMaxResult = minMax(testVector);
    
    for (int i = 0; i < minMaxResult.size(); i++) {
        cout<<minMaxResult[i]<<" ";
    }
    cout<<endl;
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
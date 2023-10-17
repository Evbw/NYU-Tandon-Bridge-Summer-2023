#include <iostream>
#include <vector>
using namespace std;

vector<int> minMax(vector<int>& v);
vector<int> minMax(vector<int>& v, int start, int end);

int main() {
    vector<int> testVector = {9, 0, 8, 1, 7, 2, 6, 3, 5, 4};
    
    if (testVector.size() == 0) {
        cout<<"Vector is empty. No result.";
        return 0;
    }

    vector<int> minMaxResult = minMax(testVector);
    
    for (int i = 0; i < minMaxResult.size() - 1; i++) {
        cout<<minMaxResult[i]<<" "<<endl;
    }

}

vector<int> minMax(vector<int>& v) {
    return minMax(v, 0, v.size()-1);
}

vector<int> minMax(vector<int>& v, int start, int end) {
    vector<int> returnVector;

    if (start >= end) {
        returnVector.push_back(v[start]);
        for (int i = 0; i < returnVector.size() - 1; i++) {
            cout<<returnVector[i]<<" "<<endl;
        }
        return returnVector;
    }
    else {
        int mid = (start + end)/2;
        minMax(v, 0, mid);
        minMax(v, mid+1, end);
    }
    
    return returnVector;
}
#include <iostream>
#include <vector>
using namespace std;

class VectorQueue {
    private:
        int start;
        int size;
        vector<int> vQueue;
    public:
        VectorQueue() : start(0), size(0) {};
        void vectorPush (int value) {
            vQueue.push_back(value);
            size++;
        }
        void vectorPop () {
            int index;
            vQueue[index++];
        }
        bool empty() {
            size = 0;
            return size;
        }
};

int main() {
    VectorQueue v;

    for ( int i = 0; i < 10; i++ ) {
        v.vectorPush(i);
        cout<<v<<" ";
    }

    return 0;
}
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
    VectorQueue vq;

    for ( int i = 0; i < 10; i++ ) {
        vq.vectorPush(i);
        cout<<vq<<" ";
    }

    return 0;
}
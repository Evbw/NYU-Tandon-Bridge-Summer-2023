#include <iostream>
#include <vector>
using namespace std;

class VectorQueue {
    private:
        int start;
        int end;
        vector<int> vQueue;
    public:
        VectorQueue() : start(0), end(0) {};
        void vectorPush (int value) {
            vQueue.push_back(value);
            end++;
        }
        void vectorPop () {
            if ( !empty() ) {
                start++;
                if ( start == end ) {
                    vQueue.clear();
                    start = end = 0;
                }
            }
        }
        bool empty() {
            return start == end;
        }
        int size() const {
            return end - start;
        }
        int operator[]( int index ) const {
            if ( index < size() ) {
                return vQueue[start + index];
            }
            cout<<"Out of range"<<endl;
            return -1;
        }

        friend ostream& operator<<( ostream& outs, const VectorQueue& vq );
};

ostream& operator<<( ostream& outs, const VectorQueue& vq ) {
    for ( int i = 0; i < vq.size(); i++ ) {
        outs<<vq[i]<<" ";
    }
    return outs;
}

int main() {
    VectorQueue vq;

    for ( int i = 0; i < 10; i++ ) {
        vq.vectorPush(i);
        cout<<vq<<endl;
    }

    for ( int i = 0; i < 10; i++ ) {
        vq.vectorPop();
        cout<<vq<<endl;
    }

    return 0;
}
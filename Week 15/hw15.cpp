#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <list>
using namespace std;

template <class T>
class Diner {
    private:
        T amountPaid;
        T name;
    public:
        Diner(double amountPaid, string name) : amountPaid(amountPaid), name(name) {};
        Diner() {};
        double getAmountPaid() {return amountPaid;}
        string getName() {return name;}
        void setAmountPaid(double newAmountPaid) { amountPaid = newAmountPaid;}
        void setName(string newName) { name = newName; }

        friend void payBack(Diner& loanShark, Diner& debtor, double groupAverage) {
            double amountOwed;
            double amountOwing;
            double amountStillOwed;
            
            amountOwing = debtor.amountPaid - groupAverage;
            amountOwed = loanShark.amountPaid - groupAverage;

            if( amountOwing > amountOwed ) {
                amountOwing -= amountOwed;
                loanShark.amountPaid -= amountOwed;
                debtor.amountPaid = amountOwing;
                if (loanShark.amountPaid == groupAverage && debtor.amountPaid != groupAverage) {
                    cout<<loanShark.name<<" is paid back! ";
                    cout<<debtor.name<<" still owes $"<<amountOwing<<endl;
                }
                else if (loanShark.amountPaid == groupAverage && debtor.amountPaid == groupAverage) {
                    cout<<loanShark.name<<" is paid back! ";
                    cout<<debtor.name<<" is paid up!"<<endl;
                }
            }
            else {
                loanShark.amountPaid -= amountOwing;
                debtor.amountPaid += amountOwing;
                amountStillOwed = loanShark.amountPaid - groupAverage;
                if (debtor.amountPaid == groupAverage && loanShark.amountPaid != groupAverage) {
                    cout<<debtor.name<<" is paid up! ";
                    cout<<loanShark.name<<" is still owed $"<<amountStillOwed<<endl;
                }
            }
        }
};

template <class T>
class LList;

template <class T>
class LListNode {
private:
	T data;
	LListNode<T>* next;
	LListNode<T>* prev;
public:
	LListNode() : next(nullptr), prev(nullptr) {}
	LListNode(const T& newdata = T(), LListNode<T>* newnext = nullptr, LListNode<T>* newprev = nullptr) :data(newdata), next(newnext), prev(newprev) {}
	friend class LList<T>;
};

template <class T>
class LList {
	LListNode<T>* head;
	LListNode<T>* tail;
	
public:
	LList();
	~LList();
	LList(const LList<T>& rhs);
	LList<T>& operator=(const LList<T>& rhs);

	void clear() { while (!isEmpty()) pop_front(); }
	void push_back(const T& data) { tail->prev = new LListNode(data, tail, tail->prev); tail->prev->prev->next = tail->prev; }
	void push_front(const T& data) { head->next = new LListNode(data, head->next, head);  head->next->next->prev = head->next; }
	T pop_back();
	T pop_front();
	int size();
	bool isEmpty() { return head->next == tail; }
};
template <class T>
LList<T>& LList<T>::operator=(const LList<T>& rhs) {
	if (this == &rhs)
		return *this;
	clear();
	LListNode<T>* ptr = rhs.head->next;
	while (ptr != rhs.tail) {
		push_back(ptr->data);
	}
	return *this;
}
template <class T>
int LList<T>::size() {
	LListNode<T>* ptr = head->next;
	int count = 0;
	while (ptr != tail) {
		count++;
		ptr = ptr->next;
	}
	return count;
}
template <class T>
T LList<T>::pop_back() {
	if (tail->prev == head) //empty list!
		return T(); //not sure what to do here?  User did something dumb.
	T retval = tail->prev->data;
	LListNode<T>* nodeToDelete = tail->prev;
	tail->prev = nodeToDelete->prev;
	nodeToDelete->prev->next = nodeToDelete->next;
	delete nodeToDelete;
	return retval;
}
template <class T>
T LList<T>::pop_front() {
	if (tail->prev == head) //empty list!
		return T(); //not sure what to do here?  User did something dumb.
	T retval = head->next->data;
	LListNode<T>* nodeToDelete = head->next;
	head->next = nodeToDelete->next;
	head->next->prev = head;
	delete nodeToDelete;
	return retval;
}
template <class T>
LList<T>::~LList() {
	clear();
	delete head;
	delete tail;
}


void openInputFile(ifstream& inFile) {
    string filename;
    cout<<"Enter the filename: "<<endl;
    cin>>filename;
    inFile.open(filename);
    while (!inFile) {
        cout<<"File failed to open."<<endl;
        cout<<"Enter the filename: "<<endl;
        cin>>filename;
        inFile.clear();
        inFile.open(filename);
    }
}

int main() {
    ifstream inFile;
    openInputFile(inFile);
    vector<int> dinerVector;
    

}
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <list>
using namespace std;

template<class T>
class node {
public:
    node<T> *prev;
    node<T> *next;
    T val;
    node(T val){  //constructor
        this->prev=this->next=nullptr;
        this->val=val;
    }
};

class Diner {
        double amountPaid;
        string name;
    public:   
        Diner(double amountPaid, string name) : amountPaid(amountPaid), name(name) {};
        Diner() {};
        double getAmountPaid() const {return amountPaid;}
        string getName() const {return name;}
        void setAmountPaid(double newAmountPaid) { amountPaid = newAmountPaid;}
        void setName(string newName) { name = newName; }
        friend void payBack(Diner& loanShark, Diner& debtor, double groupAverage);
        friend ostream& operator<<(ostream& outs, const Diner& diner);        
};

ostream& operator<<(ostream& outs, const Diner& diner) {
    outs<<diner.getName()<<" has paid $"<<diner.getAmountPaid()<<"."<<endl;
    return outs;
}

template<class T>
class LList{
public:
    node<T>* head;
    node<T>* tail;
    int size;
    LList(){ //constructor
        this->head=nullptr;
        this->tail=nullptr;
        this->size=0;
    }
    LList(node<T>* input){ //constructor
        this->head=nullptr;
        this->tail=nullptr;
        this->size=0;
    }
    ~LList();
    void addend(node<T>* end){
        if(this->size==0){this->head=end;}
        this->tail->next=end;
        end->prev=this->tail;
        this->tail=end;
        this->size++;
        
    }
    void addbeginning(node<T>* begin){
        this->head->prev=begin;
        begin->next=this->head;
        this->head=begin;
        this->size++;
    }
    void removeend(){
        if(this->size==0){cout<<"Cannot remove from empty list"<<endl;return;}
        node<T>* oldtail=this->tail;
        this->tail=this->tail->prev;
        if(this->tail!=nullptr){this->tail->next=nullptr;}
        delete oldtail;
        this->size--;
    }
    void removebeginning(){
        if(this->size==0){cout<<"Cannot remove from empty list"<<endl;return;}
        node<T>* oldhead=this->head;
        this->head=this->head->next;
        if(this->head!=nullptr){this->head->prev=nullptr;}
        delete oldhead;
        this->size--;
    }
    void print(){
        if(this->size==0){
            cout<<"List is empty"<<endl;
            return;
        }
        node<T>* on=this->head;
        while(on!=nullptr){
            cout<<on->val;
            on=on->next;
        }
        cout<<endl;
    }
};

template <class T>
LList<T>::~LList() {
	while(head != nullptr) {
        node<T>* temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
}

void payBack(Diner& loanShark, Diner& debtor, double groupAverage) {
    double amountOwed;
    double amountOwing;
    double amountStillOwed;
    double newAmountPaid;
    double newAmountPaidBack;
    
    amountOwing = debtor.getAmountPaid() - groupAverage;
    amountOwed = loanShark.getAmountPaid() - groupAverage;

    if( amountOwing > amountOwed ) {
        amountOwing -= amountOwed;
        newAmountPaid = loanShark.getAmountPaid() - amountOwed;
        loanShark.setAmountPaid(newAmountPaid);
        newAmountPaidBack = debtor.getAmountPaid() + amountOwing;
        debtor.setAmountPaid(newAmountPaidBack);
        if (loanShark.getAmountPaid() == groupAverage && debtor.getAmountPaid() != groupAverage) {
            cout<<loanShark.getName()<<" is paid back! ";
            cout<<debtor.getName()<<" still owes $"<<amountOwing<<endl;
        }
        else if (loanShark.getAmountPaid() == groupAverage && debtor.getAmountPaid() == groupAverage) {
            cout<<loanShark.getName()<<" is paid back! ";
            cout<<debtor.getName()<<" is paid up!"<<endl;
        }
    }
    else {
        newAmountPaid = loanShark.getAmountPaid() - amountOwing;
        loanShark.setAmountPaid(newAmountPaid);
        newAmountPaidBack = debtor.getAmountPaid() + amountOwing;
        debtor.setAmountPaid(newAmountPaidBack);
        amountStillOwed = loanShark.getAmountPaid() - groupAverage;
        if (debtor.getAmountPaid() == groupAverage && loanShark.getAmountPaid() != groupAverage) {
            cout<<debtor.getName()<<" is paid up! ";
            cout<<loanShark.getName()<<" is still owed $"<<amountStillOwed<<endl;
        }
    }
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
    LList<Diner> dinerList;
    string input, name;
    double amount;

    while (getline(inFile, input)) {
        size_t inSpace = input.find(' ');
        if ( inSpace != string::npos ) {
            amount = stod(input.substr(0, inSpace));
            name = input.substr(inSpace + 1);
            Diner d(amount, name);
            node<Diner>* newDinerNode = new node<Diner>(d);
            if(dinerList.size == 0) {
                dinerList.head = newDinerNode;
                dinerList.tail = newDinerNode;
                dinerList.size++;
            }
            else {
                dinerList.addend(newDinerNode);
            }
        }
        else {
            cout<<"Invalid line"<<endl;
            continue;
        }
    }
    inFile.close();
    dinerList.print();

return 0;    
}
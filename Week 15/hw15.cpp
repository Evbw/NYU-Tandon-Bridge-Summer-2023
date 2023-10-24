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
        double getAmountPaid() {return amountPaid;}
        string getName() {return name;}
        void setAmountPaid(double newAmountPaid) { amountPaid = newAmountPaid;}
        void setName(string newName) { name = newName; }
        friend void payBack(Diner& loanShark, Diner& debtor, double groupAverage);
};

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
        if(this->size==0){cout<<"List is empty"<<endl;return;}
        node<T>* on=this->head;
        while(on!=nullptr){
            cout<<on->val<<" ";
            on=on->next;
        }
        cout<<endl;
    }
};

void payBack(Diner& loanShark, Diner& debtor, double groupAverage) {
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
        }
        else {
            cout<<"Invalid line"<<endl;
            continue;
        }
    }
    inFile.close();

return 0;    

}
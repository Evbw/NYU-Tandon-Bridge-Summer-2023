#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <list>
#include <iomanip>
#include <cmath>
using namespace std;

const double NOTHING = 0.00;
const double UNDERCENT = 0.009;

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
    outs.setf(ios::fixed);
    outs.setf(ios::showpoint);
    outs<<diner.getName()<<" has paid $"<<setprecision(2)<<diner.getAmountPaid()<<"."<<endl;
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
        if(this->size==0){
            this->head=end;
            this->tail=end;
        }
        else {
            this->tail->next=end;
            end->prev=this->tail;
            this->tail=end;
        }        
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
    
    if (debtor.getAmountPaid() > 0) {
        amountOwing = groupAverage - debtor.getAmountPaid();
    }
    else {
        amountOwing = groupAverage;
    }
    amountOwed = loanShark.getAmountPaid() - groupAverage;
    cout<<debtor.getName()<<" owes $"<<amountOwing<<endl;
    cout<<loanShark.getName()<<" is owed $"<<amountOwed<<endl;

    if( amountOwed > NOTHING ) {
        if ( amountOwed >= amountOwing ) {
            newAmountPaid = loanShark.getAmountPaid() - amountOwing;
            loanShark.setAmountPaid(newAmountPaid);
            amountStillOwed = loanShark.getAmountPaid() - groupAverage;
            debtor.setAmountPaid(groupAverage);
            cout<<debtor.getName()<<" has paid "<<loanShark.getName()<<"."<<endl;
        }
        else if ( amountOwing > amountOwed ) {
            amountOwing -= amountOwed;
            newAmountPaid = loanShark.getAmountPaid() - amountOwed;
            loanShark.setAmountPaid(newAmountPaid);
            newAmountPaidBack = groupAverage - amountOwing;
            debtor.setAmountPaid(newAmountPaidBack);    
            cout<<debtor.getName()<<" has paid "<<loanShark.getName()<<"."<<endl;       
        }
        
        if ((loanShark.getAmountPaid() == groupAverage && debtor.getAmountPaid() == groupAverage) || (fabs(loanShark.getAmountPaid() - groupAverage) < UNDERCENT && fabs(debtor.getAmountPaid() - groupAverage) < UNDERCENT) ) {
            cout<<loanShark.getName()<<" is paid back! ";
            cout<<debtor.getName()<<" is paid up!"<<endl;
            cout<<endl;
        }
        else if (loanShark.getAmountPaid() == groupAverage && debtor.getAmountPaid() != groupAverage) {
            cout<<loanShark.getName()<<" is paid back! ";
            cout<<debtor.getName()<<" still owes $"<<amountOwing<<"."<<endl;
            cout<<endl;
        }
        else if (debtor.getAmountPaid() == groupAverage && loanShark.getAmountPaid() != groupAverage) {
            cout<<debtor.getName()<<" is paid up! ";
            cout<<loanShark.getName()<<" is still owed $"<<amountStillOwed<<"."<<endl;
            cout<<endl;
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
    double amount, total, party = 0.0;
    
    cout<<endl;
    while (getline(inFile, input)) {
        size_t inSpace = input.find(' ');
        if ( inSpace != string::npos ) {
            amount = stod(input.substr(0, inSpace));
            total += amount;
            party += 1;
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
    double average = total/party;
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout<<"The total ticket price is $"<<setprecision(2)<<total<<". The average ticket price is $"<<setprecision(2)<<average<<"."<<endl;
    LList<Diner> oweList;
    LList<Diner> owedList;
    LList<Diner> square;

    node<Diner>* currentDiner = dinerList.head;
    while ( currentDiner != nullptr ) {
        if ( currentDiner->val.getAmountPaid() < average ) {
            Diner d(currentDiner->val.getAmountPaid(), currentDiner->val.getName());
            node<Diner>* newDinerNode = new node<Diner>(d);
            if (oweList.size == 0) {
                oweList.head = newDinerNode;
                oweList.tail = newDinerNode;
                oweList.size++;
            }
            else {
                oweList.addend(newDinerNode);
            }
        }
        else if ( currentDiner->val.getAmountPaid() > average ) {
            Diner d(currentDiner->val.getAmountPaid(), currentDiner->val.getName());
            node<Diner>* newDinerNode = new node<Diner>(d);
            if ( owedList.size == 0) {
                owedList.head = newDinerNode;
                owedList.tail = newDinerNode;
                owedList.size++;
            }
            else {
                owedList.addend(newDinerNode);
            }
        }
        else if ( currentDiner->val.getAmountPaid() == average ) {
            Diner d(currentDiner->val.getAmountPaid(), currentDiner->val.getName());
            node<Diner>* newDinerNode = new node<Diner>(d);
            if ( square.size == 0) {
                square.head = newDinerNode;
                square.tail = newDinerNode;
                square.size++;
            }
            else {
                square.addend(newDinerNode);
            }
        }
        currentDiner = currentDiner->next;
    }
    cout<<setprecision(2)<<endl;
    cout<<"Diners who owe: "<<endl;
    oweList.print();
    cout<<"Diners who are owed: "<<endl;
    owedList.print();
    cout<<"Diners who are square: "<<endl;
    square.print();

    while ( oweList.size != 0 && owedList.size != 0 ) {
        node<Diner>* debtorNode = oweList.head;
        node<Diner>* loanSharkNode = owedList.head;

        while ( debtorNode != nullptr && loanSharkNode != nullptr ) {
            payBack(loanSharkNode->val, debtorNode->val, average);
            
            if(debtorNode->val.getAmountPaid() == average) {
                square.addend(new node<Diner>(debtorNode->val));
                oweList.removebeginning();
                debtorNode = oweList.head;
            }

            if(loanSharkNode->val.getAmountPaid() == average) {
                square.addend(new node<Diner>(loanSharkNode->val));
                owedList.removebeginning();
                loanSharkNode = owedList.head;
            }
        }
        if ( oweList.size == 1 && owedList.size == 0 ) {
            square.addend(new node<Diner>(debtorNode->val));
            oweList.removebeginning();
            debtorNode = oweList.head;
        }
    }
    
    cout<<setprecision(2);
    cout<<"Diners who owe: "<<endl;
    oweList.print();
    cout<<"Diners who are owed: "<<endl;
    owedList.print();
    cout<<"Diners who are square: "<<endl;
    square.print();

return 0;    
}
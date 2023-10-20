#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class Diner {
    private:
        double amountPaid;
        string name;
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

void openInputFile(ifstream& inFile) {
    string filename;
    cout<<"Enter the filename: "<<endl;
    cin>>filename;
    inFile.open(filename);
    while (!inFile) {
        cout<<"File failed to open."<<endl;
        out<<"Enter the filename: "<<endl;
        cin>>filename;
        inFile.clear();
        inFile.open(filename);
    }
}

int main() {
    
}
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
        void setAmountPaid(double amountPaid)
        void setName(string name)
};

int main() {
    
}
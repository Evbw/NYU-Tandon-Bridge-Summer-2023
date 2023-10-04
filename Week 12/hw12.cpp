#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Money {
    public:
        friend Money operator +(const Money& amount1, const Money& amount2);
        //Returns the sum of the values of amount1 and amount2.

        friend Money operator -(const Money& amount1, const Money& amount2);
        //Returns amount1 minus amount2.

        friend Money operator -(const Money& amount);
        //Returns the negative of the value of amount.

        friend bool operator ==(const Money& amount1, const Money& amount2);
        //Returns true if amount1 and amount2 have the same value; false otherwise.

        friend bool operator <(const Money& amount1, const Money& amount2);
        //Returns true if amount1 is less than amount2; false otherwise.

        Money(double dollars);
        //Initalizes the object so its value represents $dollars.00.

        Money();
        //Initalizes the object so its value represents $0.00.

        double get_value() const {return all_cents;}
        //Returns the amount of money recorded in the data portion of the calling object.

        void set_value(double amount) {all_cents = amount;}
        friend istream& operator >>(istream& ins, Money& amount);
        //Overloads the >> operator so it can be used to input values of type Money.
        //Notation for inputting negative amounts is as in -$100.00.
        //Precondition: If ins is a file input stream, then ins has already been
        //connected to a file.

        friend ostream& operator <<(ostream& outs, const Money& amount);
        //Overloads the << operator so it can be used to output values of type Money.
        //Precedes each output value of type Money with a dollar sign.
        //Precondition: If outs is a file output stream, then outs has already been
        //connected to a file.

    private:
        double all_cents;
};

class Check {
    private:
        int check_number;
        Money check_amount;
        bool cashed;
    public:
    
        Check(int check_num, Money check_am, bool cashed_check);

        Check();

        int get_check_number() const;

        Money get_check_amount() const;

        bool get_cashed() const;

        void set_check_number(int check_num);

        void set_check_amount(Money check_am);

        void set_cashed(bool cashed_check);

        friend bool operator <(const Check& amount1, const Check& amount2);

        friend istream& operator >>(istream& ins, Check& amount);

        friend ostream& operator <<(ostream& outs, const Check& amount);
        
};

bool compareChecksByNumber(Check check1, Check check2);

int main() {
    vector<Check> uncashed_check_vector, cashed_check_vector;
    double current_balance, new_balance;
    double amount;
    int check_num;
    Money check_am, sum_cashed_checks, sum_uncashed_checks;
    bool cashed_check;
    char cashed_check_char;

    cout<<"Please enter your current bank balance without a dollar sign (e.g. 100.00): "<<endl;
    cin>>current_balance;
    new_balance = current_balance;

    cout<<"Please enter any deposits you may have. Enter 0 when you have no more deposits: "<<endl;
    cin>>amount;
    
    while(amount > 0) {
        new_balance += amount;
        cin>>amount;
    }

    cout<<"With the added deposits, the new balance is $"<<new_balance<<"."<<endl;
    
    cout<<"Please enter any checks you have written in the format check-number, check-amount,"
        <<" cashed-status (e.g. 112 100.11 N). End output with 0 0 N: "<<endl;
    
    while(true) {
        cin>>check_num>>amount>>cashed_check_char;
        if((check_num == 0 && amount == 0 && cashed_check_char == 78) || (check_num == 0 && check_am == 0 && cashed_check_char == 110)) {
            break;
        }
        
        if (cashed_check_char == 78 || cashed_check_char == 110) {
            cashed_check = false;
        }
        else if (cashed_check_char == 89 || cashed_check_char == 121) {
            cashed_check = true;
        }

        Money amount_of_check(amount);

        Check new_check(check_num, amount_of_check, cashed_check);
        
        if(cashed_check) {
            cashed_check_vector.push_back(new_check);
        }
        else {
            uncashed_check_vector.push_back(new_check);
        }
    }

    sort(cashed_check_vector.begin(), cashed_check_vector.end(), compareChecksByNumber);
    sort(uncashed_check_vector.begin(), uncashed_check_vector.end(), compareChecksByNumber);

    for (Check check: cashed_check_vector) {
        sum_cashed_checks = sum_cashed_checks + check.get_check_amount();
    }
        
    for (Check check: uncashed_check_vector) {
        sum_uncashed_checks = sum_uncashed_checks + check.get_check_amount();
    }

    cout<<"The current balance $"<<setprecision(2)<<fixed<<new_balance<<" less the cashed checks is "<<setprecision(2)<<fixed<<new_balance - sum_cashed_checks<<"."<<endl;
    cout<<"The usable balance is "<<setprecision(2)<<fixed<<new_balance - sum_cashed_checks - sum_uncashed_checks<<"."<<endl;
    
    if ( !cashed_check_vector.empty() ) {
        cout<<"The cashed checks are: "<<endl;
        for (auto x: cashed_check_vector) {
            cout<<"Check number "<<x.get_check_number()<<" for amount "<<setprecision(2)<<fixed<<x.get_check_amount()<<endl;
        }
    }
    if ( !uncashed_check_vector.empty() ) {
        cout<<"The uncashed checks are: "<<endl;
        for (auto y: uncashed_check_vector) {
            cout<<"Check number "<<y.get_check_number()<<" for amount "<<setprecision(2)<<fixed<<y.get_check_amount()<<endl;
        }
    }
}

bool compareChecksByNumber(Check check1, Check check2) { 
    return (check1.get_check_number()<check2.get_check_number());
}

int digit_to_int(char c) {
    return static_cast<int>(c) - static_cast<int>('0');
}

Money::Money(double amount) : all_cents(amount) {
    //Body intentionally left blank.
}

Money::Money() : all_cents(0) {
    //Body intentionally left blank.
}

Money operator +(const Money& amount1, const Money& amount2) {
    Money temp;
    temp.all_cents = amount1.all_cents + amount2.all_cents;
    return temp;
}

Money operator -(const Money& amount1, const Money& amount2) {
    Money temp;
    temp.all_cents = amount1.all_cents - amount2.all_cents;
    return temp;
}

Money operator -(const Money& amount) {
    Money temp;
    temp.all_cents = -amount.all_cents;
    return temp;
}

bool operator ==(const Money& amount1, const Money& amount2) {
    return (amount1.all_cents == amount2.all_cents);
}

bool operator <(const Money& amount1, const Money& amount2) {
    return (amount1.all_cents < amount2.all_cents);
}

ostream& operator <<(ostream& outs, const Money& amount) {
    
    if (amount.all_cents < 0 ) {
        outs<<"-$"<<-amount.all_cents;
    }
    else {
        outs<<"$"<<amount.all_cents;
    }

    return outs;
}

Check::Check(int check_num, Money check_am, bool cashed_check) {
    check_number = check_num;
    if (check_am < 0) {
        cout<<"Illegal values for dollars and cents.\n";
        exit(1);
    }
    check_amount = check_am;
    cashed = cashed_check;
}

Check::Check() : check_number(0), cashed(false) {
    Money check_am;
    check_amount = check_am;
}

bool operator <(const Check& amount1, const Check& amount2) {
    return (amount1.check_amount < amount2.check_amount);
}

int Check::get_check_number() const {
    return check_number;
};

Money Check::get_check_amount() const {
    return check_amount;
}

bool Check::get_cashed() const {
    return cashed;
};

void Check::set_check_number(int check_num) {
    check_number = check_num;
}

void Check::set_check_amount(Money check_am) {
    check_amount = check_am;
}

void Check::set_cashed(bool cashed_check) {
    cashed = cashed_check;
}

ostream& operator <<(ostream& outs, const Check& check) {
        
    outs<<check.check_amount;

    return outs;
}
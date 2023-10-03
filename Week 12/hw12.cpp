#include <iostream>
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
    
        Check(int check_num, Money check_am, bool cashedCheck);
        //Initializes the object with an identifier value so its value 
        //represents an amount with the dollars and cents given by the 
        //arguments. Will not accept negative amounts.

        Check();
        //Initalizes numerical values to 0 and the bool value to false.

        int get_check_number() const;

        Money get_check_amount() const;
        //Returns the amount of money recorded in the data portion of the calling object.

        bool get_cashed() const;

        void set_check_number(int check_num);

        void set_check_amount(Money check_am);

        void set_cashed(bool cashedCheck);

        friend bool operator <(const Check& amount1, const Check& amount2);
        //Returns true if amount1 is less than amount2; false otherwise.

        friend istream& operator >>(istream& ins, Check& amount);
        //Overloads the >> operator so it can be used to input values of type Money.
        //Notation for inputting negative amounts is as in -$100.00.
        //Precondition: If ins is a file input stream, then ins has already been
        //connected to a file.

        friend ostream& operator <<(ostream& outs, const Check& amount);
        //Overloads the << operator so it can be used to output values of type Money.
        //Precedes each output value of type Money with a dollar sign.
        //Precondition: If outs is a file output stream, then outs has already been
        //connected to a file.
};

//Reads in 5 amounts of money and shows how much each
//amount differs from the largest amount.
int main() {
    Check amount[5];
    // Check cashed_checks[5];
    int i;
    // Check amount;
    
    cout<<"Enter 5 checks to deposit:\n";
    // cin>>amount;
    cin>>amount[0];
    for (i = 1; i < 5; i++) {
        cin>>amount[i];
    }
    
    cout<<"Checks of the amounts:\n";
    
    for (i = 0; i < 5; i++) {
        cout<<amount[i]<<endl;
    }
    
    cout<<" have been cashed.";

    return 0;
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

int digit_to_int(char c);
//Used in the definition of the overloaded input operator >>.
//Precondition: c is one of the digits '0' through '9'.
//Returns the integer for the digit; for example, digit_to_int('3') returns 3.

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

istream& operator >>(istream& ins, Money& amount) {
    char one_char, decimal_point, digit1, digit2;
    long dollars;
    int cents;
    bool negative;

    ins>>one_char;

    if (one_char == '-') {
        negative = true;
        ins>>one_char; //read '$'
    }
    else {
        negative = false;
    }

    ins>>dollars>>decimal_point>>digit1>>digit2;

    if (one_char != '$' || decimal_point != '.' || !isdigit(digit1) || !isdigit(digit2)) {
        cout<<"Error illegal form for money input\n";
        exit(1);
    }

    cents = digit_to_int(digit1) * 10 + digit_to_int(digit2);
    amount.all_cents = dollars * 100 + cents;

    if (negative) {
        amount.all_cents = -amount.all_cents;
    }

    return ins;
}

ostream& operator <<(ostream& outs, const Money& amount) {
    long positive_cents, dollars, cents;
    positive_cents = labs(amount.all_cents);
    dollars = positive_cents / 100;
    cents = positive_cents % 100;

    if (amount.all_cents < 0 ) {
        outs<<"-$"<<dollars<<'.';
    }
    else {
        outs<<"$"<<dollars<<'.';
    }

    if (cents < 10) {
        outs<<'0';
    }

    outs<<cents;

    return outs;
}

Check::Check(int check_num, Money check_am, bool cashedCheck) {
    check_number = check_num;
    if (check_am < 0) {
        cout<<"Illegal values for dollars and cents.\n";
        exit(1);
    }
    check_amount = check_am;
    cashed = cashedCheck;
}

Check::Check() : check_number(0), cashed(false) {
    Money check_am;
    check_amount = check_am;
}

bool operator <(const Check& amount1, const Check& amount2) {
    return (amount1.check_amount < amount2.check_amount);
}

void Check::set_check_number(int check_num) {
    check_number = check_num;
}

void Check::set_check_amount(Money check_am) {
    check_amount = check_am;
}

void Check::set_cashed(bool cashedCheck) {
    cashed = cashedCheck;
}

istream& operator >>(istream& ins, Check& amount) {
    char one_char, decimal_point, digit1, digit2;
    long dollars;
    int cents;

    ins>>one_char>>dollars>>decimal_point>>digit1>>digit2;

    if (one_char != '$' || decimal_point != '.' || !isdigit(digit1) || !isdigit(digit2)) {
        cout<<"Error illegal form for check input\n";
        exit(1);
    }

    cents = digit_to_int(digit1) * 10 + digit_to_int(digit2);
    amount.check_amount = dollars * 100 + cents;

    return ins;
}

ostream& operator <<(ostream& outs, const Check& check) {
        
    outs<<check.check_amount;

    return outs;
}
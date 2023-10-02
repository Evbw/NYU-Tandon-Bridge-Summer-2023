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

        Money(long dollars, int cents);
        //Initializes the object so its value represents an amount with
        //the dollars and cents given by the arguments. If the amount
        //is negative, then both dollars and cents should be negative.

        Money(long dollars);
        //Initalizes the object so its value represents $dollars.00.

        Money();
        //Initalizes the object so its value represents $0.00.

        double get_value() const;
        //Returns the amount of money recorded in the data portion of the calling object.

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
        long all_cents;
};

class Check {
    private:
        int check_number;
        double check_amount;
        bool cashed;
    public:
    
        Check(int check_number, long dollars, int cents, bool cashed);
        //Initializes the object with an identifier value so its value 
        //represents an amount with the dollars and cents given by the 
        //arguments. Will not accept negative amounts.

        Check(int check_number, long dollars, bool cashed);
        //Initalizes the object so its value represents $dollars.00.

        Check(int check_number, bool cashed);
        //Initalizes the object so its value represents $0.00 and sets the bool value to false.

        Check();
        //Initalizes numerical values to 0 and the bool value to false.

        double get_value() const;
        //Returns the amount of money recorded in the data portion of the calling object.

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
    Money amount[5], max;
    int i;
    
    cout<<"Enter 5 amounts of money:\n";
    cin>>amount[0];
    max = amount[0];
    for (i = 1; i < 5; i++) {
        cin>>amount[i];
        if (max < amount[i])
            max = amount[i];
        //max is the largest of amount[0]...amount[i].
    }

    Money difference[5];
    for (i = 0; i < 5; i++)
        difference[i] = max - amount[i];
    cout<<"The highest amount is "<<max<<endl;
    cout<<"The amounts and their\n"
        <<"differences from the largest are:\n";
    for (i = 0; i < 5; i++)
    {
        cout<<amount[i]<<" of by "<<difference[i]<<endl;
    }
    return 0;
}

int digit_to_int(char c) {
    return static_cast<int>(c) - static_cast<int>('0');
}

Money::Money(long dollars, int cents) {
    if (dollars * cents < 0) {
        cout<<"Illegal values for dollars and cents.\n";
        exit(1);
    }

    all_cents = dollars * 100 + cents;
}

Money::Money(long dollars) : all_cents(dollars * 100) {
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

Check::Check(int check_number, long dollars, int cents, bool cashed) {
    check_number = check_number;
    if (dollars * cents < 0) {
        cout<<"Illegal values for dollars and cents.\n";
        exit(1);
    }
    check_amount = dollars * 100 + cents;
    cashed = false;
}

Check::Check(int check_number, long dollars, bool cashed) {
    check_number = check_number;
    if (dollars < 0) {
        cout<<"Illegal values for dollars and cents.\n";
        exit(1);
    }
    check_amount = dollars * 100;
    cashed = false;
}

Check::Check(int check_number, bool cashed) {
    check_number = check_number;
    cashed = false;
}

Check::Check() : check_number(0), check_amount(0), cashed(false) {
    //Body intentionally left blank.
}
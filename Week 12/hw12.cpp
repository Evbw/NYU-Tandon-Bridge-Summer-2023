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
        //Created an amount that could be used fractionally.
};

class Check {
    private:
        //Initialize variables based on identification parameters
        int check_number;
        Money check_amount;
        bool cashed;
    public:
    
        Check(int check_num, Money check_am, bool cashed_check);
        //Initializes the object with a check_num, an amount of type Money, and whether it is cashed or not
        Check();
        //Initializes the object with empty/false variables
        int get_check_number() const;
        //Returns the check_number of the check object
        Money get_check_amount() const;
        //Returns the check_amount of the check object
        bool get_cashed() const;
        //Returns the bool of whether the check object is cashed or not
        void set_check_number(int check_num);
        //Sets the check_number of the check object
        void set_check_amount(Money check_am);
        //Sets the check_amount of the check object
        void set_cashed(bool cashed_check);
        //Sets the bool of whether the check object is cashed or not
        friend bool operator <(const Check& amount1, const Check& amount2);
        //Returns true if amount1 is less than amount2; false otherwise.
        friend istream& operator >>(istream& ins, Check& amount);
        //Overloads the >> operator so it can be used to input values of type Money.
        friend ostream& operator <<(ostream& outs, const Check& amount);
        //Overloads the << operator so it can be used to input values of type Money.
        
};

bool compareChecksByNumber(Check check1, Check check2);
//Define a non-member function to compare the values of checks

int main() {
    vector<Check> uncashed_check_vector, cashed_check_vector;
    //Declare vectors for the cashed and uncashed checks
    double current_balance, new_balance;
    //Declare a two balances, one for the user to enter and the balance after calculating new amounts
    double amount;
    //Declare an amount for deposits
    int check_num;
    //Declare an entry for the check number
    Money check_am, sum_cashed_checks, sum_uncashed_checks;
    //Declare three Money variables for the amount of the check and the sums of the cashed and uncashed checks
    bool cashed_check;
    //Declare a bool to see if the check was cashed
    char cashed_check_char;
    //Declare an entry variable to accept input to determine if the check has been cashed or not

    cout<<"Please enter your current bank balance without a dollar sign (e.g. 100.00): "<<endl;
    cin>>current_balance;
    new_balance = current_balance;
    //Request and accept input for the bank balance. Set the new balance to the current balance so adding deposits and deducting checks will be accurate

     cout << "Please enter your checks (check number, amount, cashed status). End with 0 0 N:" << endl;
    while (true) {
        cin >> check_num >> amount >> cashed_check_char;

        // Check for termination condition
        if ((check_num == 0 && amount == 0 && toupper(cashed_check_char) == 'N')) {
            break;
        }

        // Convert char to boolean for cashed status
        cashed_check = (toupper(cashed_check_char) == 'Y');

        Money amount_of_check(amount);

        // Check for duplicate check number
        bool isDuplicate = false;
        for (const Check& c : uncashed_check_vector) {
            if (c.get_check_number() == check_num) {
                isDuplicate = true;
                break;
            }
        }
        for (const Check& c : cashed_check_vector) {
            if (c.get_check_number() == check_num) {
                isDuplicate = true;
                break;
            }
        }

        if (isDuplicate) {
            cout << "Duplicate check number entered. Please re-enter check details." << endl;
            continue;
        }

        // Create and add the check to the appropriate vector
        Check new_check(check_num, amount_of_check, cashed_check);
        if (cashed_check) {
            cashed_check_vector.push_back(new_check);
        } else {
            uncashed_check_vector.push_back(new_check);
        }
    }

    cout<<"With the added deposits, the new balance is $"<<new_balance<<"."<<endl;
    //Display the new balance after deposits.
    cout<<"Please enter any checks you have written in the format check-number, check-amount,"
        <<" cashed-status (e.g. 112 100.11 N). End output with 0 0 N: "<<endl;
    //Request input for checks written by the user and if they have been cashed or not along with instructions for triggering the escape clause
    //As an aside, I find it amusing that we're writing a routine to do this when the user would have to see their balance
    //to know if a check has been cashed
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
    //Sort the vectors for cashed and uncashed checks
    for (Check check: cashed_check_vector) {
        sum_cashed_checks = sum_cashed_checks + check.get_check_amount();
    }
    //Add the total values for cashed checks
    for (Check check: uncashed_check_vector) {
        sum_uncashed_checks = sum_uncashed_checks + check.get_check_amount();
    }
    //Add the total values for uncashed checks
    cout<<"The current balance $"<<setprecision(2)<<fixed<<new_balance<<" less the cashed checks is "<<setprecision(2)<<fixed<<new_balance - sum_cashed_checks<<"."<<endl;
    cout<<"The usable balance is "<<setprecision(2)<<fixed<<new_balance - sum_cashed_checks - sum_uncashed_checks<<"."<<endl;
    //Display the balance minus the cashed checks, then display the balance minus all written checks
    if ( !cashed_check_vector.empty() ) {
        cout<<"The cashed checks are: "<<endl;
        for (auto x: cashed_check_vector) {
            cout<<"Check number "<<x.get_check_number()<<" for amount "<<setprecision(2)<<fixed<<x.get_check_amount()<<endl;
        }
    }
    //Don't display the output for the vector if there are no cashed checks. Otherwise, display the checks sorted from smallest check number to greatest
    if ( !uncashed_check_vector.empty() ) {
        cout<<"The uncashed checks are: "<<endl;
        for (auto y: uncashed_check_vector) {
            cout<<"Check number "<<y.get_check_number()<<" for amount "<<setprecision(2)<<fixed<<y.get_check_amount()<<endl;
        }
    }
    //Don't display the output for the vector if there are no uncashed checks. Otherwise, display the checks sorted from smallest check number to greatest
}

bool compareChecksByNumber(Check check1, Check check2) { 
    return (check1.get_check_number()<check2.get_check_number());
}
//Function to compare the check numbers and determine if the first is smaller than the second
Money::Money(double amount) : all_cents(amount) {
    //Body intentionally left blank.
}
//Money constructor
Money::Money() : all_cents(0) {
    //Body intentionally left blank.
}
//Empty money constructor
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
//Overloaded << operator to handle negative amounts of money and handles $ display
Check::Check(int check_num, Money check_am, bool cashed_check) {
    check_number = check_num;
    if (check_am < 0) {
        cout<<"Illegal values for dollars and cents.\n";
        exit(1);
    }
    check_amount = check_am;
    cashed = cashed_check;
}
//Construct a check. Negative amounts are not allowed
Check::Check() : check_number(0), cashed(false) {
    Money check_am;
    if (check_am < 0) {
        cout<<"Illegal values for dollars and cents.\n";
        exit(1);
    }
    check_amount = check_am;
}
//Construct a check with just an amount. Negative amounts are not allowed
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
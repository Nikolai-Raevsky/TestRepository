#ifndef _SAVINGS_ACCOUNT_H_
#define _SAVINGS_ACCOUNT_H_
#include "Account.h"

// Savings Account is a type of Account
//   adds an interest rate
// Withdraw - same as a regular account

//

class Savings_Account: public Account {
    friend std::ostream &operator<<(std::ostream &os, const Savings_Account &account);
private:
    static constexpr const char *def_name = "Unnamed Savings Account";
    static constexpr double def_balance = 0.0;
    static constexpr double def_int_rate = 0.0;
protected:
    double int_rate;
public:
	//This is a constructor that initializes name, balance, and int_rate. By default they are assigned to def_name, def_balance, and def_int_rate respectively
    Savings_Account(std::string name = def_name, double balance =def_balance, double int_rate = def_int_rate);    
	// Deposit:
//      Amount supplied to deposit will be incremented by (amount * int_rate/100) 
//      and then the updated amount will be deposited
	//amount will be amount of money the user requests to deposit in the account
	//Return:
	//	Bool: Returns a bool to be used in the account_util deposit function to determine what message to output to the console
	bool deposit(double amount);
    // Inherits the Account::withdraw methods
};

#endif // _SAVINGS_ACCOUNT_H_

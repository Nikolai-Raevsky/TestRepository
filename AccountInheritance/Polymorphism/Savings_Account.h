//////////////////////////////////////////////////////
//	Filename: Savings_Account.h
//	Name: Nikolai Raevsky (nikolai.raevsky@digipen.edu)
//	Project: PRG 7.29 Practice - Account Class With Polymorphism
//	Course: WANIC VGP2
//////////////////////////////////////////////////////

#ifndef _SAVINGS_ACCOUNT_H_
#define _SAVINGS_ACCOUNT_H_
#include "Account.h"
#include "I_Printable.h"

class Savings_Account: public Account {
    
private:
    static constexpr const char *def_name = "Unnamed Savings Account";
    static constexpr double def_balance = 0.0;
    static constexpr double def_int_rate = 0.0;
protected:
    double int_rate;
public:
	//This Savings_Account constructor initializes a Savings_Account with name string, a balance double, and an int_rate double set to def_name, def_balance, and def_int_rate by default
    Savings_Account(std::string name = def_name, double balance =def_balance, double int_rate = def_int_rate);
	/**********-deposit notes-************/
	//Description: 
	//	Deposits money into account balance. This also deposits an interest rate bonus into the account
	//Params:
	//	amount: The amount that the user requests to be deposited into the account
	//Returns:
	//	Returns true after adding the amount and the interest bonus to the account
    bool deposit(double amount);
    // Inherits the Account::withdraw method

	/**********-print notes-************/
	//Description: 
	//	Outputs the account information when called
	//Params:
	//	os: A reference to an ostream that the account information gets outputted to
	
    virtual void print(std::ostream& os) const override;
};

#endif // _SAVINGS_ACCOUNT_H_

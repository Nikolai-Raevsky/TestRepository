#ifndef _CHECKING_ACCOUNT_H
#define _CHECKING_ACCOUNT_H
#include "Account.h"

//************************************************
// Filename: Trust_Account.cpp
// Name: Nikolai Raevsky (nikolai.raevsky@digipen.edu)
// Teacher: Jeremy Kings (jeremy.kings@digipen.edu)
// Assignment: PRG 7.1.9 PRACTICE: Account Class with Inheritance
//************************************************


//Checking Account is an account with a name and a balance. 
// Checking_Account constructor constructs a checking account with a name and a balance that gets initialized into the Account parent class


//
class Checking_Account : public Account {
	// << overload outputs the account's name and balance to the console
	friend std::ostream &operator<<(std::ostream& os, const Checking_Account& account);
private:
	static constexpr const char* def_name = "Unnamed Checking Account";
	static constexpr double def_balance = 0.0;
	

public:
	// Checking_Account constructor constructs a checking account with a name and a balance that gets initialized into the Account parent class
	Checking_Account(std::string name = def_name, double balance = def_balance);
	
	// withdraw method deducts a $1.50 fee from the balance and subtracts the amount parameter from the account's balance
	//Params:
	//	amount: a double that will be subtracted from the user's account
	//Returns:
	//	Bool: it will be used in the account util withdraw function to determine what message to print
	bool withdraw(double amount);
	//We're going to steal the deposit method from the parent class and nobody will stop us
};

#endif

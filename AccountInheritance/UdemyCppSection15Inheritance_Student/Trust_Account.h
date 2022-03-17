//************************************************
// Filename: Trust_Account.h
// Name: Nikolai Raevsky (nikolai.raevsky@digipen.edu)
// Teacher: Jeremy Kings (jeremy.kings@digipen.edu)
// Assignment: PRG 7.1.9 PRACTICE: Account Class with Inheritance
//************************************************
#ifndef _TRUST_ACCOUNT_
#define _TRUST_ACCOUNT_
#include "Account.h"
#include "Savings_Account.h"
/*
* TRUST_ACCOUNT DOCUMENTATION:
* Trust_Account has name, balance, interest rate, and withdrawl counting variables
* 
* 
* 
* 
* 
*/

class Trust_Account : public Savings_Account
{
	friend std::ostream& operator<<(std::ostream& os, const Trust_Account& account);

private:
	static constexpr const char* def_name = "Unnamed Trust Account";
	static constexpr double def_balance = 0.0;
	static constexpr double def_int_rate = 0;
protected:
	
	int withdrawals = 0;
public:
	//Trust_Account constructor: Initializes a Trust_Account object with a name and balance stored in the parent Account class and an int_rate inherited from the SavingsAccount class. The variables are initialized to def_name, def_balance, and def_int_rate by default
	Trust_Account(std::string name = def_name, double balance = def_balance, double int_rate = def_int_rate);

	// Deposit:
	//      Amount supplied to deposit will be incremented by (amount * int_rate/100). A $50 bonus will be added to the account if the amount exceeds 5000
	//      and then the updated amount will be deposited
		//Params:
		//	amount: The amount of money the user requests to deposit in the account
		//Return:
		//	Bool: Returns a bool to be used in the account_util deposit function to determine what message to output to the console
	bool deposit(double amount);
	// 
	//
	//	withdraw: Withdraws a maximum of 20% of the balance from the account. If the amount is greater than that or if the withdrawl counter exceeds 3, the withdrawal fails
	//Params:
	//	amount: The amount the user requests to withdraw
	//Returns:
	//	A bool that will be used to determine what message is displayed in Account_Util's withdraw function
	bool withdraw(double amount);
};


#endif

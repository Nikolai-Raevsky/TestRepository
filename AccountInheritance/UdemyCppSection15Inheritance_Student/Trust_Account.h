//************************************************
// Filename: Trust_Account.h
// Name: Nikolai Raevsky (nikolai.raevsky@digipen.edu)
// Teacher: Jeremy Kings (jeremy.kings@digipen.edu)
// Assignment: PRG 7.1.9 PRACTICE: Account Class with Inheritance
//************************************************
#ifndef _TRUST_ACCOUNT_
#define _TRUST_ACCOUNT_
#include "Account.h"

/*
* TRUST_ACCOUNT DOCUMENTATION:
* Trust_Account has name, balance, interest rate, and withdrawl counting variables
* Trust_Account constructor: Initializes a Trust_Account object with a name and balance stored in the parent Account class and an internally stored int_rate 
* deposit: Deposits the amount multiplied by the interest rate into the account balance. If the deposit amount is greater than or equal to 5000, the balance also gets a 50 dollar bonus.
* Withdraw: Withdraws a maximum of 20% of the balance from the account. If the amount is greater than that or if the withdrawl counter exceeds 3, the withdrawal fails
* 
* 
*/

class Trust_Account : public Account
{
	friend std::ostream& operator<<(std::ostream& os, const Trust_Account& account);

private:
	static constexpr const char* def_name = "Unnamed Trust Account";
	static constexpr double def_balance = 0.0;
	static constexpr double def_int_rate = 0;
protected:
	double int_rate;
	int withdrawals = 0;
public:
	Trust_Account(std::string name = def_name, double balance = def_balance, double int_rate = def_int_rate);
	bool deposit(double amount);
	bool withdraw(double amount);
};


#endif

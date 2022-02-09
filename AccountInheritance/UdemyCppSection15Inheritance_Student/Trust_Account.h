//************************************************
// Filename: Trust_Account.h
// Name: Nikolai Raevsky (nikolai.raevsky@digipen.edu)
// Teacher: Jeremy Kings (jeremy.kings@digipen.edu)
// Assignment: PRG 7.1.9 PRACTICE: Account Class with Inheritance
//************************************************
#ifndef _TRUST_ACCOUNT_
#define _TRUST_ACCOUNT_
#include "Account.h"

class Trust_Account : public Account
{
	friend std::ostream& operator<<(std::ostream& os, const Trust_Account& account);

private:
	static constexpr const char* def_name = "Unnamed Checking Account";
	static constexpr double def_balance = 0.0;
	static constexpr double def_int_rate = 0;
protected:
	double int_rate;
public:
	Trust_Account(std::string name = def_name, double balance = def_balance, double int_rate = def_int_rate);
	bool deposit(double amount);
	bool withdraw(double amount);
};


#endif

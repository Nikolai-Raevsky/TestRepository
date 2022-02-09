#ifndef _CHECKING_ACCOUNT_H
#define _CHECKING_ACCOUNT_H
#include "Account.h"
#include <iostream>
//************************************************
// Filename: Trust_Account.cpp
// Name: Nikolai Raevsky (nikolai.raevsky@digipen.edu)
// Teacher: Jeremy Kings (jeremy.kings@digipen.edu)
// Assignment: PRG 7.1.9 PRACTICE: Account Class with Inheritance
//************************************************

class Checking_Account : public Account {
private:
	static constexpr const char* def_name = "Unnamed Checking Account";
	static constexpr double def_balance = 0.0;
	

public:
	//Make a constructor
	Checking_Account(std::string name = def_name, double balance = def_balance);
	
	//Make a withdraw function
	bool
};

#endif

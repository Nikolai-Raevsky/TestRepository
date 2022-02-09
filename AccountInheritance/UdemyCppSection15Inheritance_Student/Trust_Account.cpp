//************************************************
// Filename: Trust_Account.cpp
// Name: Nikolai Raevsky (nikolai.raevsky@digipen.edu)
// Teacher: Jeremy Kings (jeremy.kings@digipen.edu)
// Assignment: PRG 7.1.9 PRACTICE: Account Class with Inheritance
//************************************************


//IMPORTANT FUNCTIONS
//
// Account::withdraw
// Account::deposit
// Trust_account.h functions

#include "Trust_Account.h"
#include <iostream>

std::ostream& operator<< (std::ostream& os, const Trust_Account& account)
{
	std::cout << "[Account name: " << account.name << ": " << account.balance << ", " << account.int_rate << "]";
	return os;
}



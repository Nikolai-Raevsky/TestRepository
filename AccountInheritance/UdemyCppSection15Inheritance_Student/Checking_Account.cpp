//************************************************
// Filename: Checking_Account.cpp
// Name: Nikolai Raevsky (nikolai.raevsky@digipen.edu)
// Teacher: Jeremy Kings (jeremy.kings@digipen.edu)
// Assignment: PRG 7.1.9 PRACTICE: Account Class with Inheritance
//************************************************
#include <ostream>
#include "Checking_Account.h"


//IMPORTANT FUNCTIONS FROM OTHER FILES TO REMEMBER
// bool Account::withdraw
// The functions in Checking_Account.h (Checking_Account(std::string 
//Make a constructor
Checking_Account::Checking_Account(std::string name, double balance) : Account(name, balance)
{

}

//Make a withdraw function
bool Checking_Account::withdraw(double amount)
{
	if (amount > balance)
	{
		return Account::withdraw(amount);
	}
	balance -= 1.50;
	return Account::withdraw(amount);
}

std::ostream& operator<<(std::ostream& os, const Checking_Account& account)
{
	std::cout << "[Checking_Account: " << account.name << ": " << account.balance << "]";
	return os;
}
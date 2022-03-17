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
#include "Savings_Account.h"
#include "Trust_Account.h"
#include <iostream>

std::ostream& operator<< (std::ostream& os, const Trust_Account& account)
{
	std::cout << "[Trust Account: " << account.name << ": " << account.balance << ", " << account.int_rate << "%, withdrawals: " << account.withdrawals << "]";
	return os;
}

Trust_Account::Trust_Account(std::string name, double balance, double int_rate) 
	: Savings_Account{ name, balance, int_rate }
{

}

bool Trust_Account::deposit(double amount)
{
	if (amount >= 5000)
	{
		amount += 50;
	}
	amount += amount * (int_rate / 100);
	
	return Account::deposit(amount);
}

bool Trust_Account::withdraw(double amount)
{
	double withdrawLimit = balance * .2;
	if (amount < withdrawLimit) //I LEFT HERE
	{
		
		withdrawals += 1;
		if (withdrawals > 3)
		{
			//std::cout << "withdrawals conditional is triggered. ";
			withdrawals = 3;
			return false;
		}

		else
		{
			//std::cout << "Mark that withdrawls have not exceeded 3 ";
			return Account::withdraw(amount);
		}
			
		
	}
	else
	{
		
		//std::cout << "The amount withdrawn is more than 20% ";
		return false;
	}
		

	

	
}



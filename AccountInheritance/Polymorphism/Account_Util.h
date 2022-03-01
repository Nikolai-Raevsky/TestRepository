//////////////////////////////////////////////////////
//	Filename: Account_Util.h
//	Name: Nikolai Raevsky (nikolai.raevsky@digipen.edu)
//	Project: PRG 7.29 Practice - Account Class With Polymorphism
//	Course: WANIC VGP2
//////////////////////////////////////////////////////


#ifndef _ACCOUNT_UTIL_H_
#define _ACCOUNT_UTIL_H_
#include <vector>
#include "Account.h"
#include "Savings_Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"


/**********-display notes-************/
	//Description: 
	//	Outputs a vector of account pointers
	//Params:
	//	&accounts: a reference to the account pointer vector being outputted
	
void display(const std::vector<Account *> &accounts);

/**********-deposit notes-************/
	//Description: 
	//	Displays a confirmation or failure of account deposits
	//Params:
	//	accounts: A vector of account pointers that (after dereferencing) the function will check
	//	amount: The amount of money (trying to be) deposited into the account balance
	
void deposit(std::vector<Account *> &accounts, double amount);

/**********-withdraw notes-************/
	//Description: 
	//	Displays a withdrawal confirmation or denial
	//Params:
	//	accounts: A vector of account pointers that (after dereferencing) the function will check
	//	amount: The amount of money (trying to be) withdrawn from the account balance
	
void withdraw(std::vector<Account *> &accounts, double amount);



#endif
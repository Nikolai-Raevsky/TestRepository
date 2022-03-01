//////////////////////////////////////////////////////
//	Filename: Checking_Account.h
//	Name: Nikolai Raevsky (nikolai.raevsky@digipen.edu)
//	Project: PRG 7.29 Practice - Account Class With Polymorphism
//	Course: WANIC VGP2
//////////////////////////////////////////////////////

#ifndef _CHECKING_ACCOUNT_H_
#define _CHECKING_ACCOUNT_H_
#include <iostream>
#include <string>
#include "Account.h"
#include "I_Printable.h"

class Checking_Account: public Account {
    
private:
    static constexpr const char *def_name = "Unnamed Checking Account";
    static constexpr double def_balance = 0.0;
    static constexpr double per_check_fee = 1.5;
public:
	//Checking_Account constructor constructs a Checking_Account with name and balance set to def_name and def_balance by default
    Checking_Account(std::string name = def_name, double balance = def_balance);    
	/**********-withdraw notes-************/
	//Description: 
	//	Withdraws money from account balance account balance with an additional checking fee
	//Params:
	//	amount: The amount of money the user requests to withdraw
	//Returns:
	//	Returns true if the difference of the balance and the amount + checking_account fee are greater than or equal to 0, false otherwise

    bool withdraw(double amount);
    // Inherits the Account::deposit method

	/**********-print notes-************/
	//Description: 
	//	Used by << operator to output account information to console
	//Params:
	//	os: The ostream that the account information gets outputted to
	
    virtual void print(std::ostream& os) const override;
};

#endif // _CHECKING_ACCOUNT_H_

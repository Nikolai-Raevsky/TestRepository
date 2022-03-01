//////////////////////////////////////////////////////
//	Filename: Account.h
//	Name: Nikolai Raevsky (nikolai.raevsky@digipen.edu)
//	Project: PRG 7.29 Practice - Account Class With Polymorphism
//	Course: WANIC VGP2
//////////////////////////////////////////////////////



// Simple Account 
#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include <iostream>
#include <string>
#include "I_Printable.h"
//I have to remember that if I have to deal with more stupid project stuff from PolymorphicAccount being in the same solution as the Inheritance project, I'm going to make a new solution

class Account : public I_Printable{
    
private:   
    static constexpr const char *def_name = "Unnamed Account";
    static constexpr double def_balance = 0.0;
protected:
    std::string name;
    double balance;
public:
	//This Account function constructs an account with a name set to def_name and a balance set to def_balance

    Account(std::string name = def_name, double balance = def_balance);


	/**********-deposit notes-************/
	//Description: 
	//	Deposits money into account balance
	//Params:
	//	amount: The amount that gets deposited into the balance
	//Returns:
	//	Returns false if the amount is less than 0 and true otherwise


    virtual bool deposit(double amount);

	/**********-withdraw notes-************/
	//Description: 
	//	Withdraws money from account balance
	//Params:
	//	amount: The amount that gets withdrawn from the balance
	//Returns:
	//	Returns true if balance-amount is greater than or equal to 0, false otherwise


    virtual bool withdraw(double amount);

	/**********-print notes-************/
	//Description: 
	//	Outputs the account name and balance
	//Params:
	//	os: The ostream that the account is being outputted to. This is required to work with the I_Printable interface
	
	virtual void print(std::ostream& os);
};
#endif
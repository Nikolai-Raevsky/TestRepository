//////////////////////////////////////////////////////
//	Filename: Trust_Account.h
//	Name: Nikolai Raevsky (nikolai.raevsky@digipen.edu)
//	Project: PRG 7.29 Practice - Account Class With Polymorphism
//	Course: WANIC VGP2
//////////////////////////////////////////////////////

#ifndef _TRUST_ACCOUNT_H_
#define _TRUST_ACCOUNT_H_

#include "Savings_Account.h"
#include "I_Printable.h"

class Trust_Account : public Savings_Account {
    friend std::ostream &operator<<(std::ostream &os, const Trust_Account &account);
private:
    static constexpr const char *def_name = "Unnamed Trust Account";
    static constexpr double def_balance = 0.0;
    static constexpr double def_int_rate = 0.0;
    static constexpr double bonus_amount = 50.0;
    static constexpr double bonus_threshold = 5000.0;
    static constexpr int max_withdrawals = 3;
    static constexpr double max_withdraw_percent = 0.2;
protected:
    int num_withdrawals;
public:
	//A constructor that initializes a Trust_Account with a name string, a balance double, and an int_rate double set to def_name, def_balance, and def_int_rate respectively by default
    Trust_Account(std::string name = def_name,  double balance = def_balance, double int_rate = def_int_rate);
    
    // Deposits of $5000.00 or more will receive $50 bonus
    bool deposit(double amount);
    
    // Only allowed maximum of 3 withdrawals, each can be up to a maximum of 20% of the account's value
    bool withdraw(double amount);
	/**********-print notes-************/
	//Description: 
	//	Outputs the trust account variables for the << operator
	//Params:
	//	os: A reference to the ostream that the variables will get outputted to
	//Returns:
	//	Returns false if the amount is less than 0 and true otherwise
    virtual void print(std::ostream& os) const override;


};

#endif // _TRUST_ACCOUNT_H_

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
    Account(std::string name = def_name, double balance = def_balance);
    virtual bool deposit(double amount);
    virtual bool withdraw(double amount);
	virtual void print(std::ostream& os);
};
#endif
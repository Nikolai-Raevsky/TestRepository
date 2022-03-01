//////////////////////////////////////////////////////
//	Filename: Checking_Account.cpp
//	Name: Nikolai Raevsky (nikolai.raevsky@digipen.edu)
//	Project: PRG 7.29 Practice - Account Class With Polymorphism
//	Course: WANIC VGP2
//////////////////////////////////////////////////////

#include "Checking_Account.h"
#include "I_Printable.h"

Checking_Account::Checking_Account(std::string name, double balance)
    : Account {name, balance} {
}

bool Checking_Account::withdraw(double amount) {
    amount += per_check_fee;
    return Account::withdraw(amount);
}



void Checking_Account::print(std::ostream& os) const
{
    os << "[Checking_Account: " << name << ": " << balance << "]";
    
}


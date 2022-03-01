//////////////////////////////////////////////////////
//	Filename: Trust_Account.cpp
//	Name: Nikolai Raevsky (nikolai.raevsky@digipen.edu)
//	Project: PRG 7.29 Practice - Account Class With Polymorphism
//	Course: WANIC VGP2
//////////////////////////////////////////////////////

#include "Trust_Account.h"
#include "I_Printable.h"

Trust_Account::Trust_Account(std::string name, double balance, double int_rate)
    : Savings_Account {name, balance, int_rate}, num_withdrawals {0}  {
        
}

// Deposit additional $50 bonus when amount >= $5000
bool Trust_Account::deposit(double amount) {
    if (amount >= bonus_threshold)
        amount += bonus_amount;
    return Savings_Account::deposit(amount);
}
    
// Only allowed 3 withdrawals, each can be up to a maximum of 20% of the account's value
bool Trust_Account::withdraw(double amount) {
    if (num_withdrawals >= max_withdrawals || (amount > balance * max_withdraw_percent))
        return false;
    else {
        ++num_withdrawals;
        return Savings_Account::withdraw(amount);
    }
}

std::ostream &operator<<(std::ostream &os, const Trust_Account &account) {
    os << "[Trust Account: " << account.name << ": " << account.balance << ", " << account.int_rate 
        << "%, withdrawals: " << account.num_withdrawals <<  "]";
    return os;
}

void Trust_Account::print(std::ostream& os) const
{
    os << "[Trust Account: " << name << ": " << balance << ", " << int_rate
        << "%, withdrawals: " << num_withdrawals << "]";
}

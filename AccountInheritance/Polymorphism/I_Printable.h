//////////////////////////////////////////////////////
//	Filename: I_Printable.h
//	Name: Nikolai Raevsky (nikolai.raevsky@digipen.edu)
//	Project: PRG 7.29 Practice - Account Class With Polymorphism
//	Course: WANIC VGP2
//////////////////////////////////////////////////////

#ifndef _I_PRINTABLE_H_
#define _I_PRINTABLE_H_
#include <iostream>
class I_Printable
{
	/**********-<< operator overload notes-************/
	//Description: 
	//	Outputs an I_Printable's outputtable variables (as determined by a print child function called within). 
	//	In this assignment, all accounts inherit from this I_Printable class so the operator generally outputs the account name, balance, and interest rate
    friend std::ostream& operator<<(std::ostream& os, const I_Printable& obj);
public:
    virtual void print(std::ostream& os) const = 0;
    virtual ~I_Printable() = default;
};
#endif


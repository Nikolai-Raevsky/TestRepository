//////////////////////////////////////////////////////
//	Filename: I_Printable.cpp
//	Name: Nikolai Raevsky (nikolai.raevsky@digipen.edu)
//	Project: PRG 7.29 Practice - Account Class With Polymorphism
//	Course: WANIC VGP2
//////////////////////////////////////////////////////



#include "I_Printable.h"
#include <iostream>

std::ostream& operator<<(std::ostream& os, const I_Printable& obj)
{
	os.precision(2);
	os << std::fixed;
	obj.print(os);
	return os;
}
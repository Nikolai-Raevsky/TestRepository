#include "I_Printable.h"
#include <iostream>

std::ostream& operator<<(std::ostream& os, const I_Printable& obj)
{
	I_Printable::print(os);
	return os;
}
//--------------------------------------------------
//
// Filename:	PhoneBook.cpp
// Author:		Nikolai Raevsky (nikolai.raevsky@digipen.edu)
// Project:		PRG 8.3.9 CORE ASSIGNMENT: Phone Book
// Course:		WANIC VGP2
//
// Copyright © 2022 DigiPen (USA) Corporation.
//
//--------------------------------------------------

#include "PhoneBook.h"
#include <iostream>
#include <fstream>
#include <string>
#include <deque>
#include <vector>


//Constructors

PhoneEntry::PhoneEntry(std::string name_, std::string last_name_, std::string email_, int region_, int number_) :
	name(name_), last_name(last_name_), email(email_), region(region_), number(number_)
{
}

PhoneBook::PhoneBook(std::string filename_)
{

}

PhoneBook::PhoneBook(const PhoneBook& copy_)
{

}

//Equal operator
PhoneBook& PhoneBook::operator=(const PhoneBook& rhs)
{

}

//Other functions
void PhoneBook::Save(std::string filename_) const
{

}

void PhoneBook::AddEntry(const std::string& name_, const std::string& last_name_, const std::string& email_, int region_, int number_)
{
}

void PhoneBook::SortByName()
{
}

void PhoneBook::RemoveEntriesByName(std::string subString_)
{
}

PhoneBook::~PhoneBook()
{
}

std::ostream& operator<<(std::ostream& os_, const PhoneBook& phonebook_)
{
	// TODO: insert return statement here
}



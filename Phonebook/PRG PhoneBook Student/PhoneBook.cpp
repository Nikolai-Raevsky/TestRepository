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




PhoneEntry::PhoneEntry(std::string name_, std::string last_name_, std::string email_, int region_, int number_) :
	name(name_), last_name(last_name_), email(email_), region(region_), number(number_)
{
}

PhoneBook::PhoneBook(std::string filename_)
{
	//Tokens
	std::string nameToken;
	std::string last_nameToken;
	std::string emailToken;
	int regionToken;
	int numberToken;
	//Open the file with filename_

	//Store text from the file in the entries array

	//Copy phone entry members into local variables. After the loop is over and all these variables have information, store pointers to those in the phone entries array

	//Use ifstream
	std::ifstream inputFile(filename_);

	if (inputFile.is_open())
	{
		while (inputFile >> nameToken)
		{
			inputFile >> last_nameToken;
			inputFile >> emailToken;
			inputFile >> regionToken;
			inputFile >> numberToken;

			PhoneEntry* newEntry = new PhoneEntry(nameToken, last_nameToken, emailToken, regionToken, numberToken);
			entries.push_back(newEntry);
		}

	}

	//Collect phoneentry members 

	//Once all the phone entry information is collected add it to phoneentry vector in phonebook
}

PhoneBook::PhoneBook(const PhoneBook& copy_)
{

}


PhoneBook& PhoneBook::operator=(const PhoneBook& rhs)
{

}


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
	return os_;
}



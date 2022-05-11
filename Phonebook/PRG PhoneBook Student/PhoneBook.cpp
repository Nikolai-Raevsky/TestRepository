//--------------------------------------------------
//
// Filename:	PhoneBook.cpp
// Author:		Nikolai Raevsky (nikolai.raevsky@digipen.edu)
// Project:		PRG 8.3.9 CORE ASSIGNMENT: Phone Book
// Course:		WANIC VGP2
//
// Copyright © 2022 DigiPen (USA) Corporation.
//
// 
// 
// MISCELLANEOUS NOTES TO HELP ME UNDERSTAND THE ASSIGNMENT BETTER:
// Each PhoneEntry is dynamically allocated into the PhoneBook's PhoneEntry vector (entries)
// entries is the only private member in PhoneBook (the only thing whose data we're reading and writing in this file
// Each dynamically allocated entry (which is supposed to be each entry) gets stored into an std::vector
// The vector contains entry pointers basically
// Each vector element needs to be individually allocated and freed (the vector doesn't need this to get rid of the pointers because the STL creators have already implemented constructors and destructors that handle allocation and deletion)
// In the copy constructor, each entry element in the copy_'s constructor needs to be stored in *this.entries. Not the pointers, but like the data you get when you dereference the pointers
//--------------------------------------------------

#include "PhoneBook.h"
#include <iostream>
#include <fstream>
#include <string>
#include <deque>
#include <vector>



//Hello
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
			char tempHyphen;
			inputFile >> tempHyphen;
			inputFile >> numberToken;
			char tempAsterisk;
			inputFile >> tempAsterisk;

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

	//change this later
	return *this;
}


void PhoneBook::Save(std::string filename_) const
{
	std::ofstream outputFile(filename_);
	
}

void PhoneBook::AddEntry(const std::string& name_, const std::string& last_name_, const std::string& email_, int region_, int number_)
{
	PhoneEntry* newEntry = new PhoneEntry(name_, last_name_, email_, region_, number_);
	entries.push_back(newEntry);
}

void PhoneBook::SortByName()
{
}

void PhoneBook::RemoveEntriesByName(std::string subString_)
{
}

PhoneBook::~PhoneBook()
{
	//Functions I'll need for this: delete (entries[i])

	for (auto iter = entries.begin(); iter < entries.end(); ++iter)
	{
		delete (*iter);
	}
}

std::ostream& operator<<(std::ostream& os_, const PhoneBook& phonebook_)
{
	for (auto iter = phonebook_.entries.begin(); iter < phonebook_.entries.end(); ++iter)
	{
		os_ << (*iter)->name << " " << (*iter)->last_name << std::endl;
		os_ << (*iter)->email << std::endl;
		os_ << (*iter)->region << "-" << (*iter)->number << std::endl << "*" << std::endl;
		
		

	}
	// TODO: insert return statement here
	return os_;
}



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
#include <algorithm>


bool PhoneEntryCompare(PhoneEntry* entry1, PhoneEntry* entry2)
{
	return (entry1->name < entry2->name);
}


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
	
	std::ifstream inputFile(filename_);

	if (inputFile.is_open())
	{
		while (inputFile >> nameToken)
		{
			inputFile >> last_nameToken;
			inputFile >> emailToken;
			inputFile >> regionToken;
			char tempHyphen; //Temp to keep hyphen out of PhoneEntry
			inputFile >> tempHyphen;
			inputFile >> numberToken;
			char tempAsterisk;//Temp to keep asterisk out of PhoneEntry
			inputFile >> tempAsterisk;

			PhoneEntry* newEntry = new PhoneEntry(nameToken, last_nameToken, emailToken, regionToken, numberToken);
			entries.push_back(newEntry);
		}

	}

	 

	//Once all the phone entry information is collected add it to phoneentry vector in phonebook
}

PhoneBook::PhoneBook(const PhoneBook& copy_)
{
	//For this one, I'll need iterators I think

	for (auto iter = copy_.entries.begin(); iter < copy_.entries.end(); ++iter)
	{
		//Construct a new entry based on the iter's members
		PhoneEntry* newEntry = new PhoneEntry((*iter)->name, (*iter)->last_name, (*iter)->email, (*iter)->region, (*iter)->number);
		entries.push_back(newEntry);
	}
}


PhoneBook& PhoneBook::operator=(const PhoneBook& rhs)
{
	ClearPhoneBook();
	for (auto iter = rhs.entries.begin(); iter < rhs.entries.end(); ++iter)
	{
		AddEntry((*iter)->name, (*iter)->last_name, (*iter)->email, (*iter)->region, (*iter)->number);
	}
	//change this later
	return *this;
}

//Description: Outputs this PhoneBook to a file
//Params:
//	filename_: the name of the file the user wants to output to
void PhoneBook::Save(std::string filename_) const
{
	std::ofstream outputFile(filename_);
	outputFile << *this;

}
//Description:
//	Adds a new PhoneEntry to the entries vector of PhoneBook
//Params:
//	name_ : This will be the name member of the new PhoneEntry
//	last_name_ : This will be the last_name member of the new PhoneEntry
//	eamil_ : This will be the email member of the new PhoneEntry
//	region_ : This will be the region member of the new PhoneEntry
//	number_ : This will be the number member of the new entry
void PhoneBook::AddEntry(const std::string& name_, const std::string& last_name_, const std::string& email_, int region_, int number_)
{
	PhoneEntry* newEntry = new PhoneEntry(name_, last_name_, email_, region_, number_);
	entries.push_back(newEntry);
}

//Description:
//	sorts the entries based on how early their names are in alphabetical order
void PhoneBook::SortByName()
{
	//I need a comparing function and std::sort for this one
	std::sort(entries.begin(), entries.end(), PhoneEntryCompare);
}
//Description:
//	Removes a PhoneEntry from the entries vector based on whether their name member contains a certain sequence of characters 
// (in most uses it would be whole names but in the driver we can remove entries based on sequences of as few as two characters)
//Params:
//	subString_ : The character sequence that the name must feature to be removed from entries
void PhoneBook::RemoveEntriesByName(std::string subString_)
{
	//This function uses entries->name.substr(pos) and entries->name.find("on"), a for loop
	for (auto iter = entries.begin(); iter < entries.end(); )
	{
		if ((*iter)->name.find(subString_) != std::string::npos)
		{
			delete (*iter);
			*iter = nullptr;
			iter = entries.erase(iter);
		}

		else
		{
			++iter;
		}

	}


}

void PhoneBook::ClearPhoneBook()
{
	for (auto iter = entries.begin(); iter < entries.end(); )
	{
		delete (*iter);
		*iter = nullptr;
		iter = entries.erase(iter);
	}

}
//Description:
//	Deletes the memory of the PhoneEntries that are in the entries vector. 
PhoneBook::~PhoneBook()
{
	//Functions I'll need for this: delete (entries[i])
	ClearPhoneBook();
	
}
//Description:
//	Outputs the PhoneEntries in the entries array (all the members of each PhoneEntry) to whichever output stream us programmers or the user chooses
//Params:
//	os_ : The output stream that will display the Phonebook information
//	phonebook_ : The PhoneBook that contains the entries vector we are displaying from
//Returns:
//	 An output stream object that enables recursive use of this function for complex output statements
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



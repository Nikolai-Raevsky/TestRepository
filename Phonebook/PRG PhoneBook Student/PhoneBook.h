#pragma once
#include <string>
#include <vector>
#include <deque>

struct PhoneEntry
{
    std::string name;
    std::string last_name;
    std::string email;
    int region;
    int number;
    //A non - default PhoneEntry constructor. Initializes the name, last_name, email, region, and number members of PhoneEntry
    PhoneEntry(std::string name_, std::string last_name_,
        std::string email_, int region_, int number_);

};
// Description:
// Determines whether entry1 is alphabetically before or after entry2
//Params:
//	entry1: One of the PhoneEntry pointers the user wants to compare
//	entry2: The other Phoneentry pointer the user wants to compare
//Returns:
//	A bool determining if entry1 is alphabetically before entry2 or not
bool PhoneEntryCompare(PhoneEntry* entry1, PhoneEntry* entry2);
class PhoneBook
{
public:
    //A non-default constructor for PhoneBook. Assigns the filename_'s phone entries into the entries vector
    //Params:
    //  filename_ is the name of the file the user wants to construct a PhoneBook from
    PhoneBook(std::string filename_);

    //Description:
    //  A copy constructor that initializes a PhoneBook with the entries contents of another
    //Params:
    //  copy_ is the PhoneBook the user wants to copy the entries vector from
    PhoneBook(const PhoneBook &copy_);
    //Description:
    //  An operator overload that assigns the contents of one PhoneBook's entries array to another
    PhoneBook & operator= (const PhoneBook & rhs_);
    //Description
    //  Writes the entries content of a PhoneBook's entries vector onto a text file
    //Params:
    //  filename_ The name of the file that the user wants to output to
    void Save(std::string filename_) const;
    //Description:
    //  An insertion operator overload that outputs the entries content of a PhoneBook to an output stream
    friend std::ostream & operator<<(std::ostream & os_, 
                                     const PhoneBook & phonebook_);
    //Description:
    //  Inserts a pointer to a new PhoneEntry at the end of the entries vector
    //Params:
    //  name_ is the PhoneEntry's name
    //  last_name_ is the PhoneEntry's last_name
    //  email_ is the PhoneEntry's email
    //  region_ is the PhoneEntry's region
    //  number_ is the PhoneEntry's number
    void AddEntry(const std::string &name_,
                  const std::string &last_name_,
                  const std::string &email_,
                  int region_, int number_);
    //Description:
    //  Sorts the entries vector of the PhoneBook in the name member's alphabetical order
    void SortByName();
    //Description:
    //  Removes a PhoneEntry from the entries vector based on content in the name member
    //Params:
    //  subString_ is the text that the PhoneEntry's name has that the user wants to remove. This will generally be a name, but in the driver it can be as small as a pair of characters
    void RemoveEntriesByName(std::string subString_);
    
    //A PhoneBook Destructor
    ~PhoneBook();

private:

    std::vector<PhoneEntry *> entries;
    //Description:
    //  Deletes the PhoneEntry pointers in the entries vector and erases the pointers from the vector
    void ClearPhoneBook();
    //std::deque<PhoneEntry *> entries;
};

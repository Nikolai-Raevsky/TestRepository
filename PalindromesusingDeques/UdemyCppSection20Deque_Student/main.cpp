/************************************
Name: Nikolai Raevsky (nikolai.raevsky@digipen.edu)
Instructor: Jeremy Kings (jeremy.kings@digipen.edu)
Assignment: PRG8.2.7 CORE ASSIGNMENT: Palindromes using Deques
Course: WANIC VGP2
Other Notes:
This is using code from udemy.com (especially the main function)
*************************************/
// Section 20
// Challenge 1
// Identifying palindrome strings using a deque
#include <cctype>
#include <deque>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

bool is_palindrome(const std::string& s)
{
    // You must implement this function.
    // Since we are learning the STL - use a deque to solve the problem.
		// First you will need to add each character from the string to the deque!
		std::deque<char> characters;

        for (unsigned i = 0; i < s.size(); i++)
        {
            //This one should copy 


            //Use toupper and isalpha to make sure characters are all capped 
            if (isalpha(s[i]))
            {
                characters.push_back(toupper(s[i]));
            }
            
        }
        unsigned charactersSize = characters.size();
        if (charactersSize == 1)
        {
            return true;
        }
        while (charactersSize >= 1)
        {
            if (charactersSize == 1)
            {
                return true;
            }
            if (characters.front() != characters.back())
            {
                return false;
            }

            else
            {
                characters.pop_front();
                characters.pop_back();
            }
            charactersSize = characters.size();

        }


        //The instructions said to use pop_front, and pop_back, front, back, 
		
		
    return false;
}

int main()
{
    std::vector<std::string> test_strings{ "a", "aa", "aba", "abba", "abbcbba", "ab", "abc", "radar", "bob", "ana",
        "avid diva", "Amore, Roma", "A Toyota's a toyota", "A Santa at NASA", "C++",
        "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!", "This is a palindrome", "palindrome" };
   
    std::cout << std::boolalpha;
    std::cout << std::setw(8) << std::left << "Result" << "String" << std::endl;
    for(const auto& s : test_strings) {
        std::cout << std::setw(8) << std::left << is_palindrome(s)  << s << std::endl;
    }
    std::cout << std::endl;
    return 0;
}

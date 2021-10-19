//-----------------------------------------------------------------------------------------------------------------
//		Filename: main.cpp
//		Author: Nikolai Raevsky (nikolai.raevsky@digipen.edu)
//		Project: PRG 5.2.7 CORE ASSIGNMENT - Console I/O and Iteration in C++
// Course: WANIC VGP2
//
//Copyright © 2021 DigiPen (USA) Corporation.
//
//
//-------------------------------------------------------------------------------------------------------------------


//Includes
#include <iostream>

//Functions for assignment.

//Filled rectangle

//Unfilled rectangle

//Filled triangle

//Unfilled triangle

int main(int argc, char* argv[])
{
	std::cout << argv[0] << "\n"; //This is still a work in progress
	int height;
	int width = 0;
	
	
	std::cout << "Gimme two integers or else! :) ";
	std::cin >> height >> width;
	
	std::cout << "\nNum is " << height << " and nextnum is " << width << "\n";
	for (int h = 0; h < height; h++)
	{
		for (int w = 0; w < width; w++)
		{
			std::cout << "*";
		}
		std::cout << "\n";
	}
	std::cout << atoi (argv[1]) << "\n";


	//Rectangle tests


	//Triangle tests
}
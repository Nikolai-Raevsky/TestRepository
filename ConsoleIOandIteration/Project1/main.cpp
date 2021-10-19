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

int main(void)
{
	int height;
	int width = 0;
	std::cout << "Hello world. \n";
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


	//Rectangle tests


	//Triangle tests
}
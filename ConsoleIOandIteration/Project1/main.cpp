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
void drawFilledRectangle(int Height, int Width)
{

}
//Unfilled rectangle
void drawUnfilledRectangle(int Height, int Width)
{

}
//Filled triangle
void drawFilledTriangle(int Height)
{

}
//Unfilled triangle
void drawUnfilledTriangle(int Height)
{

}
int main(void)
{
	int drawChoice;
	//Make sure to loop this since the expectation is that the question will keep on being asked until the user exits or picks a different number
	std::cout << "What would you like to draw? \n"
		<< "1 - A Filled Rectangle \n"
		<< "2 - A Non Filled Rectangle \n"
		<< "3 - A Filled Triangle \n"
		<< "4 - A Non Filled Triangle"
		<< "Any Other Number - Exit \n";
	std::cin >> drawChoice;

	switch (drawChoice) 
	{
	case 1:
		//Filled rectangle
		std::cout << "This confirms the case can be read.\n";
		std::cout << ""
		break;
	case 2:
		//Un filled rectangle
		std::cout << "This confirms the case can be read.\n";
		break;
	case 3:
		//Filled triangle
		std::cout << "This confirms the case can be read.\n";
		break;
	case 4:
		//Un filled triangle
		std::cout << "This confirms the case can be read.\n";
		break;

	default:
		std::cout << "Thank you for using our application!\n";
		return 0;
	}
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
	


	//Rectangle tests


	//Triangle tests
}
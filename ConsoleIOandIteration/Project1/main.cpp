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
	std::cout << "What would you like to draw? \n"
		<< "1 - A Filled Rectangle \n"
		<< "2 - A Non Filled Rectangle \n"
		<< "3 - A Filled Triangle \n"
		<< "4 - A Non Filled Triangle"
		<< "Any Other Number - Exit \n";
	
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
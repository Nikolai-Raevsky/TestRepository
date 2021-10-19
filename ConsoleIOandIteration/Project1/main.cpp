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
	for (int h = 0; h < Height; h++)
	{
		for (int w = 0; w < Width; w++)
		{
			std::cout << "*";
		}
		std::cout << "\n";
	}
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
	int height;
	int width;
	bool loopCheck = true;
	int drawChoice;
	while (loopCheck)
	{
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
			std::cout << "Enter this rectangle's height and width values: ";
			std::cin >> height >> width;
			drawFilledRectangle(height, width);
			
			break;
		case 2:
			//Un filled rectangle
			std::cout << "Enter this rectangle's height and width values: ";
			std::cin >> height >> width;
			break;
		case 3:
			//Filled triangle
			std::cout << "Enter the triangle's height value: ";
			break;
		case 4:
			//Un filled triangle
			std::cout << "Enter the triangle's height value: ";
			break;

		default:
			std::cout << "Thank you for using our application!\n";
			return 0;
		}
	}
	
	
	
	
	
	
	
	
	


	//Rectangle tests


	//Triangle tests
}
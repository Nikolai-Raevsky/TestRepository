//-----------------------------------------------------------------------------------------------------------------
//		Filename: main.cpp
//		Author: Nikolai Raevsky (nikolai.raevsky@digipen.edu)
//		Project: PRG 5.2.7 CORE ASSIGNMENT - Console I/O and Iteration in C++
// Course: WANIC VGP2
//
//Copyright © 2021 DigiPen (USA) Corporation.
//
//

//IMPORTANT COMMENTS:
//Tomorrow work on getting the top vertex of the unfilled triangle centered with the base, filling out the bottom row, and tests. In particular, (if I get to testing) make sure that the functions send an error message if the user doesn't send any height or width for the shapes.
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
	

	if (Width == 0)
	{
		std::cout << "The rectangle width has to be at least 1\n";
		return;
	}
	for (int h = 0; h < Height; h++)
	{
		for (int w = 0; w < Width; w++)
		{
			//Fill top and bottom rows with asterisks
			if (h == 0 || h == Height - 1)
				std::cout << "*";
			//Mid row asterisk generation
			else
			{
				if (w == 0 || w == Width - 1)
				{
					std::cout << "*";
				}
					
				else
				{
					std::cout << " ";
				}
					
			}
		}
		
		std::cout << "\n";
	}
}
//Filled triangle
void drawFilledTriangle(int Height)
{
	if (Height == 0)
	{
		std::cout << "The triangle height has to at least be 1.\n";
		return;
	}
	int spaces = Height - 1;
	int asterisks = 1;
	for (int h = 0; h < Height; h++)
	{
		
		for (int space = 0; space < spaces; space++)
		{
			std::cout << " ";
		}
		
		for (int asterisk = 0; asterisk < asterisks; asterisk++)
		{
			std::cout << "*";
		}
		spaces -= 1;
		asterisks += 2;
		std::cout << "\n";
	}
}
//Unfilled triangle
void drawUnfilledTriangle(int Height)
{
	int extspaces = Height - 1;
	int intspaces = 0;
	int asterisks = 1;
	for (int h = 0; h < Height; h++)
	{

		for (int space = 0; space < extspaces; space++)
		{
			std::cout << " ";
		}

		std::cout << "*";

		for (int space = 0; space < intspaces; space++)
		{
			std::cout << " ";
		}
		std::cout << "*";
		extspaces -= 1;
		intspaces += 2;
		asterisks += 2;
		std::cout << "\n";
	}
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
			if (height == 0)
			{
				std::cout << "The rectangle height has to be at least 1 \n";
				break;
			}
			drawFilledRectangle(height, width);
			
			break;
		case 2:
			//Un filled rectangle
			std::cout << "Enter this rectangle's height and width values: ";
			std::cin >> height >> width;
			drawUnfilledRectangle(height, width);
			break;
		case 3:
			//Filled triangle
			std::cout << "Enter the triangle's height value: ";
			std::cin >> height;
			drawFilledTriangle(height);
			break;
		case 4:
			//Un filled triangle
			std::cout << "Enter the triangle's height value: ";
			std::cin >> height;
			drawUnfilledTriangle(height);
			break;

		default:
			std::cout << "Thank you for using our application!\n";
			return 0;
		}
	}
	
	
	
	
	
	
	
	
	


	//Rectangle tests


	//Triangle tests
}
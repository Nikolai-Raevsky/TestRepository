//-----------------------------------------------------------------------------------------------------------------
//		Filename: main.cpp
//		Author: Nikolai Raevsky (nikolai.raevsky@digipen.edu)
//		Project: PRG 5.2.7 CORE ASSIGNMENT - Console I/O and Iteration in C++
// Course: WANIC VGP2
//
//Copyright © 2021 DigiPen (USA) Corporation.
//
//
//
//
//
//-------------------------------------------------------------------------------------------------------------------


//Includes
#include <iostream>
#define RECTANGLEHEIGHTERROR "The rectangle height has to be at least 1\n\n"
#define RECTANGLEWIDTHERROR "The rectangle width has to be at least 1\n\n"
#define TRIANGLEHEIGHTERROR "The triangle's height has to be at least 1\n\n"



void drawFilledRectangle(int Height, int Width)
{
	if (Height <= 0)
	{
		std::cout << RECTANGLEHEIGHTERROR;
		return;
	}

	if (Width <= 0)
	{
		std::cout << RECTANGLEWIDTHERROR;
		return;
	}
	for (int h = 0; h < Height; h++)
	{
		for (int w = 0; w < Width; w++)
		{
			std::cout << "*";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}

void drawUnfilledRectangle(int Height, int Width)
{
	if (Height <= 0)
	{
		std::cout << RECTANGLEHEIGHTERROR;
		return;
	}

	if (Width <= 0)
	{
		std::cout << RECTANGLEWIDTHERROR;
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
	std::cout << "\n";
}

void drawFilledTriangle(int Height)
{
	if (Height <= 0)
	{
		std::cout << TRIANGLEHEIGHTERROR;
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
	std::cout << "\n";
}
//Unfilled triangle
void drawUnfilledTriangle(int Height)
{
	if (Height <= 0)
	{
		std::cout << TRIANGLEHEIGHTERROR;
		return;
	}
	int externalspaces = Height - 1;
	int internalspaces = 0;
	int asterisks = 1;
	for (int h = 0; h < Height - 1; h++)
	{

		for (int space = 0; space < externalspaces; space++)
		{
			std::cout << " ";
		}

		std::cout << "*";

		for (int space = 0; space < internalspaces; space++)
		{
			std::cout << " ";
		}
		if (h != 0)
		{
			std::cout << "*";
		}
		
		externalspaces -= 1;
		if (h == 0)
		{
			internalspaces += 1;
		}

		else
		{
			internalspaces += 2;
		}
		
		asterisks += 2;
		std::cout << "\n";
	}

	//Bottom-most row
	for (int asterisk = 0; asterisk < asterisks; asterisk++)
	{
		std::cout << "*";
	}
	std::cout << "\n\n";
}
int main(void)
{
	int height;
	int width;
	bool loopCheck = true;
	int drawChoice;
	while (loopCheck)
	{
		
		std::cout << "What would you like to draw?\n"
			<< "1 - A Filled Rectangle\n"
			<< "2 - A Non Filled Rectangle\n"
			<< "3 - A Filled Triangle\n"
			<< "4 - A Non Filled Triangle\n"
			<< "Any Other Number - Exit\n\n";
		std::cin >> drawChoice;

		std::cout << "Your choice is: " << drawChoice << "\n";
		switch (drawChoice)
		{
		case 1:
			
			std::cout << "Enter the rectangle's width and height values: \n";
			std::cin >> width >> height;
			
			
			
			drawFilledRectangle(height, width);
			
			break;
		case 2:
			
			std::cout << "Enter the rectangle's width and height values:\n";
			std::cin >> width >> height;
			drawUnfilledRectangle(height, width);
			break;
		case 3:
			std::cout << "Enter the triangle's height value: \n";
			std::cin >> height;
			drawFilledTriangle(height);
			break;
		case 4:
			std::cout << "Enter the triangle's height value: \n";
			std::cin >> height;
			drawUnfilledTriangle(height);
			break;

		default:
			std::cout << "Thank you for using our application!";
			return 0;
		}
	}
	
	
	
	
	
	
	
	
	


	//Rectangle tests


	//Triangle tests
}
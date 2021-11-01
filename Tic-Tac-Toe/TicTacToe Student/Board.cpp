/**********************************************
*	
*	File Name: Board.cpp
*	Name: Nikolai Raevsky (nikolai.raevsky@digipen.edu)
*	Project: PRG 5.5.6 CORE Assignment - Tic-Tac-Toe
*	Course: WANIC VGP2
*	Copyright © DigiPen (USA) Corporation. 
* 
* Note for Thursday: Do diffing tests with current boards before moving onto the last two functions
* ********************************************/

//Includes
#include <iostream>
#include "Board.h"
namespace CS170
{


	struct Board
	{
		TileState data[3][3];
	};

	Board* BoardCreate()
	{
		Board* board = new Board;
		for (int row = 0; row < boardLength; row++)
		{
			for (int cell = 0; cell < boardLength; cell++)
			{
				board->data[row][cell] = tsEMPTY;
			}
		}
		return board;
		
		
	}

	void BoardFree(Board*& theBoard)
	{
		//MAKE SURE THAT THE POINTER ISN'T POINTING TO A DEALLOCATED MEMORY SPOT
		delete theBoard;
		theBoard = nullptr;
	}

	void BoardDisplay(const Board& board)
	{
		//All the printing will be handled through here
		//Double check tilestate documentation to make sure you understand how to access the board's tilestates. If I remember, I think that the structure contains a tilestate array.
		for (int row = 0; row < boardLength; row++)
		{
			for (int hash = 0; hash < 13; hash++)
			{
				std::cout << "-";
			}
			std::cout << std::endl;
			for (int cell = 0; cell < boardLength; cell++)
			{
				std::cout << "|";
				std::cout << " ";
				if (board.data[row][cell] == tsPLAYER_ONE)
				{
					std::cout << "O";
				}

				else if (board.data[row][cell] == tsPLAYER_TWO)
				{
					std::cout << "X";
				}

				else
					std::cout << " ";
				//std::cout << "|";
				std::cout << " ";

			}
			std::cout << "|" << std::endl;
		}
		for (int hash = 0; hash < 13; hash++)
		{
			std::cout << "-";
		}
		std::cout << std::endl;

		
	}

	PlaceResult BoardPlaceToken(Board& board, unsigned row, unsigned column, TileState value) //Ask teach about this thing
	{
		//If space is not on board
		if (row >= boardLength || column >= boardLength || row < 0 || column < 0)
		{
			return prREJECTED_OUTOFBOUNDS;
		}
		//If space is occupied
		if (board.data[row][column] != tsEMPTY)
		{
			return prREJECTED_OCCUPIED;
		}

		else
		{
			board.data[row][column] = value;
			return prACCEPTED;
		}
	}

	//void BoardReset(Board& board)
	//{

	//}

	//BoardState BoardGetState(const Board& board)
	//{

	//}
}
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
					std::cout << "X";
				}

				else if (board.data[row][cell] == tsPLAYER_TWO)
				{
					std::cout << "O";
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

	void BoardReset(Board& board)
	{
		//Loop through the board and reset tilestate to tsEMPTY
		for (int row = 0; row < boardLength; row++)
		{
			for (int cell = 0; cell < boardLength; cell++)
			{
				board.data[row][cell] = tsEMPTY;
			}
		}
	}

	BoardState BoardGetState(const Board& board)
	{
		
		
		//Tie is no spaces are empty and nobody won
		//Player one win states
		if
		(	 //Vertical columns
			(board.data[0][0] == tsPLAYER_ONE && board.data[0][1] == tsPLAYER_ONE && board.data[0][2] == tsPLAYER_ONE) ||
			(board.data[1][0] == tsPLAYER_ONE && board.data[1][1] == tsPLAYER_ONE && board.data[1][2] == tsPLAYER_ONE) ||
			(board.data[2][0] == tsPLAYER_ONE && board.data[2][1] == tsPLAYER_ONE && board.data[2][2] == tsPLAYER_ONE) ||
			//Horizontal rows
			(board.data[0][0] == tsPLAYER_ONE && board.data[1][0] == tsPLAYER_ONE && board.data[2][0] == tsPLAYER_ONE) ||
			(board.data[0][1] == tsPLAYER_ONE && board.data[1][1] == tsPLAYER_ONE && board.data[2][1] == tsPLAYER_ONE) ||
			(board.data[0][2] == tsPLAYER_ONE && board.data[1][2] == tsPLAYER_ONE && board.data[2][2] == tsPLAYER_ONE) ||
			//Diagonals
			(board.data[0][0] == tsPLAYER_ONE && board.data[1][1] == tsPLAYER_ONE && board.data[2][2] == tsPLAYER_ONE) ||
			(board.data[2][0] == tsPLAYER_ONE && board.data[1][1] == tsPLAYER_ONE && board.data[0][2] == tsPLAYER_ONE)	)
				{
					return bsWIN_ONE;
				}
		else if
			(	 //Vertical columns
				(board.data[0][0] == tsPLAYER_TWO && board.data[0][1] == tsPLAYER_TWO && board.data[0][2] == tsPLAYER_TWO) ||
				(board.data[1][0] == tsPLAYER_TWO && board.data[1][1] == tsPLAYER_TWO && board.data[1][2] == tsPLAYER_TWO) ||
				(board.data[2][0] == tsPLAYER_TWO && board.data[2][1] == tsPLAYER_TWO && board.data[2][2] == tsPLAYER_TWO) ||
				//Horizontal rows
				(board.data[0][0] == tsPLAYER_TWO && board.data[1][0] == tsPLAYER_TWO && board.data[2][0] == tsPLAYER_TWO) ||
				(board.data[0][1] == tsPLAYER_TWO && board.data[1][1] == tsPLAYER_TWO && board.data[2][1] == tsPLAYER_TWO) ||
				(board.data[0][2] == tsPLAYER_TWO && board.data[1][2] == tsPLAYER_TWO && board.data[2][2] == tsPLAYER_TWO) ||
				//Diagonals
				(board.data[0][0] == tsPLAYER_TWO && board.data[1][1] == tsPLAYER_TWO && board.data[2][2] == tsPLAYER_TWO) ||
				(board.data[2][0] == tsPLAYER_TWO && board.data[1][1] == tsPLAYER_TWO && board.data[0][2] == tsPLAYER_TWO))
				{
			return bsWIN_TWO;
				}
		else
		{
			return bsTIE;
		}

		//Still going if some spaces are empty
		for (int row = 0; row < boardLength; row++)
		{
			for (int cell = 0; cell < boardLength; cell++)
			{
				if (board.data[row][cell] == tsEMPTY)
				{
					return bsOPEN;
				}
			}
		}

			
	}
}
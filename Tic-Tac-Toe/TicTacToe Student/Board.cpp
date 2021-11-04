/**********************************************
*	
*	File Name: Board.cpp
*	Name: Nikolai Raevsky (nikolai.raevsky@digipen.edu)
*	Project: PRG 5.5.6 CORE Assignment - Tic-Tac-Toe
*	Course: WANIC VGP2
*	Copyright © DigiPen (USA) Corporation. 
* 
* 
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

	// Allocate memory for a tic-tac-toe board.
	// Returns:
	//   A pointer to the created board struct.
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
	// Free memory for the tic-tac-toe board.
	// Params:
	//   theBoard = A reference to the pointer to the board.
	void BoardFree(Board*& theBoard)
	{
		//MAKE SURE THAT THE POINTER ISN'T POINTING TO A DEALLOCATED MEMORY SPOT
		delete theBoard;
		theBoard = nullptr;
	}
	// Display the contents of the board using the standard output stream.
	// Params:
	//   theBoard = A reference to the game board.
	void BoardDisplay(const Board& board)
	{
		
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
	// Place a token on the board at a specific position.
	// Params:
	//   theBoard = A reference to the game board.
	//   row = The row of the board on which to place the token.
	//   column = The column of the board on which to place the token.
	//   value = The value to place in the specified tile.
	// Returns:
	//   Whether the token was able to be placed.
	PlaceResult BoardPlaceToken(Board& board, unsigned row, unsigned column, TileState value) //Ask teach about this thing
	{
		
		if (row >= boardLength || column >= boardLength || row < 0 || column < 0)
		{
			return prREJECTED_OUTOFBOUNDS;
		}
		
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
	// Reset the board to an empty state.
	// Params:
	//   theBoard = A reference to the game board.
	void BoardReset(Board& board)
	{
		
		for (int row = 0; row < boardLength; row++)
		{
			for (int cell = 0; cell < boardLength; cell++)
			{
				board.data[row][cell] = tsEMPTY;
			}
		}
	}
	// Get the current state of the board. (Is the game over?)
	// Params:
	//   theBoard = A reference to the game board.
	// Returns:
	//   The current state of the game - win, tie, or open (still going).
	BoardState BoardGetState(const Board& board)
	{
		
		
		
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
				(board.data[2][0] == tsPLAYER_TWO && board.data[1][1] == tsPLAYER_TWO && board.data[0][2] == tsPLAYER_TWO)	)
				{
			return bsWIN_TWO;
				}
		

		//bsOpen
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

		return bsTIE;

			
	}
}
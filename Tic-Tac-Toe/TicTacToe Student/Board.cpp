/**********************************************
*	
*	File Name: Board.cpp
*	Name: Nikolai Raevsky (nikolai.raevsky@digipen.edu)
*	Project: PRG 5.5.6 CORE Assignment - Tic-Tac-Toe
*	Course: WANIC VGP2
*	Copyright © DigiPen (USA) Corporation. 
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
		return board;
	}

	void BoardFree(Board*& theBoard)
	{
		//MAKE SURE THAT THE POINTER ISN'T POINTING TO A DEALLOCATED MEMORY SPOT
		delete theBoard;
	}

	void BoardDisplay(const Board& board)
	{
		//All the printing will be handled through here
		//Read about dynamic memory allocation guidelines to make sure you don't have any pointers to deallocated memory or memory leaks
		
		

		
	}

	PlaceResult BoardPlaceToken(Board& board, unsigned row, unsigned column, TileState value)
	{
		
	}

	void BoardReset(Board& board)
	{

	}

	BoardState BoardGetState(const Board& board)
	{

	}
}
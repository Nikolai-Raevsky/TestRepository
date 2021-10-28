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

	}

	void BoardDisplay(const Board& board)
	{

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
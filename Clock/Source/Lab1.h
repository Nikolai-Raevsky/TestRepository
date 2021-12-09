//------------------------------------------------------------------------------
//
// File Name:	Lab1.h
// Author(s):	Jeremy Kings (j.kings) modified by Nikolai Raevsky (n.raevsky)
// Project:		Lab1
// Course:		MAT140
//
// Copyright © 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

#pragma once

//------------------------------------------------------------------------------
// Includes:
//------------------------------------------------------------------------------

#include "BetaObject.h" // BetaObject
#include "Vector2D.h"   // Vector2D

//------------------------------------------------------------------------------
// Public Structures:
//------------------------------------------------------------------------------

class Lab1 : public Beta::BetaObject
{
public:
	//------------------------------------------------------------------------------
	// Public Functions:
	//------------------------------------------------------------------------------

	// Constructor
	Lab1();

	// Initialize the Lab1 level.
	void Initialize();

	// Update the Lab1 level.
	// Params:
	//	 dt = Change in time (in seconds) since the last game loop.
	void Update(float dt);

	// Shut down the Lab1 level.
	void Shutdown();

private:
	//------------------------------------------------------------------------------
	// Private Consts:
	//------------------------------------------------------------------------------

	const float pi; //This is used to make the rotational Velocity and isn't for me necessarily
	const float lineLength;
	const float rotationalVelocity;
	const Beta::Vector2D origin;

	//------------------------------------------------------------------------------
	// Private Variables:
	//------------------------------------------------------------------------------

	// Angles
	float angle1;
	float angle2;
	float angle3;

	// Points
	//Beta::Vector2D p, q, r;
	//I'll comment these variables above out since they were given to me
	// TO DO: Add other variables here as needed.
	//These three are the points I'm using. I understand that we got p, q, and r, but those names mean nothing to me
	Beta::Vector2D secondsHand;
	Beta::Vector2D minutesHand;
	Beta::Vector2D hoursHand;
};

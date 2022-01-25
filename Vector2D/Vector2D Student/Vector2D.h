/*************************************************************
*	Filename: Vector2D.h
	Name: Nikolai Raevsky (nikolai.raevsky@digipen.edu)
	Instructor: Jeremy Kings (j.kings@digipen.edu
	Assignment: PRG 6.3.6 CORE ASSIGNMENT: Vector2D Class
	***********************************************************/
////////////////////////////////////////////////////////////////////////////////
#ifndef VECTOR2D_H
#define VECTOR2D_H
////////////////////////////////////////////////////////////////////////////////

#include <iostream> // istream, ostream

namespace CS170
{
	class Vector2D
	{
	public:
		// Constructors (2)
		//A constructor that initializes a Vector2D's x and y variables with x_ and y_ respectively
		
		Vector2D(float x_, float y_);

		//A constructor that initializes a Vector2D's x and y variables with 0
		Vector2D(void);
		// Accessors (2)
		
		//Accesses x variable for use in other functions
		float X(void);
		//Accesses y variable for use in other functions
		float Y(void);


		// Mutators (2)

		//This one sets the current Vector2D's x value to x_
		void X(float x_);

		//This one sets the current Vector2D's y value to y_
		void Y(float y_);
		
		
		// Other functions (7)
		
		//Calculates the magnitude of the vector with floats x and y
			//Returns a float that is the product of the Pythagorean theorem with x and y
		float Magnitude();
		//Squares the magnitude of the vector
			//returns: A float that's the product of the current vector's magnitude multiplied by itself
		float MagnitudeSquared();

		//Makes a normalized vector that goes in the current direction of the current one
			//Returns: A normalized Vector2D
		Vector2D Normalized();

		//Calculates the distance between the coordinates of two Vector2D with the Distance formula
			//Params: A vector that we'll be retrieving one of the coordinates from. The other coordinates come from the current Vector2D's coordinates
			//Returns: A float that represents the distance between the two points of the vectors
		float Distance(Vector2D vector);
		//Calculates the squared distance between the coordinates of two Vector2D with the Distance formula but without the step where you square root it
			//Params: A vector that we'll be retrieving one of the coordinates from. The other coordinates come from the current Vector2D's coordinates.
			//Returns: A float that represents the squared distance between the two points of the vectors
		float DistanceSquared(Vector2D vector);

		Vector2D Midpoint(Vector2D vector);
		//DotProduct

		// Overloaded operators (9 member functions)
		
		// =

		//Vector + vector Addition
		//Vector - vector subtraction
		//Vector * int multiplication
		//Vector / int division
		//+=
		//-=
		//*=
		// /=
		
	private:
		float x; // The x-coordinate of a Vector2D
		float y; // The y-coordinate of a Vector2D
	};
  
	// Overloaded operators (2 non-member, non-friend functions)
	//<<

	std::ostream& operator<<(std::ostream& os, Vector2D rhs);
	//
	//

} // namespace CS170

#endif
////////////////////////////////////////////////////////////////////////////////

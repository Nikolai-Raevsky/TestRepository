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
		
		//
		float X(void);
		float Y(void);


		// Mutators (2)
		void X(float x_);
		void Y(float y_);
		//Vector2D X();
		//Vector2D Y();
		
		// Other functions (7)
		
		//Calculates the magnitude of the vector with floats x and y
		float Magnitude();
		//Squares the magnitude of the vector
		float MagnitudeSquared();

		//Returns a normalized vector going in the same direction as the original one (a unit vector of the current one).
		Vector2D Normalized();
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

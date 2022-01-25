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
		Vector2D(float x, float y);
		Vector2D(void);
		// Accessors (2)
		
		float X(void);
		float Y(void);


		// Mutators (2)
		void X(float x_);
		void Y(float y_);
		//Vector2D X();
		//Vector2D Y();
		
		// Other functions (7)
		
		//Magnitude
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

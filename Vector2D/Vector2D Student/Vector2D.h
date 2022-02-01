/*************************************************************
*	Filename: Vector2D.h
	Name: Nikolai Raevsky (nikolai.raevsky@digipen.edu)
	Instructor: Jeremy Kings (j.kings@digipen.edu
	Assignment: PRG 6.3.6 CORE ASSIGNMENT: Vector2D Class
	Copyright © 2022DigiPen (USA) Corp. 

	NOTE: When I say say "current vector" or "original vector" I mean the vector that the member function is being called from (as opposed to any vectors passed in as paramaters to the member functions).
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
		float X(void) const;
		//Accesses y variable for use in other functions
		float Y(void) const;


		// Mutators (2)

		//This one sets the current Vector2D's x value to x_
		void X(float x_);

		//This one sets the current Vector2D's y value to y_
		void Y(float y_);
		
		
		// Other functions (7)
		
		//Calculates the magnitude of the vector with floats x and y
			//Returns a float that is the product of the Pythagorean theorem with x and y
		float Magnitude() const;
		//Squares the magnitude of the vector
			//returns: A float that's the product of the current vector's magnitude multiplied by that same magnitude
		float MagnitudeSquared() const;

		//Makes a normalized vector that goes in the direction of the current one
			//Returns: A normalized Vector2D
		Vector2D Normalized() const;

		//Calculates the distance between the coordinates of two Vector2D with the Distance formula
			//Params: A vector that we'll be retrieving one of the coordinates from. The other coordinates come from the current Vector2D's coordinates
			//Returns: A float that represents the distance between the two points of the vectors (using the distance formula)
		float Distance(const Vector2D& vector) const;
		//Calculates the squared distance between the coordinates of two Vector2D with the Distance formula but without the step where you square root it
			//Params: A vector that we'll be retrieving one of the coordinates from. The other coordinates come from the current Vector2D's coordinates.
			//Returns: A float that represents the squared distance between the two points of the vectors
		float DistanceSquared(const Vector2D& vector) const;
		//Calculates the vector who points to the midpoint of the original Vector2D and the vector paramater
		//Params: The second vector we'll be retrieving coordinates from for this operation
		//Returns: A float that represents the distance of the vector multiplied by itself
		Vector2D Midpoint(const Vector2D& vector) const;

		//Calcualtes the DotProduct of two vectors (the original vector and the vector passed in as a paramater
		//Params: Takes the second vector we'll be receiving coordinates from to do the DotProduct operation
		//Returns: A float that represents the dot product of the original Vector2D and the passed in vector Vector2D, which is the sum of the dot product operation (product of all xs + product of all ys).
		float DotProduct(const Vector2D& vector) const;

		// Overloaded operators (9 member functions)
		//Add two vectors to get vector sum
		Vector2D operator+(const Vector2D& rhs) const;
		//Subtract two vectors to get a vector difference
		Vector2D operator-(const Vector2D& rhs) const;
		//Multiply a vector by a scalar to get a scaled up vector
		Vector2D operator*(const float& rhs) const;
		
		//Divide a vector by a scalar to get a scaled down vector
		Vector2D operator/(const float& rhs) const;
		//Increment operator that adds vector rhs to the original vector
		Vector2D& operator+=(const Vector2D& rhs);
		//Decrement operator that subtracts vector rhs from the original vector
		Vector2D& operator-=(const Vector2D& rhs);
		//Multiplier operator that scales up the vector by rhs
		Vector2D& operator*=(const float& rhs);
		//Divider operator that scales down the vector by the rhs
		Vector2D& operator/=(const float& rhs);
		//This operator overload for - negates the vector. This one is unary
		Vector2D operator-() const;
		

		
		
	private:
		float x; // The x-coordinate of a Vector2D
		float y; // The y-coordinate of a Vector2D
	};
  
	// Overloaded operators (2 non-member, non-friend functions)
	
	//This operator overload gives the << operator the ability to output the passed in vector to the console's output stream
	std::ostream& operator<<(std::ostream& os, Vector2D rhs);
	//This is the operator overload for a float scalar being multiplied by a vector. Returns the scaled up vector, much like the *operator overload member function but for if the float is on the left instead of the right
	Vector2D operator*(float lhs, Vector2D& rhs);
	
	
	
	//
	//

} // namespace CS170

#endif
////////////////////////////////////////////////////////////////////////////////

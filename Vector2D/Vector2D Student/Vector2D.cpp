/*************************************************************
*	Filename: Vector2D.cpp
	Name: Nikolai Raevsky (nikolai.raevsky@digipen.edu)
	Instructor: Jeremy Kings (j.kings@digipen.edu
	Assignment: PRG 6.3.6 CORE ASSIGNMENT: Vector2D Class
	***********************************************************/
#include "Vector2D.h"  // Vector2D members
#include <cmath>    // sqrt, atan, sin, cos

namespace CS170
{

///////////////////////////////////////////////////////////////////////////////
// 22 public member functions (2 constructors, 2 accessors, 2 mutators, 7 others, 9 operators) 

// Constructors (2)
Vector2D::Vector2D(float x_, float y_)
  : x(x_), y(y_)
{
}

Vector2D::Vector2D(void)
: x(0), y(0)
{
}

// Accessors (2)
float Vector2D::X(void)
{
	return x;
}
 float Vector2D::Y(void)
{
	return y;
}

// Mutators (2)
void Vector2D::X(float x_)
	
{
	x = x_;
}
void Vector2D::Y(float y_)
	
{
	y = y_;
}

// Other functions (7)
float Vector2D::Magnitude(void)
{
	return sqrt(x*x+y*y);
}
float Vector2D::MagnitudeSquared(void)
{
	return Magnitude() * Magnitude();
}

Vector2D Vector2D::Normalized(void)
{
	Vector2D vector(x, y);
	vector.x = x / Magnitude();
	vector.y = y / Magnitude();
	return vector;
}
// Operators (9)



//Vector + vector Addition
//Vector - vector subtraction
//Vector * int multiplication
//Vector / int division
//+=
//-=
//*=
// /=


// 2 non-member, non-friend functions (operators)
std::ostream& operator<<(std::ostream& os, Vector2D rhs)
{
	os << "(" << rhs.X() << ", " << rhs.Y() << ")" << std::endl;
	return os;
}

} // namespace CS170




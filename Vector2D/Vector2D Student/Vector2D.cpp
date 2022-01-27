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

 float Vector2D::Distance(const Vector2D vector)
{
	return sqrt((vector.x - x) * (vector.x - x) + (vector.y -y) * (vector.y-y));
}

float Vector2D::DistanceSquared(const Vector2D vector)
{
	return (vector.x - x) * (vector.x - x) + (vector.y - y) * (vector.y - y);
}
Vector2D Vector2D::Midpoint(const Vector2D vector)
{
	return Vector2D((vector.x + x) / 2, (vector.y + y) / 2);
}

float Vector2D::DotProduct(const Vector2D vector)
{
	
	return (x * vector.x + y * vector.y);
}
// Operators (9)
Vector2D Vector2D::operator+(const Vector2D& lhs)
{
	return Vector2D(lhs.x + x, lhs.y + y);
}

Vector2D Vector2D::operator-(const Vector2D& rhs)
{
	return Vector2D(x-rhs.x, y-rhs.y);
}

Vector2D Vector2D::operator*(const float& rhs)
{
	return Vector2D(x * rhs, y * rhs);
}


Vector2D Vector2D::operator/(const float& rhs)
{
	return Vector2D(x / rhs, y / rhs);
}

Vector2D& Vector2D::operator+=(const Vector2D& rhs)
{
	x += rhs.x;
	y += rhs.y;
	return *this;
}

Vector2D& Vector2D::operator-=(const Vector2D& rhs)
{
	x -= rhs.x;
	y -= rhs.y;
	return *this;
}

Vector2D& Vector2D::operator*=(const float& rhs)
{
	x *= rhs;
	y *= rhs;
	return *this;
}

Vector2D& Vector2D::operator/=(const float& rhs)
{
	x /= rhs;
	y /= rhs;
	return *this;
}

Vector2D& Vector2D::operator=(const Vector2D& rhs)
{
	x = rhs.x;
	y = rhs.y;
	return *this;
}



// 2 non-member, non-friend functions (operators)
std::ostream& operator<<(std::ostream& os, Vector2D rhs)
{
	os << "(" << rhs.X() << ", " << rhs.Y() << ")" << std::endl;
	return os;
}

Vector2D operator*(float lhs, Vector2D& rhs)
{
	
	return rhs * lhs;
	
}
} // namespace CS170




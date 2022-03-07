#pragma once
/********************************************
	Filename: Circle.h
	Author: Nikolai Raevsky (nikolai.raevsky@digipen.edu)
	Assignment: PRG 7.2.11 CORE ASSIGNMENT: Inheritance with Shapes
	Course: WANIC VGP2
********************************************/
#include "Point.h"
#include "Shape.h"

class Circle : public Shape
{
public:
	//A constructor that initializes Circle with a radius set to radius_. The center should generally be initialized in the Shape constructor
	Circle(Point center_, unsigned int radius_);

	//Description: Displays the center and radius of the circle to the console
	void Draw() const;
private:
	unsigned int radius;
};
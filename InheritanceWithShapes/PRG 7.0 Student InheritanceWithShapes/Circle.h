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
	//A constructor that initializes Circle with a radius set to radius_. I think that center gets initialized in the Shape constructor but I might have to check with Jeremy about that
	Circle(Point center_, unsigned int radius_);

	//Description: Displays the center and radius of the circle to the console
	void Draw() const;
private:
	unsigned int radius;
};
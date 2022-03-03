/********************************************
	Filename: Circle.cpp
	Author: Nikolai Raevsky (nikolai.raevsky@digipen.edu)
	Assignment: PRG 7.2.11 CORE ASSIGNMENT: Inheritance with Shapes
	Course: WANIC VGP2
********************************************/
#include <iostream>
#include "Circle.h"
#include "Shape.h"
Circle::Circle(Point center_, unsigned int radius_) : Shape(center_), radius(radius_) {}

void Circle::Draw() const
{
	std::cout << "Drawing a circle at x = " << center.x << " y = " << center.y << " and radius " << radius << std::endl << std::endl;
}
/********************************************
	Filename: Shape.cpp
	Author: Nikolai Raevsky (nikolai.raevsky@digipen.edu)
	Assignment: PRG 7.2.11 CORE ASSIGNMENT: Inheritance with Shapes
	Course: WANIC VGP2
********************************************/
#include <ostream>
#include "Shape.h"
Shape::Shape(Point center_) : center(center_)
{

}

Point Shape::GetCenter()
{
	return center;
}

void Shape::SetCenter(float x_, float y_) 
{
	center = Point(x_, y_);
}
Shape::~Shape()
{
	
}
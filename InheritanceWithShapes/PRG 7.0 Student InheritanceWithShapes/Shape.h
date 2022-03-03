#pragma once
/********************************************
	Filename: Shape.h
	Author: Nikolai Raevsky (nikolai.raevsky@digipen.edu)
	Assignment: PRG 7.2.11 CORE ASSIGNMENT: Inheritance with Shapes
	Course: WANIC VGP2
********************************************/



/************
IMPORTANT NOTES FOR VIRTUAL FUNCTIONS AND ABSTRACT CLASSES I'M GONNA FORGET:
To make a class abstract, set the function header to 0 (this would occur in the .h files
Virtual functions for derived objects can only be called if the method is called from a pointer*/

#include "Point.h"
class Shape
{
public:
	//Constructs a shape with a center set to center_
	Shape(Point center_);
	//This destructor is meant to be overriden by the destructors of derived objects
	virtual ~Shape();
	//returns the shape's center
	Point GetCenter();
	void SetCenter(float x_, float y_);
	//A pure virtual draw function that is meant to be overidden by derived classes
	 virtual void Draw() const = 0;

protected:
	Point center;
};

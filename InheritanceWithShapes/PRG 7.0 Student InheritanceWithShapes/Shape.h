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
	Shape(Point center_);
	virtual ~Shape();
	Point GetCenter();
	void SetCenter(float x_, float y_);
	virtual void Draw();

private:
	Point center;
};

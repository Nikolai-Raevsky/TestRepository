#pragma once
/********************************************
	Filename: Rectangle.h
	Author: Nikolai Raevsky (nikolai.raevsky@digipen.edu)
	Assignment: PRG 7.2.11 CORE ASSIGNMENT: Inheritance with Shapes
	Course: WANIC VGP2
********************************************/
#include "Point.h"
#include "Shape.h"
#include "Shape_With_Vertices.h"

class Rectangle : public Shape_With_Vertices
{
public:
	//This is a constructor that initializes a rectangle with a center, width, and height set to center_, width_, and height_ respetively
	Rectangle(Point center_, unsigned int width_, unsigned int height_);
	//This function outputs the rectangle's center, width, height, and vertices
	void Draw() const;
	
private:
	unsigned int width;
	unsigned int height;
};
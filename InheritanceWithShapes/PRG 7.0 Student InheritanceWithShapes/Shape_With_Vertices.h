#pragma once
/********************************************
	Filename: Shape_With_Vertices.h
	Author: Nikolai Raevsky (nikolai.raevsky@digipen.edu)
	Assignment: PRG 7.2.11 CORE ASSIGNMENT: Inheritance with Shapes
	Course: WANIC VGP2
********************************************/
#include "Shape.h"
#include "Point.h"


class Shape_With_Vertices : public Shape
{
public:
	//This is a constructor that initializes a Shape_With_Vertices with a center set to center_ and a number_of_vertices set to number_of_vertices_
	Shape_With_Vertices(Point center_, unsigned int number_of_vertices_);

	//This is a copy constructor that allocates new memory for a shape_with_vertices with identical dereferenced vertices and number_of_vertices values with the passed in figure Shape_With_Vertices
	Shape_With_Vertices(const Shape_With_Vertices& figure);

	//This is a destructor meant to be overidden by the rectangle and polygon destructors
	virtual ~Shape_With_Vertices();

	
	//	Sets center to a point made up of values x_ and y_ and transforms the other vertices based on how much the center was transformed. Rectangle doesn't track individual vertices so I have to make different variants for each of them
	void SetCenter(float x_, float y_);

	
	

protected:
	Point* vertices; //array
	unsigned int number_of_vertices;
};
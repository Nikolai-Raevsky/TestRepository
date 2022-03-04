/********************************************
	Filename: Shape_With_Vertices.cpp
	Author: Nikolai Raevsky (nikolai.raevsky@digipen.edu)
	Assignment: PRG 7.2.11 CORE ASSIGNMENT: Inheritance with Shapes
	Course: WANIC VGP2
********************************************/
#include <iostream>
#include "Shape_With_Vertices.h"

Shape_With_Vertices::Shape_With_Vertices(Point center_, unsigned int number_of_vertices_) : Shape(center_), number_of_vertices(number_of_vertices_)
{
	vertices = new Point[number_of_vertices];
}

Shape_With_Vertices::~Shape_With_Vertices()
{
	delete vertices;
	vertices = nullptr;
}

void Shape_With_Vertices::SetCenter(float x_, float y_)
{	
	float translateX = x_ - center.x;
	float translateY = y_ - center.y;
	center = Point(x_, y_);

	for (unsigned int i = 0; i < number_of_vertices; i++)
	{
		vertices[i] = Point(vertices[i].x + translateX, vertices[i].y + translateY);
	}
}
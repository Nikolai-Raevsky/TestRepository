/********************************************
	Filename: Rectangle.cpp
	Author: Nikolai Raevsky (nikolai.raevsky@digipen.edu)
	Assignment: PRG 7.2.11 CORE ASSIGNMENT: Inheritance with Shapes
	Course: WANIC VGP2
********************************************/
#include <iostream>
#include "Rectangle.h"
#include "Shape_With_Vertices.h"
#include "Shape.h"

Rectangle::Rectangle(Point center_, unsigned int width_, unsigned int height_) : Shape_With_Vertices(center_, 4), width(width_), height(height_)
{
	//------I'll probably need to readjust the operations until they match the rectangle output files better but this is good enough for now

	//Top left vertex
	vertices[0] = Point(center.x - (static_cast<float>(width) / 2), center.y + (float(height) / 2));

	//Top right vertex
	vertices[1] = Point(center.x + (static_cast<float>(width) / 2), center.y + (float(height) / 2));

	//Bottom right vertex
	vertices[2] = Point(center.x + (static_cast<float>(width) / 2), center.y - (float(height) / 2));

	//Bottom left vertex
	vertices[3] = Point(center.x - (static_cast<float>(width) / 2), center.y - (float(height) / 2));

	
}

void Rectangle::Draw() const
{
	std::cout << "Drawing a rectangle at x = " << center.x << " y = " << center.y << " with width = " << width << " and height = " << height << std::endl;

	for (unsigned int i = 0; i < number_of_vertices; i++)
	{
		std::cout << "Vertex " << i << " (" << vertices[i].x << ", " << vertices[i].y << ")" << std::endl;
	}
	std::cout << std::endl;
}
/********************************************
	Filename: Polygon.cpp
	Author: Nikolai Raevsky (nikolai.raevsky@digipen.edu)
	Assignment: PRG 7.2.11 CORE ASSIGNMENT: Inheritance with Shapes
	Course: WANIC VGP2
********************************************/
#include <iostream>
#include "Polygon.h"
#include "Shape_With_Vertices.h"
#include "Shape.h"
#include "Point.h"

Polygon::Polygon(Point center_, unsigned int number_of_vertices_) : Shape_With_Vertices(center_, number_of_vertices_)
{
	for (unsigned int i = 0; i < number_of_vertices; i++)
	{
		vertices[i] = Point(0, 0);
	}
}

Polygon::Polygon(Point center_, const Point* points, unsigned int number_of_vertices_) : Shape_With_Vertices(center_, number_of_vertices_)
{
	for (unsigned int i = 0; i < number_of_vertices; i++)
	{
		vertices[i] = Point(center.x + points[i].x, center.y + points[i].y);//points[i];
	}
}

void Polygon::SetVertex(unsigned int vertexIdx_, float x_, float y_)
{
	if (vertexIdx_ >= number_of_vertices)
	{
		std::cout << "Bad vertex index provided" << std::endl;
		return;
	}
	vertices[vertexIdx_] = Point(center.x + x_, center.y + y_);
}

void Polygon::Draw() const
{
	std::cout << "Drawing a polygon at x = " << center.x << " y = " << center.y  << std::endl;

	for (unsigned int i = 0; i < number_of_vertices; i++)
	{
		std::cout << "Vertex " << i << " (" << vertices[i].x << ", " << vertices[i].y << ")" << std::endl;
	}
	std::cout << std::endl;
}
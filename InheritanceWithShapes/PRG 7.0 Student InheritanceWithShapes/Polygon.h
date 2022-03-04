#pragma once
/********************************************
	Filename: Polygon.h
	Author: Nikolai Raevsky (nikolai.raevsky@digipen.edu)
	Assignment: PRG 7.2.11 CORE ASSIGNMENT: Inheritance with Shapes
	Course: WANIC VGP2
********************************************/
#include "Point.h"
#include "Shape_With_Vertices.h"
#include "Shape.h"

class Polygon : public Shape_With_Vertices 
{
public:
	//This is a constructor that creates a Polygon with a center and number_of_vertices set to center_ and number_of_vertices_ respectively. All the vertices are set to (0,0) in this version
	Polygon(Point center_, unsigned int number_of_vertices_);

	//An overload of the Polygon constructor that passes in an array of points, which the Polygon's vertices array will be assigned to
	Polygon(Point center_, const Point *points_, unsigned int number_of_vertices);
	
	//This function assigns the the vertex at vertices[vertexIdx_] to a new Point(x_, y_)
	void SetVertex(unsigned int vertexIdx_, float x_, float y_);

	//This function outputs the polygon center and vertices to the console
	void Draw() const;
};
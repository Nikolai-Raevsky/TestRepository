/********************************************
	Filename: Shape_With_Vertices.cpp
	Author: Nikolai Raevsky (nikolai.raevsky@digipen.edu)
	Assignment: PRG 7.2.11 CORE ASSIGNMENT: Inheritance with Shapes
	Course: WANIC VGP2
********************************************/
#include <iostream>
#include "Shape_With_Vertices.h"

Shape_With_Vertices::Shape_With_Vertices(Point center_, unsigned int number_of_vertices_) : Shape(center), number_of_vertices(number_of_vertices_)
{}

Shape_With_Vertices::~Shape_With_Vertices()
{
	delete vertices;
	vertices = nullptr;
}
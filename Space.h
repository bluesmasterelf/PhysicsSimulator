#pragma once
#include "BodyFactory.h"
#include "Body.h"
#include <iostream>
#include <cmath>

#include <vector>
class Space
{
	char space[40][40];
	Body bodies[10];
	//Body* pointers[10];
	std::vector<Body*> pointers;
	//Sphere* pointers[10];
	BodyFactory factory;
		
public:
	void fillSpace();
	void makeBodies();
	void makePointers(int quantity);

	//display
	void display();

	void time();
	void collide(Body* b1, Body* b2);

	//void collide(Sphere b1, Sphere b2);

	Space();
	~Space();
};


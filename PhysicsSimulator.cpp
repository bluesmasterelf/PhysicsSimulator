// PhysicsSimulator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Body.h"
#include "BodyFactory.h"
#include "Space.h"
#include <iostream>


int main()
{
	Space awesomeSpace;
	awesomeSpace.fillSpace();
	awesomeSpace.makePointers(10);
	//awesomeSpace.makeBodies();
	for (int i = 0; i < 3; i++) {
		awesomeSpace.display();
		for (int j = 0; j < 3; j++) {//only display every few time iterates
			awesomeSpace.time();
			std::cout << "time passes";
		}
	}
	return 0;
}
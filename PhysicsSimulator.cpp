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
	awesomeSpace.makePointers(5);
	//awesomeSpace.makeBodies();
	for (int i = 0; i < 8; i++) {
		awesomeSpace.display();
		awesomeSpace.fillSpace();//clear trails periodically
		for (int j = 0; j < 8; j++) {//only display every few time iterates
			awesomeSpace.time();
			std::cout << "time passes" << std::endl;
		}
	}
	return 0;
}
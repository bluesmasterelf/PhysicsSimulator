#include "Space.h"
#include <vector>

void Space::fillSpace() {
	for (int i = 0; i < 40; i++) {
		for (int j = 0; j < 40;j++) {
			space[i][j] = '.';
		}
	}
}

//Generate pointers and place them in space
void Space::makePointers(int quantity=10) {
	for (int i = 0; i < quantity; i++) {
		//pointers.push_back(new Sphere); 
		pointers.push_back(factory.MakePointer(1));
		space[pointers[i]->getPosition()[0]][pointers[i]->getPosition()[1]] = static_cast<char>(i + 70);
	}
}

void Space::display() {
	for (int i = 0; i < 40; i++) {  
		for (int j = 0; j < 40;j++) {
			std::cout << space[i][j];
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void Space::time() {
	for (int i = 0; i < 10; i++) {
		
		//update positions according as their vectors dictate
		Body* temp = pointers[i];
		int newPos[2] = { (temp->getPosition()[0] + temp->getVector()[0]) % 40, (temp->getPosition()[1] + temp->getVector()[1]) % 40 };
		temp->updatePosition(newPos);
		pointers[i] = temp;
		//update positions in space
		space[pointers[i]->getPosition()[0]][pointers[i]->getPosition()[1]] = static_cast<char>(i + 70);

		//detect collisions
		for (int i = 0; i < 9; i++) {
			for (int j = i+1; j < 10;j++) {
				collide(pointers[i], pointers[j]);
				//std::cout << i << j << ", ";
			}
		}
	}
}
void Space::collide(Body* b1, Body* b2) {
	b1->collideWith(b2);
}

Space::Space(){
}
Space::~Space(){}

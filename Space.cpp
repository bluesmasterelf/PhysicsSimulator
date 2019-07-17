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
	for (int k = 0; k < 2; k++) {
		pointers.push_back(factory.MakePointer(2)); //seed a few missiles
		pointers[k]->setName(static_cast<char>(k + 65));
		space[pointers[k]->getPosition()[0]][pointers[k]->getPosition()[1]] = pointers[k]->getName();

	}
	for (int i = 2; i < quantity+2; i++) {
		pointers.push_back(factory.MakePointer(1));
		pointers[i]->setName(static_cast<char>(i + 65));
		space[pointers[i]->getPosition()[0]][pointers[i]->getPosition()[1]] = pointers[i]->getName();
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
	for (int i = 0; i < pointers.size(); i++) {
		
		//update positions according as their vectors dictate
		Body* temp = pointers[i];
		int newPos[2] = { (temp->getPosition()[0] + temp->getVector()[0]) % 40, (temp->getPosition()[1] + temp->getVector()[1]) % 40 };
		//correct for negative indices
		if (newPos[0] < 0) { newPos[0] += 40; }
		if (newPos[1] < 0) { newPos[1] += 40; }
		temp->updatePosition(newPos);
		pointers[i] = temp;
		
		//update positions in space
		space[pointers[i]->getPosition()[0]][pointers[i]->getPosition()[1]] = pointers[i]->getName();
	}
		//detect collisions
		for (int i = 0; i < pointers.size()-1; i++) {
			for (int j = i+1; j < pointers.size();j++) {
				//std::cout << i << j << "collision loop indices" << std::endl;
				bool detonation = collide(pointers[i], pointers[j]);
				if (detonation) {
					std::cout << pointers[i]->getName() << " destroyed " << pointers[j]->getName() << std::endl;
					int detPos[2] = { pointers[i]->getPosition()[0], pointers[i]->getPosition()[1] };
					space[detPos[0]][detPos[1]] = 'X';
					space[detPos[0] + 1][detPos[1]] = 'X';
					space[detPos[0] - 1][detPos[1]] = 'X';
					space[detPos[0]][detPos[1] + 1] = 'X';
					space[detPos[0]][detPos[1] -1] = 'X';
					pointers.erase(pointers.begin() + i);
					pointers.erase(pointers.begin() + j-1);
					}
			}
		}
	
}
bool Space::collide(Body* b1, Body* b2) {
	return b1->collideWith(b2);
}


Space::Space(){
}
Space::~Space(){}

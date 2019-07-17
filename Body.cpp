#include "Body.h"
#include <iostream>


//abstract Body function definitions
int* Body::getPosition() {
	return position;
}
void Body::updatePosition(int newPosition[]) {
	position[0] = newPosition[0];
	position[1] = newPosition[1];
}

int* Body::getVector() {
	return vector;
}
void Body::updateVector(int newVector[]) {
	vector[0] = newVector[0];
	vector[1] = newVector[1];
}

int Body::getMass() {
	return mass;
} 
void Body::setMass(int newMass) {
	mass = newMass;
}

void Body::setName(char newName) {
	name = newName;
}
char Body::getName() {
	return name;
}

bool Body::collideWith(Body* b2) { return false; }

bool Body::collide(int* position, int rad) { return false; }

//Sphere function definitions
int Sphere::getRadius() {
	return radius;
}
void Sphere::setRadius(int newRadius) {
	radius = newRadius;
}
void Sphere::setElastic(bool newElastic) {
	elastic = newElastic;
}

bool Sphere::collideWith(Body* b2) {
	bool hit = b2->collide(getPosition(), getRadius());
	if (hit) {
		std::cout << getName() << "collided with " << b2->getName() << " at " << getPosition()[0] << ", " << getPosition()[1] << std::endl;


		//vector mathematics (this got out of hand quickly, didn't it?)
		float normSquared= (float)(pow(getPosition()[0] - b2->getPosition()[0],2))+ 
			(float)(pow(getPosition()[1] - b2->getPosition()[1], 2));//only invariant throughout computation
		
		//Computing new first vector
		float massDisp1 = 2 * (float)b2->getMass() / (float)(getMass() + b2->getMass());
		int dotProduct1 = (getVector()[0] - b2->getVector()[0]) * (getPosition()[0] - b2->getPosition()[0])
			+ (getVector()[1] - b2->getVector()[1]) * (getPosition()[1] - b2->getPosition()[1]);//invariant through first vector computation
		
		//first vector x computation
		float impactDirection1X = (float)(getPosition()[0] - b2->getPosition()[0]);
		int totalDisplacement1X = (int)(massDisp1*dotProduct1*impactDirection1X/normSquared+0.5);//round float to nearest integer
		
		//std::cout << "first vector, second vector, first position, secon "
		std::cout << "Norm squared " << normSquared << std::endl;
		std::cout << "massDisp1 " << massDisp1 << " dotProduct1 " << dotProduct1 << std::endl;
		std::cout << "impactDirection1x " << impactDirection1X << " totalDisplacement1X " << totalDisplacement1X << std::endl;
		int newVector1X=getVector()[0]-totalDisplacement1X;

		//first vector y computation
		float impactDirection1Y = (float)(getPosition()[1] - b2->getPosition()[1]);
		int totalDisplacement1Y = (int)(massDisp1 * dotProduct1 * impactDirection1Y / normSquared + 0.5);//round float to nearest integer

		int newVector1Y = getVector()[1] - totalDisplacement1Y;
		//tempVec1Y = newVector1Y;
		int newVector1[2] = { newVector1X,newVector1Y };

		//Computing new second vector
		float massDisp2 = 2 * (float)getMass() / (float)(getMass() + b2->getMass());
		int dotProduct2 = -1 * dotProduct1;

		//second vector x computation
		float impactDirection2X =-1* impactDirection1X;
		int totalDisplacement2X = (int)(massDisp1 * dotProduct2 * impactDirection2X / normSquared + 0.5);//round float to nearest integer

		int newVector2X = b2->getVector()[0] - totalDisplacement2X;
		
		//second vector y computation
		float impactDirection2Y = -1.0*impactDirection1Y;
		int totalDisplacement2Y = (int)(massDisp1 * dotProduct1 * impactDirection2Y / normSquared + 0.5);//round float to nearest integer
		
		
		int newVector2Y = b2->getVector()[1] - totalDisplacement2Y;
		
		//detect if vectors unchanged in casting to int
		if (newVector1X == getVector()[0] && newVector1Y == getVector()[1] && newVector2X == b2->getVector()[0] && newVector2Y == b2->getVector()[1]) {
			newVector2Y += 3;//throw off second body in event nothing changes
		}
		
		//newVector2Y += 3;  //vectors not changing , must be a math error. 

		int newVector2[2] = {newVector2X,newVector2Y};
		
		//update vectors //
		b2->updateVector(newVector2);
		updateVector(newVector1);

	
	}
	return false;
}
bool Sphere::collide(int* pos, int rad) {
	float dist = sqrt(pow((float)(pos[0] - getPosition()[0]), 2) + pow((float)(pos[1] - getPosition()[1]), 2));
	float sumRad = (float)(rad + getRadius());
	if (dist< sumRad){
		return true;}
	return false;
}

//missile function definitions
bool Missile::collideWith(Body* b2) {
	bool hit = b2->collide(getPosition(), getRadius());
	if (hit) {
		return true;
	}
	return false;
}
bool Missile::collide(int* pos, int rad) {
	float dist = sqrt(pow((float)(pos[0] - getPosition()[0]), 2) + pow((float)(pos[1] - getPosition()[1]), 2));
	float sumRad = (float)(rad + getRadius());
	if (dist < sumRad) { return true; }
	return false;
}
int Missile::getRadius() {
	return radius;
}
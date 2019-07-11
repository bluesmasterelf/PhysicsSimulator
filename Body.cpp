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

void Body::collideWith(Body* b2) { std::cout << "fail"; }

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

void Sphere::collideWith(Body* b2) {
	bool hit = b2->collide(getPosition(), getRadius());
	if (hit) {
		int tempVec1X =  getVector()[0] ;
		int tempVec1Y = getVector()[1];
		int tempVec2X = b2->getVector()[0];
		int tempVec2Y = b2->getVector()[1];

		//vector mathematics (this got out of hand quickly, didn't it?)
		float normSquared= pow((float)(pow(getPosition()[0] - b2->getPosition()[0],2))+ 
			(float)(pow(getPosition()[1] - b2->getPosition()[1], 2)),2);//only invariant throughout computation
		
		//Computing new first vector
		float massDisp1 = 2 * (float)b2->getMass() / (float)(getMass() + b2->getMass());
		int dotProduct1 = (getVector()[0] - b2->getVector()[0]) * (getPosition()[0] - b2->getPosition()[0])
			+ (getVector()[1] - b2->getVector()[1]) * (getPosition()[1] - b2->getPosition()[1]);//invariant through first vector computation
		
		//first vector x computation
		float impactDirection1X = (float)(getPosition()[0] - b2->getPosition()[0]);
		int totalDisplacement1X = (int)(massDisp1*dotProduct1*impactDirection1X/normSquared+0.5);//round float to nearest integer
		
		int newVector1X=getVector()[0]-totalDisplacement1X;
		tempVec1X = newVector1X;
		//first vector y computation
		float impactDirection1Y = (float)(getPosition()[1] - b2->getPosition()[1]);
		int totalDisplacement1Y = (int)(massDisp1 * dotProduct1 * impactDirection1Y / normSquared + 0.5);//round float to nearest integer

		int newVector1Y = getVector()[1] - totalDisplacement1Y;
		tempVec1Y = newVector1Y;
		int newVector1[2] = { newVector1X,newVector1Y };

		//Computing new second vector

		float massDisp2 = 2 * (float)getMass() / (float)(getMass() + b2->getMass());
		int dotProduct2 = -1 * dotProduct1;

		//second vector x computation
		float impactDirection2X = -1.0*impactDirection1X;
		int totalDisplacement2X = (int)(massDisp1 * dotProduct2 * impactDirection2X / normSquared + 0.5);//round float to nearest integer

		int newVector2X = getVector()[0] - totalDisplacement2X;
		tempVec2X = newVector2X;
		//second vector y computation
		float impactDirection2Y = -1.0*impactDirection1Y;
		int totalDisplacement2Y = (int)(massDisp1 * dotProduct1 * impactDirection2Y / normSquared + 0.5);//round float to nearest integer

		int newVector2Y = getVector()[1] - totalDisplacement2Y;
		tempVec2Y = newVector2Y;
		int newVector2[2] = {newVector2X,newVector2Y};


		//update vectors
		b2->updateVector(newVector2);
		updateVector(newVector1);

		//let the user know what's up
		std::cout << "collision detected at " << getPosition()[0] << getPosition()[1]<< std::endl;
	}
}
bool Sphere::collide(int* pos, int rad) {
	float dist = sqrt(pow((float)(pos[0] - getPosition()[0]), 2) + pow((float)(pos[1] - getPosition()[1]), 2));
	float sumRad = (float)(rad + getRadius());
	if (dist< sumRad){return true;}
	return false;
}



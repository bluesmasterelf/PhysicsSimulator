#pragma once
#include <cstdlib>
class Body
{
	//abstract Body fields
	int mass = std::rand()%10+3;
	int vector[2] = { std::rand() % 8 - 4, std::rand() % 8 - 4 };
	int position[2] = { std::rand() % 40 , std::rand() % 40 };



public:
	int* getPosition();
	void updatePosition(int newPosition[]);
	
	int* getVector();
	void updateVector(int newVector[]);
	
	int getMass();
	void setMass(int newMass);

	virtual void collideWith(Body* b2);
	virtual bool collide(int* position, int rad);
};

class Sphere : public Body {
	int radius=std::rand()%2+1;
	bool elastic=false;
	//bool sticky; for playing later
public:
	void setRadius(int newRadius);
	int getRadius();
	void setElastic(bool newElastic);

	void collideWith(Body* b2);
	bool collide(int* pos, int rad);
};


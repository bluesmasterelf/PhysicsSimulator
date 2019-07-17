#pragma once
#include <cstdlib>
class Body
{
	//abstract Body fields
	int mass = std::rand()%20+40;
	int vector[2] = { std::rand() % 8 - 4, std::rand() % 8 - 4 };
	int position[2] = { std::rand() % 40 , std::rand() % 40 };
	char name;



public:
	void setName(char newName);
	char getName();
	int* getPosition();
	void updatePosition(int newPosition[]);
	
	int* getVector();
	void updateVector(int newVector[]);
	
	int getMass();
	void setMass(int newMass);

	virtual bool collideWith(Body* b2);
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

	bool collideWith(Body* b2);
	bool collide(int* pos, int rad);
};

class Missile : public Body {
	int radius = 1;
public:
	int getRadius();
	bool collideWith(Body* b2);
	bool collide(int* pos, int rad);
};
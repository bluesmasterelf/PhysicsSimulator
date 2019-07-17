#include "BodyFactory.h"

Body BodyFactory::MakeBody(int selection = 1) {
	//only one case to start
	switch (selection) {
	case 1: {
		Sphere sphere;
		return sphere;
		break;
	}
	case 2: {
		Missile missile;
		return missile;
		break;
	}
	}
}

Body* BodyFactory::MakePointer(int selection = 1) {
	switch (selection) {
	case 1:
		return new Sphere;
		break;
	case 2:
		return new Missile;
		break;
	}
}

BodyFactory::BodyFactory(){
}

BodyFactory::~BodyFactory(){
}

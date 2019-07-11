#include "BodyFactory.h"

Body BodyFactory::MakeBody(int selection = 1) {
	//only one case to start
	switch (selection) {
	case 1:
		Sphere ret_sphere;
		return ret_sphere;
	}
}

Body* BodyFactory::MakePointer(int selection = 1) {
	switch (selection) {
	case 1:
		return new Sphere;
	}
}

BodyFactory::BodyFactory(){
}

BodyFactory::~BodyFactory(){
}

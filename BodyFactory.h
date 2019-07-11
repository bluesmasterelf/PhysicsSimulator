#include "Body.h"
#pragma once

class BodyFactory
{
public:
	Body MakeBody(int selection);

	Body* MakePointer(int selection);

	BodyFactory();
	~BodyFactory();

};
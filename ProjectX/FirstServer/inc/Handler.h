#pragma once
#include <string>

enum class Robot_Actions : int
{
	UP = 0,
	LEFT,
	DOWN,
	RIGHT,
	HEAD_LEFT,
	HEAD_RIGHT
};

//char* request(Robot_Actions action, char power);

void request(Robot_Actions, unsigned char*, unsigned char);



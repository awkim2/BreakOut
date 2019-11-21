#pragma once

#include "ofMain.h"

class Paddle {
public:
	Paddle();
	int GetXPosition();
	void SetXPosition(int new_position);
private:
	int x_position_;
};
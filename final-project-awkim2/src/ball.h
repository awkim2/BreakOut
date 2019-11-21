#pragma once

#include <vector>

class Ball {
public:
	Ball();
	int GetXPosition();
	int GetYPosition();
	void SetXPosition(int x_position);
	void SetYPosition(int y_position);

private:
	int x_position_;
	int y_position_;
};
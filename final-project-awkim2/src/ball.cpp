#include "ball.h"

Ball::Ball()
{
	x_position_ = 500;
	y_position_ = 550;
}

int Ball::GetXPosition()
{
	return x_position_;
}

int Ball::GetYPosition()
{
	return y_position_;
}

void Ball::SetXPosition(int x_position)
{
	x_position_ = x_position;
}

void Ball::SetYPosition(int y_position)
{
	y_position_ = y_position;
}

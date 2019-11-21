#include "paddle.h"

Paddle::Paddle()
{
	x_position_ = 400;
}

int Paddle::GetXPosition()
{
	return x_position_;
}

void Paddle::SetXPosition(int new_position)
{
	x_position_ = new_position;
}

#include "brick.h"


Brick::Brick(int lives, int x_position, int y_position)
{
	lives_ = lives;
	x_position_ = x_position;
	y_position_ = y_position;
	width_ = 175;
	height_ = 45;
	powerup_ = false;
}

int Brick::GetXPosition()
{
	return x_position_;
}

int Brick::GetYPosition()
{
	return y_position_;
}

int Brick::GetWidth()
{
	return width_;
}

int Brick::GetHeight()
{
	return height_;
}

int Brick::GetLives()
{
	return lives_;
}

bool Brick::GetPowerUp()
{
	return powerup_;
}

void Brick::SetXPosition(int x_position)
{
}

void Brick::SetYPosition(int y_position)
{
}

void Brick::SetLives(int lives)
{
	lives_ = lives;
}

void Brick::SetPowerUp(bool boolean)
{
	powerup_ = boolean;
}

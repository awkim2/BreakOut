#pragma once

class Brick {
public:
	Brick(int lives, int x_position, int y_position);
	int GetXPosition();
	int GetYPosition();
	int GetWidth();
	int GetHeight();
	int GetLives();
	bool GetPowerUp();
	void SetXPosition(int x_position);
	void SetYPosition(int y_position);
	void SetLives(int lives);
	void SetPowerUp(bool boolean);
private:
	int lives_;
	int x_position_;
	int y_position_;
	int width_;
	int height_;
	bool powerup_;
};
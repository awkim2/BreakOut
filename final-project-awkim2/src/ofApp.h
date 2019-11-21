#pragma once

#include <ctime>
#include <cstdlib>
#include <utility>
#include <vector>
#include <stdlib.h>
#include "ofMain.h"
#include "paddle.h"
#include "ball.h"
#include "brick.h"


enum GameState {
	SPLASH = 0,
	INSTRUCTIONS,
	LEVELS,
	PAUSED,
	DEAD,
	WON
};

enum PowerBrick {
	PLUSLIFE = 0,
	SLOWBALL,
	DOUBLEHIT,
	EXTENDPADDLE
};

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();
	void resetLevel();

	void keyPressed(int key);
	void keyReleased(int key);
	void windowResized(int w, int h);

	void DrawSplash();
	void DrawInstructions();
	void DrawLevels();
	void DrawPaused();
	void DrawDead();
	void DrawWon();

	void PaddleMove();
	void BallMove();

	void ConstructBricks(int level_);
	void DrawBricks();

	int CollisionHandle(Brick stationary_, Ball projectile_, int dx_, int dy_);
	bool CollisionBrick(Brick stationary_);
	bool CollisionPaddle();


private:
	Paddle player_;
	Ball ball_;
	vector<vector<Brick>> construct_;

	GameState current_gamestate_;
	
	bool move_left_;
	bool move_right_;
	bool move_ball_ = false;
	int paddle_velocity;
	int ball_x_velocity_ = 4;
	int ball_y_velocity_ = -4;

	bool construct_bricks_;
	bool clear_bricks_;

	int lives_;
	int current_level_;
	
	ofTrueTypeFont arcade_font;
	ofColor BLACK_ = ofColor(0, 0, 0);
	ofColor WHITE_ = ofColor(255, 255, 255);
	ofColor GREEN_ = ofColor(0, 255, 0);
	ofColor BLUE_ = ofColor(0, 0, 255);
	ofColor RED_ = ofColor(255, 0, 0);
	ofColor YELLOW_ = ofColor(238, 244, 66);
	ofColor brick_colors_[5] = {RED_, YELLOW_, GREEN_, BLUE_, BLACK_};

	PowerBrick power_brick_[4] = { PLUSLIFE, SLOWBALL, DOUBLEHIT, EXTENDPADDLE };
	PowerBrick set_power_;

};

#include "ofApp.h"
#include <iostream>

#define construct_size_ 5

using namespace std;


void ofApp::setup() {
	ofSetWindowTitle("BreakOutGame");
	current_gamestate_ = SPLASH;
	arcade_font.load("ARCADECLASSIC.ttf", 32, false);
	player_ = Paddle();
	ball_ = Ball();
	construct_bricks_ = true;
	lives_ = 3;
	current_level_ = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
	PaddleMove();
	BallMove();
	
	if (current_gamestate_ == LEVELS && clear_bricks_) {
		resetLevel();
		construct_bricks_ = true;
	}
	if (lives_ <= 0) {
		current_gamestate_ = DEAD;
	}
	if (current_level_ > 5) {
		current_gamestate_ = WON;
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	if (current_gamestate_ == SPLASH) {
		DrawSplash();
	}
	else if (current_gamestate_ == INSTRUCTIONS) {
		move_ball_ = true;
		update();
		DrawInstructions();
	}
	else if (current_gamestate_ == PAUSED) {
		move_ball_ = false;
		DrawPaused();
	}
	else if (current_gamestate_ == LEVELS) {
		update();
		DrawLevels();	
	}
	else if (current_gamestate_ == DEAD) {
		DrawDead();
	}
	else {
		DrawWon();
	}
}

/*
 * a method called at the beginning of each level
 */
void ofApp::resetLevel()
{
	player_ = Paddle();
	ball_ = Ball();
	move_ball_ = false;
	ball_x_velocity_ = 4;
	ball_y_velocity_ = -4;
	clear_bricks_ = false;
	construct_.clear();
	current_level_++;
	ConstructBricks(current_level_);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == OF_KEY_F12) {
		ofToggleFullscreen();
		return;
	}
	int upper_key = toupper(key); // Standardize on upper case
	
	if (current_gamestate_ == SPLASH) {
		current_gamestate_ = (current_gamestate_ == SPLASH && key == OF_KEY_BACKSPACE) ? INSTRUCTIONS : SPLASH;
	}
	if (current_gamestate_ == INSTRUCTIONS) {
		current_gamestate_ = (current_gamestate_ == INSTRUCTIONS && upper_key == 'S') ? LEVELS : INSTRUCTIONS;
	}
	
	if (upper_key == 'J') {
		update();
		move_left_ = true;
	}
	else if (upper_key == 'L') {
		update();
		move_right_ = true;
	}
	if (current_gamestate_ == INSTRUCTIONS && upper_key == 'B') {
		update();
		move_ball_ = true;
	}
	if (current_gamestate_ == LEVELS && upper_key == 'B') {
		update();
		move_ball_ = true;
	}
	if (current_gamestate_ == LEVELS) {
		current_gamestate_ = (current_gamestate_ == LEVELS && upper_key == 'P') ? PAUSED : LEVELS;
	}
	if (current_gamestate_ == PAUSED) {
		current_gamestate_ = (current_gamestate_ == PAUSED && upper_key == 'O') ? LEVELS : PAUSED;
	}
	if (current_gamestate_ == LEVELS && upper_key == 'N') {
		update();
		clear_bricks_ = true;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	int upper_key = toupper(key); // Standardize on upper case
	if (upper_key == 'J') {
		move_left_ = false;
	}
	else if (upper_key == 'L') {
		move_right_ = false;
	}
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

/*
 * the following are darw methods for each gamestate
 */
void ofApp::DrawSplash()
{
	ofSetBackgroundColor(BLACK_);
	string welcome_message = "My BreakOut Game";
	ofSetColor(YELLOW_);
	arcade_font.drawString(welcome_message, 350, 300);
	arcade_font.drawString("PRESS BACKSPC TO LOAD INSTRUCTIONS", 160, 400);
}

void ofApp::DrawInstructions()
{
	ofSetBackgroundColor(BLACK_);
	ofSetColor(YELLOW_);
	arcade_font.drawString("The point of this game is survive all three \n levels without losing all your lives!", 75, 100);
	arcade_font.drawString("Use the J and L keys to move left and right!", 80, 200);
	arcade_font.drawString("Keep your eye out for any special power bricks!", 50, 250);
	arcade_font.drawString("press the s key to begin playing!", 200, 300);

	ofSetColor(GREEN_);
	ofDrawCircle(ball_.GetXPosition(), ball_.GetYPosition(), 30);
}

void ofApp::DrawLevels() {
	ofSetBackgroundColor(WHITE_);
	ofSetColor(RED_);
	ofDrawRectangle(player_.GetXPosition(), 720, 150, 10);
	ofSetColor(GREEN_);
	ofDrawCircle(ball_.GetXPosition(), ball_.GetYPosition(), 10);
	DrawBricks();
	ofSetColor(BLACK_);
	string life_str = to_string(lives_);
	string level_str = to_string(current_level_);
	arcade_font.drawString(life_str + " LIVES ", 40, 780);
	arcade_font.drawString("LEVEL " + level_str, 820, 780);
}

void ofApp::DrawPaused()
{
	ofSetBackgroundColor(WHITE_);
	ofSetColor(BLACK_);
	arcade_font.drawString("game is paused", 350, 400);
}

void ofApp::DrawDead()
{
	ofSetBackgroundColor(WHITE_);
	ofSetColor(BLACK_);
	arcade_font.drawString("uh oh! better luck next time!", 220, 400);
}

void ofApp::DrawWon()
{
	ofSetBackgroundColor(WHITE_);
	ofSetColor(BLACK_);
	arcade_font.drawString("congratulations! you won!", 210, 400);
}

/*
 * method to contorl the movements of the paddle.
 */
void ofApp::PaddleMove()
{
	if (move_left_) {
		paddle_velocity = -10;
	}
	else if (move_right_) {
		paddle_velocity = 10;
	}
	else {
		paddle_velocity = 0;
	}
	
	//checking if paddle hits the edge
	if (player_.GetXPosition() + paddle_velocity > 850 || player_.GetXPosition() + paddle_velocity < 0) {
		paddle_velocity = 0;
	}
	
	//translating the paddle with the velocity set above
	int current_position = player_.GetXPosition();
	player_.SetXPosition(current_position + paddle_velocity);
}

/*
 * method to control movements of the ball.
 */
void ofApp::BallMove()
{
	if (move_ball_) {
		int current_x_position = ball_.GetXPosition();
		int current_y_position = ball_.GetYPosition();
		ball_.SetXPosition(current_x_position + ball_x_velocity_);
		ball_.SetYPosition(current_y_position + ball_y_velocity_);
	}
	if (ball_.GetYPosition() < 10) {
		ball_y_velocity_ *= -1;
	}

	if (ball_.GetXPosition() < 10 || ball_.GetXPosition() > 990) {
		ball_x_velocity_ *= -1;
	}
	if (current_gamestate_ == LEVELS && ball_.GetYPosition() >= 780) {
		ball_ = Ball();
		move_ball_ = false;
		ball_x_velocity_ = 4;
		ball_y_velocity_ = -4;
		lives_--;
	}
	//ball for instructions screen
	if (current_gamestate_ == INSTRUCTIONS && ball_.GetYPosition() >= 770) {
		ball_y_velocity_ *= -1;
	}
	//paddle collision
	if (CollisionPaddle()) {
		ball_y_velocity_ *= -1;
		ball_x_velocity_ = ((ball_.GetXPosition() + 10) - (player_.GetXPosition() + (150 / 2))) / 10;
	}

	//brick collision
	for (size_t i = 0; i < construct_.size(); i++) {
		for (size_t j = 0; j < construct_.at(i).size(); j++) {
			if (construct_.at(i).at(j).GetLives() > 0) {
				if (CollisionBrick(construct_.at(i).at(j))) {
					int current_lives = construct_.at(i).at(j).GetLives();
					construct_.at(i).at(j).SetLives(current_lives - 1);
					
					int check_direction = CollisionHandle(construct_.at(i).at(j), ball_, ball_x_velocity_, ball_y_velocity_);
					if (check_direction == 0 || check_direction == 2) {
						ball_x_velocity_ += -1;
					}
					if (check_direction == 1 || check_direction == 3) {
						ball_y_velocity_ *= -1;
					}
					if (construct_.at(i).at(j).GetLives() <= 0) {
						construct_.at(i).erase(construct_.at(i).begin() + j);
					}
				}
			}
		}
	}
}

/*
 * a method to initialize the construct_ vector based on the level
 */
void ofApp::ConstructBricks(int level_)
{	
	int random_x = rand() % 4;
	int random_y = rand() % 4;
	
	if (construct_bricks_) {
		for (int i = 0; i < construct_size_; i++) {
			vector<Brick> lines_;
			for (int j = 0; j < construct_size_; j++) {
				int random = rand() % (level_) + 1;
				Brick single(random, 198 * i + 15, 75 * j + 15);
				if (i == random_x && j == random_y) {
					single.SetPowerUp(true);
					int random_power = rand() % 3;
					set_power_ = power_brick_[random_power];
				}
				lines_.push_back(single);
			}
			construct_.push_back(lines_);
		}
	}
	construct_bricks_ = false;
}

/*
 * a method to draw the construct_ 2D vector
 */
void ofApp::DrawBricks()
{
	clear_bricks_ = true;
	for (auto vector : construct_) {
		for (auto brick : vector) {
			if (brick.GetLives() > 0) {
				clear_bricks_ = false;
				ofSetColor(brick_colors_[brick.GetLives() - 1]);
				if (brick.GetPowerUp()) {
					if (set_power_ == PLUSLIFE) {
						ofSetColor(0, 255, 237); //neon blue
					}
					else if (set_power_ == SLOWBALL) {
						ofSetColor(203, 0, 255); //magenta
					}
					else if (set_power_ == DOUBLEHIT) {
						ofSetColor(255, 157, 0); //orange
					}
					else {
						ofSetColor(255, 0, 102); //hot pink
					}
				}
				ofDrawRectangle(brick.GetXPosition(), brick.GetYPosition(), brick.GetWidth(), brick.GetHeight());
			}
		}
	}
}

/*
 * a method that returns an integer necessary for the angle of collision trajectory.
 */
int ofApp::CollisionHandle(Brick stationary_, Ball projectile_, int dx_, int dy_)
{
	int previous_x = projectile_.GetXPosition() - dx_;
	int previous_y = projectile_.GetYPosition() - dy_;
	int height = 20;
	int width = 20;
	int result = 0; //intersecting from right is default.
	
	if (previous_y + height <= stationary_.GetYPosition() && projectile_.GetYPosition() + height >= stationary_.GetYPosition()) {
		//intersect from top
		result = 1;
	}
	else if (previous_x + width <= stationary_.GetXPosition() && projectile_.GetXPosition() + width >= stationary_.GetXPosition()) {
		//intersect from left
		result = 2;
	}
	else if (previous_y >= stationary_.GetYPosition() + stationary_.GetHeight() && projectile_.GetYPosition() <= stationary_.GetYPosition() + stationary_.GetHeight()) {
		//intersect from bottom
		result = 3;
	}
	return result;
}

/*
 * a method that checks if the ball collided with a brick
 */
bool ofApp::CollisionBrick(Brick stationary_)
{
	int ball_diameter = 20;
	int brick_width = stationary_.GetWidth();
	int brick_height = stationary_.GetHeight();

	if (stationary_.GetXPosition() < ball_.GetXPosition() + ball_diameter &&
		stationary_.GetXPosition() + brick_width > ball_.GetXPosition() &&
		stationary_.GetYPosition() < ball_.GetYPosition() + ball_diameter &&
		stationary_.GetYPosition() + brick_height > ball_.GetYPosition()) {
		return true;
	}
	return false;
}

/*
 * a method that checks if the ball collided with the paddle
 */
bool ofApp::CollisionPaddle()
{
	int ball_diameter = 20;
	int paddle_width = 150;
	int paddle_height = 10;
	int paddle_y_value = 720;
	if (player_.GetXPosition() < ball_.GetXPosition() + ball_diameter &&
		player_.GetXPosition() + paddle_width > ball_.GetXPosition() &&
		paddle_y_value < ball_.GetYPosition() + ball_diameter &&
		paddle_y_value + paddle_height > ball_.GetYPosition()) {
		return true;
	}
	return false;
}



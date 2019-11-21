# Final Project

## Ball Class
- created a starting x and y position
- created get and set methods for the x and y position

## Brick Class
- created a constructor that takes in lives, x position, and y position
- there is a set width and height
- created get and set methods for the lives, x position, and y position

## ofApp Class
- created enum for gamestates
### setup function
- initializes everything for the game
### update function
- includes moveball and movepaddle which updates the positions
- includes resetLevel method which is called at the beginning of every level
- sets conditions for gamestates
### draw function
- includes functions that draw for each gamestate and update
### keypressed function
- includes conditions for keys that are pressed to progress throughout the game
### construct bricks function
- a function that initialized a 2d vector with bricks based on the level

## Paddle Class
- includes an x position
- created a get and set method for the x position

# Final Project Proposal

In this final project, I propose to create my own take on the classic game BreakOut. The game BreakOut consists of a 
"paddle" object at the bottom of the GUI window which moves horizontally. There is a ball object which bounces around
the frame and bouces according to the angle of its collision course. At the top of the frame is an array of boxes. The
whole point of the game is to use the collisions of the balls to break the boxes at the top of the frame without the
ball going past the paddle object. Each box has a number of lives needed for the box to disintegrate. Everytime the 
ball contacts the box, the box loses a life. There are 5 levels/gamestates to this game and as the levels progress, the
number of boxes and lives per boxes will increase, making the game more difficult. The objective of the game is to 
reach level 5 and lose as little balls as possible. At the end of the game, there will be a high score board that stores
all past scores.

I will use the ofxGui Library and the ofxVectorGraphics Library to create this game. The ofxGui Library help me
design the game with certain commands and setting colors. The ofxVectorGraphics library will help with the 2d geometry
needed to calculate collisions, trajectories, and translations.

I plan on adding extensions to this game as well. I plan an focusing a lot on the aesthetics of the game and will
focus a lot on color scheme. I will also create certain power-up bricks, so that when the certain bricks are 
eliminated, I will add temporary power-ups to the game such as double hit collisions.

## Library Documentation
- https://github.com/frauzufall/ofxGuiExtended
- https://github.com/lian/ofx-dev/tree/master/addons/ofxVectorGraphics
#include "ofMain.h"
#include "ofApp.h"

#define DISPLAY_MODE OF_WINDOW

//========================================================================
int main( ){
	ofSetupOpenGL(1000,800, DISPLAY_MODE);			// <-------- setup the GL context

	ofSetFrameRate(30); // An appropriate framerate that moves the snake at a good speed
						// Due to the simple nature of our objects rendering things this slow should not cause visual discomfort or lage

	// this kicks off the running of my app
	ofRunApp(new ofApp());

}

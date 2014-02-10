#pragma once

#include "ofMain.h"
#include "ofxFaceTracker.h"

class testApp : public ofBaseApp {
public:
	void setup();
	void update();
	void draw();
	void keyPressed(int key);
    string userInput;
	
	ofVideoGrabber cam;
	ofxFaceTracker tracker;
	ExpressionClassifier classifier;
    
    ofTrueTypeFont normalFont;
    ofTrueTypeFont angryFont;
    ofTrueTypeFont happyFont;
    
    ofColor normalColor;
    ofColor happyColor;
    ofColor angryColor;
    
    
    float normalValue=0;
    float angryValue=0;
    float happyValue=0;

};

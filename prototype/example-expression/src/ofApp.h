#pragma once

#include "ofMain.h"
#include "ofxFaceTrackerThreaded.h"
#include "ofxPulseSensor.h"
#include "emoWord.h"

#include "baseScene.h"

#include "startScene.h"
#include "calibrationScene1.h"
#include "calibrationScene2.h"
#include "calibrationScene3.h"
#include "chatScene.h"


class ofApp : public ofBaseApp {
public:
	void setup();
	void update();
	void draw();
	
    void keyPressed(int key);
	void keyReleased(int key);
    
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);

    
    //PulseSensor
    ofxPulseSensor  pSensor;

    //FaceTracker
	ofVideoGrabber cam;
	ofxFaceTrackerThreaded tracker;
	ExpressionClassifier classifier;
    
    //text input
    string userInput;
    
    int fontSize;
    int leading;
    
    //fonts
    vector<ofTrueTypeFont> fonts;
    
    //colors
    ofColor normalColor;
    ofColor happyColor;
    ofColor angryColor;
    
    //probs
    float normalValue=0;
    float angryValue=0;
    float happyValue=0;
    
    
    emoWord input;
    // currently typing word
    vector<emoWord> words;
    // all words those are finished typing
    
    int 				snapCounter;
    bool 				bSnapshot;
    ofImage             img;
    char 				snapString[255];
    
    
    
    
    //scene manager
    void changeScene (int newScene);
    int whichScene;
    int prevWhichScene;
    
    vector <baseScene * > scenes;
    baseScene * prevScene;
    
    
    //ui
    int buttonRadius;
    
};

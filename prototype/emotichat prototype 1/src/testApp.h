#pragma once

#include "ofMain.h"
#include "ofxFaceTrackerThreaded.h"
#include "Word.h"
#include "ofxPulseSensor.h"

class testApp : public ofBaseApp {
public:
    
    
    
	void setup();
	void update();
	void draw();
	void keyPressed(int key);
    void keyReleased(int key);


    string userInput;
	
	ofVideoGrabber cam;
	ofxFaceTrackerThreaded tracker;
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
    
    vector<ofTrueTypeFont> fonts;
    
    Word input; // <-- this is the word that the user is typing at any given time
    vector<Word> words; // <-- this is the list of words that the user has typed in the past.
    
    int 				snapCounter;
    bool 				bSnapshot;
    ofImage             img;
    char 				snapString[255];
    
    ofxPulseSensor  pSensor;
    

};

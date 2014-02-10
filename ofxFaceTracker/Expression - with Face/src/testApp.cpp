#include "testApp.h"

using namespace ofxCv;
using namespace cv;

void testApp::setup() {
	ofSetVerticalSync(true);
	cam.initGrabber(640, 480);
	
	tracker.setup();
	tracker.setRescale(.5);
    
    classifier.load("expressions");
    
    normalFont.loadFont("frabk.ttf", 20);
    normalColor = ofColor::white;
    
    
    angryFont.loadFont("angrybird.ttf", 40);
    angryColor = ofColor::red;
    
    happyFont.loadFont("frabk.ttf", 20);
    happyColor = ofColor::green;
    
}

void testApp::update() {
	cam.update();
	if(cam.isFrameNew()) {
		if(tracker.update(toCv(cam))) {
			classifier.classify(tracker);
		}		
	}
}

void testApp::draw() {
	ofSetColor(255);
    cam.draw(0, 0);
	tracker.draw();
	
	int w = 100, h = 12;
	ofPushStyle();
	ofPushMatrix();
	ofTranslate(5, 10);
	int n = classifier.size();
	int primary = classifier.getPrimaryExpression();
  for(int i = 0; i < n; i++){
		ofSetColor(i == primary ? ofColor::red : ofColor::black);
		ofRect(0, 0, w * classifier.getProbability(i) + .5, h);
      
      cout<< classifier.getProbability(i) << " " << i << endl;
      
      angryValue = classifier.getProbability(0);
      happyValue = classifier.getProbability(1);
      
      

		ofSetColor(255);
		ofDrawBitmapString(classifier.getDescription(i), 5, 9);
		ofTranslate(0, h + 5);
  }
	ofPopMatrix();
	ofPopStyle();
	
	ofDrawBitmapString(ofToString((int) ofGetFrameRate()), ofGetWidth() - 20, ofGetHeight() - 10);
	
    
//    
//    drawHighlightString(
//		string() +
//		"r - reset\n" +
//		"e - add expression\n" +
//		"a - add sample\n" +
//		"s - save expressions\n"
//		"l - load expressions",
//		14, ofGetHeight() - 7 * 12);
    
    
    // SHOW TEXT
    
    
    if(happyValue>0.5) {
        ofSetColor(happyColor);
        happyFont.drawString(userInput, 10, 120);
        
        
    }else if (angryValue>0.8) {
        ofSetColor(angryColor);
        angryFont.drawString(userInput, 10, 120);
        
    } else {
        ofSetColor(normalColor);
        normalFont.drawString(userInput, 10, 120);
    }
}



    void testApp::keyPressed(int key){

//
//	if(key == 'r') {
//		tracker.reset();
//		classifier.reset();
//	}
//	if(key == 'e') {
//		classifier.addExpression();
//	}
//	if(key == 'a') {
//		classifier.addSample(tracker);
//	}
//	if(key == 's') {
//		classifier.save("expressions");
//	}
//	if(key == 'l') {
//		classifier.load("expressions");
//	}
    
    
    if(key==OF_KEY_BACKSPACE) {
        // take a letter off of userInput
        if (userInput.size () > 0)
            userInput.resize (userInput.size () - 1);
    } else if(key==OF_KEY_RETURN) {
        userInput+="\n";
    } else {
        userInput+=(char)key;
    }

    
    }
#include "testApp.h"

#define FONT_SIZE 24
#define LEADING 50

using namespace ofxCv;
using namespace cv;

void testApp::setup() {
    
    ofBackground(130, 204, 186);
	ofSetVerticalSync(true);
	cam.initGrabber(640, 480);
	
	tracker.setup();
	tracker.setRescale(.5);
    
    classifier.load("expressions");
    
    //normalFont.loadFont("frabk.ttf", 20);
    normalColor = ofColor::white;
    
    
    //angryFont.loadFont("angrybird.ttf", 40);
    angryColor = ofColor::red;
    
    //happyFont.loadFont("frabk.ttf", 20);
    happyColor = ofColor::yellow;
    
    string fontfiles[3] =
        {"frabk.ttf",
        "angrybird.ttf",
        "Happy Sans.ttf"
    };
    for(int i=0; i<3; i++) {
        ofTrueTypeFont font;
        font.loadFont(fontfiles[i], FONT_SIZE);
        fonts.push_back(font);
    }
    
    bSnapshot = false;
    
    
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
    ofPushMatrix();
    ofTranslate(10, 10);
    ofScale(0.5, 0.5);
    cam.draw(0, 0);
    tracker.draw();
    ofPopMatrix();
	
	int w = 100, h = 12;
	ofPushStyle();
	ofPushMatrix();
	ofTranslate(350, 10);
	int n = classifier.size();
	int primary = classifier.getPrimaryExpression();
    for(int i = 0; i < n; i++){
       
        ofSetColor(i == primary ? ofColor::teal: ofColor::teal);
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
	
    ofPushMatrix();
    ofTranslate(0, 230);
    ofPoint pos(10, LEADING);
    for(int i=0; i<words.size(); i++)
    {
        if (pos.x+words[i].getWidth() > ofGetWidth()) {
            pos.x = 10;
            pos.y += LEADING;
        }
        words[i].draw(pos);
        pos.x += words[i].getWidth();
    }
    
    // Draw the word that the user is currently typing
    input.draw(pos);
    
        if (bSnapshot == true){
    		// grab a rectangle at 200,200, width and height of 300,180
            img.grabScreen(0,0,640, 480);
    
    		string fileName = "snapshot_"+ofToString(10000+snapCounter)+".png";
    		img.saveImage(fileName);
    		sprintf(snapString, "saved %s", fileName.c_str());
    		snapCounter++;
    		bSnapshot = false;
    	}
    
    ofPopMatrix();
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
//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
    
    // If the user hits space, add it to the list of typed words
    if (key == OF_KEY_DOWN){
		bSnapshot = true;
	}
    
    if(key==' ')
    {
        words.push_back(input);
        
        // Reset the user input word
        //int n = ofRandom(fonts.size());
        //input.font = fonts[n];
        input.word = "";
        //input.color.setHsb(ofRandom(255), 255, 255);
        
    }
    else if (key==OF_KEY_BACKSPACE)
    {
        // If the user hits backspace, we either have to delete a letter from "input",
        // or go back to the previous word.
        if(input.word.length()==0) {
            input = words.back();
            words.pop_back();
        } else {
            input.word = input.word.substr(0, input.word.size()-1);
        }
        
    }
    else
    {
        // For all other keys, just add a letter to the input word
        if(happyValue>0.5) {
            input.font = fonts[2];
            input.word += (char)key;
            input.color = happyColor;
            
        }else if (angryValue>0.8) {
            input.font = fonts[1];
            input.word += (char)key;
            input.color = angryColor;
            //            input.shake = ofRandomf() * 5;
        }
        else{
            input.font = fonts[0];
            input.word += (char)key;
            input.color = normalColor;
        }
        
        
    }
    
}
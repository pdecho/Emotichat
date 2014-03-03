//
//  calibrationScene1.cpp
//  ofApp
//
//  Created by Firm Read on 3/2/14.
//
//

#include "calibrationScene1.h"
#include "ofApp.h"


void calibrationScene1::setup(){
    okayPos.set(600, 300);
    cancelPos.set(300, 300);
    
}


void calibrationScene1::update(){
    
    
}

void calibrationScene1::draw(){
    
    //draw face video
	ofSetColor(255);
    ofPushMatrix();
    ofTranslate(10, 10);
    ofScale(0.5, 0.5);
    ((ofApp*)ofGetAppPtr())->cam.draw(0, 0);
    ((ofApp*)ofGetAppPtr())->tracker.draw();
    ofPopMatrix();
	
    //draw probs
	int w = 100, h = 12;
	ofPushStyle();
	ofPushMatrix();
	ofTranslate(350, 10);
	int n = ((ofApp*)ofGetAppPtr())->classifier.size();
	int primary = ((ofApp*)ofGetAppPtr())->classifier.getPrimaryExpression();
    
    for(int i = 0; i < n; i++){
		ofSetColor(i == primary ? ofColor::teal : ofColor::teal);
		ofRect(0, 0, w * ((ofApp*)ofGetAppPtr())->classifier.getProbability(i) + .5, h);
        
        ((ofApp*)ofGetAppPtr())->angryValue = ((ofApp*)ofGetAppPtr())->classifier.getProbability(0);
        ((ofApp*)ofGetAppPtr())->happyValue = ((ofApp*)ofGetAppPtr())->classifier.getProbability(1);
        
		ofSetColor(255);
		ofDrawBitmapString(((ofApp*)ofGetAppPtr())->classifier.getDescription(i), 5, 9);
		ofTranslate(0, h + 5);
    }
    
	ofPopMatrix();
	ofPopStyle();
    
    
    
    
    ofDrawBitmapStringHighlight("Smile and click",
                                ofGetWidth()/2, ofGetHeight()/2);
    
    ofPushStyle();
    ofSetColor(255);
        
    ofCircle(okayPos, ((ofApp*)ofGetAppPtr())->buttonRadius);
    ofCircle(cancelPos, ((ofApp*)ofGetAppPtr())->buttonRadius);
    ofPopStyle();
    
    ofDrawBitmapStringHighlight("next", okayPos);
    ofDrawBitmapStringHighlight("reset", cancelPos);
    
    
    
    
}




void calibrationScene1::keyPressed(int key){}
void calibrationScene1::keyReleased(int key){}

void calibrationScene1::mouseMoved(int x, int y ){};
void calibrationScene1::mouseDragged(int x, int y, int button){}
void calibrationScene1::mousePressed(int x, int y, int button){
    ofPoint mouseIn(x,y);
    
    if (okayPos.distance(mouseIn) < ((ofApp*)ofGetAppPtr())->buttonRadius){
        ((ofApp*)ofGetAppPtr())->whichScene = 2;
        
        ((ofApp*)ofGetAppPtr())->classifier.addExpression("smile");
        ((ofApp*)ofGetAppPtr())->classifier.addSample(((ofApp*)ofGetAppPtr())->tracker);
        //		((ofApp*)ofGetAppPtr())->classifier.save("expressions");
    }
    
    if (cancelPos.distance(mouseIn) < ((ofApp*)ofGetAppPtr())->buttonRadius) {
        ((ofApp*)ofGetAppPtr())->whichScene = 0;
        ((ofApp*)ofGetAppPtr())->tracker.reset();
        ((ofApp*)ofGetAppPtr())->classifier.reset();
    }
    

    
}
void calibrationScene1::mouseReleased(int x, int y, int button){}


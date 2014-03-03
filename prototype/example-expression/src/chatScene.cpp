//
//  chatScene.cpp
//  ofApp
//
//  Created by Firm Read on 3/2/14.
//
//

#include "chatScene.h"
#include "ofApp.h"


void chatScene::setup(){
    resetPos.set(600,300);
}


void chatScene::update(){
    
    
}

void chatScene::draw(){
    
    //draw pulse graph
    ((ofApp*)ofGetAppPtr())->pSensor.draw();
    
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
	
    //print framerate
	ofDrawBitmapString("framerate" + ofToString((int) ofGetFrameRate()),
                       ofGetWidth() - 250,
                       ofGetHeight() - 10);
    
    //	drawHighlightString(
    //		string() +
    //		"r - reset\n" +
    //		"e - add expression\n" +
    //		"a - add sample\n" +
    //		"s - save expressions\n"
    //		"l - load expressions",
    //		14, ofGetHeight() - 7 * 12);
    
    
    //draw chat fonts
    ofPushMatrix();
    ofTranslate(0, 230);
    ofPoint pos(10, ((ofApp*)ofGetAppPtr())->leading);
    // draw previous words
    if (((ofApp*)ofGetAppPtr())->words.size()> 0) {
        for(int i=0; i<((ofApp*)ofGetAppPtr())->words.size(); i++)
        {
            if (pos.x+((ofApp*)ofGetAppPtr())->words[i].getWidth() > ofGetWidth()) {
                pos.x = 10;
                pos.y += ((ofApp*)ofGetAppPtr())->leading;
            }
            ((ofApp*)ofGetAppPtr())->words[i].draw(pos);
            pos.x += ((ofApp*)ofGetAppPtr())->words[i].getWidth();
        }
    }
    
    // draw currently typing word
    if (((ofApp*)ofGetAppPtr())->input.word.length() != 0){
        ((ofApp*)ofGetAppPtr())->input.draw(pos);
        cout << " i know i know " << endl;
    }
    
    // save snapshot
    if (((ofApp*)ofGetAppPtr())->bSnapshot == true){
        // grab a rectangle at 200,200, width and height of 300,180
        ((ofApp*)ofGetAppPtr())->img.grabScreen(0,0,640, 480);
        
        string fileName = "snapshot_"+ofToString(10000+((ofApp*)ofGetAppPtr())->snapCounter)+".png";
        ((ofApp*)ofGetAppPtr())->img.saveImage(fileName);
        sprintf(((ofApp*)ofGetAppPtr())->snapString, "saved %s", fileName.c_str());
        ((ofApp*)ofGetAppPtr())->snapCounter++;
        ((ofApp*)ofGetAppPtr())->bSnapshot = false;
    }
    
    ofPopMatrix();
    
    
    ofCircle(resetPos, ((ofApp*)ofGetAppPtr())->buttonRadius);
    
    
}




void chatScene::keyPressed(int key){
    cout << "presseeedddddd" << endl;
    if(key==OF_KEY_BACKSPACE) {
        // take a letter off of userInput
        if (((ofApp*)ofGetAppPtr())->userInput.size () > 0)
            ((ofApp*)ofGetAppPtr())->userInput.resize (((ofApp*)ofGetAppPtr())->userInput.size () - 1);
    } else if(key==OF_KEY_RETURN) {
        ((ofApp*)ofGetAppPtr())->userInput+="\n";
    } else {
        ((ofApp*)ofGetAppPtr())->userInput+=(char)key;
    }
}
void chatScene::keyReleased(int key){
    // If the user hits space, add it to the list of typed words
    if (key == OF_KEY_DOWN){
		((ofApp*)ofGetAppPtr())->bSnapshot = true;
	}
    
    if(key==' ')
    {
        ((ofApp*)ofGetAppPtr())->input.shake = ofMap(((ofApp*)ofGetAppPtr())->pSensor.BPM, 60, 130, 0.0, 3.0, true);
        ((ofApp*)ofGetAppPtr())->words.push_back(((ofApp*)ofGetAppPtr())->input);
        
        // Reset the user input word
        //int n = ofRandom(fonts.size());
        //input.font = fonts[n];
        ((ofApp*)ofGetAppPtr())->input.word = "";
        //input.color.setHsb(ofRandom(255), 255, 255);
        
    }
    else if (key==OF_KEY_BACKSPACE)
    {
        // If the user hits backspace, we either have to delete a letter from "input",
        // or go back to the previous word.
        if(((ofApp*)ofGetAppPtr())->input.word.length()==0) {
            ((ofApp*)ofGetAppPtr())->input = ((ofApp*)ofGetAppPtr())->words.back();
            ((ofApp*)ofGetAppPtr())->words.pop_back();
        } else {
            ((ofApp*)ofGetAppPtr())->input.word = ((ofApp*)ofGetAppPtr())->input.word.substr(0, ((ofApp*)ofGetAppPtr())->input.word.size()-1);
        }
        
    }
    else
    {
        // For all other keys, just add a letter to the input word
        if(((ofApp*)ofGetAppPtr())->happyValue>0.5) {
            ((ofApp*)ofGetAppPtr())->input.font = ((ofApp*)ofGetAppPtr())->fonts[2];
            ((ofApp*)ofGetAppPtr())->input.word += (char)key;
            ((ofApp*)ofGetAppPtr())->input.color = ((ofApp*)ofGetAppPtr())->happyColor;
//            cout << "happy" <<endl;
            
        }else if (((ofApp*)ofGetAppPtr())->angryValue>0.8) {
            ((ofApp*)ofGetAppPtr())->input.font = ((ofApp*)ofGetAppPtr())->fonts[1];
            ((ofApp*)ofGetAppPtr())->input.word += (char)key;
            ((ofApp*)ofGetAppPtr())->input.color = ((ofApp*)ofGetAppPtr())->angryColor;
            //            input.shake = ofRandomf() * 5;
//            cout << "angry" << endl;
        }
        else{
            ((ofApp*)ofGetAppPtr())->input.font = ((ofApp*)ofGetAppPtr())->fonts[0];
            ((ofApp*)ofGetAppPtr())->input.word += (char)key;
            ((ofApp*)ofGetAppPtr())->input.color = ((ofApp*)ofGetAppPtr())->normalColor;
//            cout << "anafjl;ajfawoif" << endl;
        }
        
        
    }
}

void chatScene::mouseMoved(int x, int y ){};
void chatScene::mouseDragged(int x, int y, int button){}
void chatScene::mousePressed(int x, int y, int button){
    
    ofPoint mouseIn(x,y);
    if (resetPos.distance(mouseIn) < ((ofApp*)ofGetAppPtr())->buttonRadius){
        ((ofApp*)ofGetAppPtr())->whichScene = 0;
        
		((ofApp*)ofGetAppPtr())->tracker.reset();
		((ofApp*)ofGetAppPtr())->classifier.reset();
    }
 
}
void chatScene::mouseReleased(int x, int y, int button){}



//
//  startScene.cpp
//  ofApp
//
//  Created by Firm Read on 3/2/14.
//
//

#include "startScene.h"
#include "ofApp.h"


void startScene::setup(){
    logo.loadImage("images/logo.png");
    okayPos.set(600, 300);
}


void startScene::update(){
    
    
}

void startScene::draw(){
    ofSetRectMode(OF_RECTMODE_CENTER);
    logo.draw(ofGetWidth()/2, ofGetHeight()/2, 200, 200);
    ofSetRectMode(OF_RECTMODE_CORNER);
    ofDrawBitmapStringHighlight("Emotichat", ofGetWidth()/2, ofGetHeight()/2+300);
    
    
    ofPushStyle();
    ofSetColor(255);
    ofCircle(okayPos, ((ofApp*)ofGetAppPtr())->buttonRadius);
    ofPopStyle();
    
    ofDrawBitmapStringHighlight("next", okayPos);
}




void startScene::keyPressed(int key){};
void startScene::keyReleased(int key){};

void startScene::mouseMoved(int x, int y ){};
void startScene::mouseDragged(int x, int y, int button){};
void startScene::mousePressed(int x, int y, int button){
    //got to next scene
//    ((testApp *)ofGetAppPtr()) -> changePage( 6);
    
    ofPoint mouseIn(x,y);
    if (okayPos.distance(mouseIn) < ((ofApp*)ofGetAppPtr())->buttonRadius){
        ((ofApp*)ofGetAppPtr())->whichScene = 1;
        cout<< "happening" << endl;
    }
    


};
void startScene::mouseReleased(int x, int y, int button){};

//
//  calibrationScene1.h
//  ofApp
//
//  Created by Firm Read on 3/2/14.
//
//

#ifndef __ofApp__calibrationScene1__
#define __ofApp__calibrationScene1__

#include <iostream>
#include "ofMain.h"
#include "baseScene.h"

class calibrationScene1 : public baseScene {
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
    
    
    ofPoint okayPos, cancelPos;
};

#endif /* defined(__ofApp__calibrationScene1__) */

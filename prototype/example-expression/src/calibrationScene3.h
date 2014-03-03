//
//  calibrationScene3.h
//  ofApp
//
//  Created by Firm Read on 3/2/14.
//
//

#ifndef __ofApp__calibrationScene3__
#define __ofApp__calibrationScene3__

#include <iostream>
#include "ofMain.h"
#include "baseScene.h"

class calibrationScene3 : public baseScene {
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

#endif /* defined(__ofApp__calibrationScene3__) */

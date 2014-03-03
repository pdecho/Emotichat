//
//  startScene.h
//  ofApp
//
//  Created by Firm Read on 3/2/14.
//
//

#ifndef __ofApp__startScene__
#define __ofApp__startScene__

#include <iostream>
#include "ofMain.h"
#include "baseScene.h"

class startScene : public baseScene {
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

    ofImage logo;
    ofPoint okayPos;
    
    
};


#endif /* defined(__ofApp__startScene__) */

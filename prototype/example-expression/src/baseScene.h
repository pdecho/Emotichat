//
//  baseScene.h
//  ofApp
//
//  Created by Firm Read on 3/2/14.
//
//

#ifndef __ofApp__baseScene__
#define __ofApp__baseScene__

#include <iostream>

#include "ofMain.h"

class baseScene {
public:
    
    virtual void setup(){};
    virtual void update(){};
    virtual void draw(){};
    
    virtual void keyPressed(int key){};
    virtual void keyReleased(int key){}
    
    virtual void mouseMoved(int x, int y){};
    virtual void mouseDragged(int x, int y, int button){};
    virtual void mousePressed(int x, int y, int button){};
    virtual void mouseReleased(int x, int y, int button){};
    
};


#endif /* defined(__ofApp__baseScene__) */

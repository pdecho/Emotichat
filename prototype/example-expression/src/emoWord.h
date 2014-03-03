
#pragma once
#include "ofMain.h"

class emoWord {
public:
    
    
    
    float shake;
    ofColor color;
    string word;
    ofTrueTypeFont font;
    
    
    
    void draw(ofPoint pos) {
        
        ofPushStyle();
        ofSetColor(color);
        font.drawString(word, pos.x+ofRandom(-shake, shake), pos.y+ofRandom(-shake, shake));
        ofPopStyle();
    }
    
    
    
    
    float getWidth() {
        return font.getStringBoundingBox(word, 0, 0).width + (font.getSize() * 0.5);
    }
    
};
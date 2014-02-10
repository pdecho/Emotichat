//
//  Word.h
//  WordStyle
//
//  Created by Jeffrey Crouse on 11/23/13.
//
//

#pragma once
#include "ofMain.h"

class Word {
public:
    void draw(ofPoint pos) {
        
        ofPushStyle();
        ofSetColor(color);
        font.drawString(word, pos.x+ofRandom(-shake, shake), pos.y+ofRandom(-shake, shake));
        ofPopStyle();
    }
    float getWidth() {
        return font.getStringBoundingBox(word, 0, 0).width + (font.getSize() * 0.5);
    }
    
    float shake;
    ofColor color;
    string word;
    ofTrueTypeFont font;
};
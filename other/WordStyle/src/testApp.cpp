#include "testApp.h"

#define FONT_SIZE 48
#define LEADING 60

//--------------------------------------------------------------
void testApp::setup(){
    
    string fontfiles[8] = {
        "fonts/Dreamer.ttf",
        "fonts/FantasticParty.ttf",
        "fonts/Google-spies PERSONNAL USE ONLY.ttf",
        "fonts/Kimmun.ttf",
        "fonts/Opificio-Serif-regular.ttf",
        "fonts/Royal Delight.ttf",
        "fonts/soft_lines_7.ttf",
        "fonts/StoneBird.ttf" };
    for(int i=0; i<8; i++) {
        ofTrueTypeFont font;
        font.loadFont(fontfiles[i], FONT_SIZE);
        fonts.push_back(font);
    }
    
    int n = ofRandom(fonts.size());
    input.font = fonts[n];
    input.word = "";
    input.color.setHsb(ofRandom(255), 255, 255);
    input.shake = ofRandomf() * 5;
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    
    // Draw all of the words.  Keep track of where on the screen we are
    // so we make sure to drop to the next line if necessary.
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
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
    
    // If the user hits space, add it to the list of typed words
    if(key==' ')
    {
        words.push_back(input);

        // Reset the user input word
        int n = ofRandom(fonts.size());
        input.font = fonts[n];
        input.word = "";
        input.color.setHsb(ofRandom(255), 255, 255);
        input.shake = ofRandomf() * 5;
        
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
        input.word += (char)key;
    }
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}

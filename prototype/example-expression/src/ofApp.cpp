#include "ofApp.h"

using namespace ofxCv;
using namespace cv;

//--------------------------------------------------------------

void ofApp::setup() {
	ofSetVerticalSync(true);
	cam.initGrabber(640, 480);
    ofSetCircleResolution(100);
	
	tracker.setup();
	tracker.setRescale(.5);
    
    ofBackground(130, 204, 186);
    
//    classifier.load("expressions");
    
    
    normalColor = ofColor::white;
    angryColor = ofColor::red;
    happyColor = ofColor::yellow;

    //0
    scenes.push_back(new startScene() );
    //1
    scenes.push_back(new calibrationScene1() );
    //2
    scenes.push_back(new calibrationScene2() );
    //3
    scenes.push_back(new calibrationScene3() );
    //4
    scenes.push_back(new chatScene() );

    
    for (int i = 0; i < scenes.size(); i++) {
        scenes[i]->setup();
    }
    
    string fontfiles[3] =
    {
        "fonts/frabk.ttf",
        "fonts/angrybird.ttf",
        "fonts/Happy Sans.ttf"
    };
    

    for(int i=0; i<3; i++) {
        ofTrueTypeFont font;
        font.loadFont(fontfiles[i], fontSize);
        fonts.push_back(font);
    }
    
    
    bSnapshot = false;
    pSensor.setup();
    
    fontSize = 24;
    leading = 50;
    
    ofBackground(130, 204, 186);
    buttonRadius = 60;
    whichScene = 0;
    
}

//--------------------------------------------------------------

void ofApp::update() {
    
    scenes[whichScene]->update();
    
	cam.update();
	if(cam.isFrameNew()) {
		if(tracker.update(toCv(cam))) {
			classifier.classify(tracker);
		}		
	}
    pSensor.update();
}

//--------------------------------------------------------------

void ofApp::draw() {
    
    scenes[whichScene]->draw();

}

//--------------------------------------------------------------

void ofApp::keyPressed(int key) {
    
    scenes[whichScene]->keyPressed(key);
    
}

//--------------------------------------------------------------

void ofApp::keyReleased(int key){
    
    scenes[whichScene]->keyReleased(key);
        
}



//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
    
    scenes[whichScene]->mouseMoved(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
    scenes[whichScene]->mouseDragged(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
    scenes[whichScene]->mousePressed(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
    scenes[whichScene]->mouseReleased(x, y, button);
}

//--------------------------------------------------------------

void ofApp::changeScene(int newScene){
    whichScene = newScene;
    
    if (prevWhichScene != whichScene) {
        prevScene = scenes[prevWhichScene];
    }
}



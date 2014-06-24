#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    fc = 0.05;
    
    filterHighPass.setType(OFX_BIQUAD_TYPE_HIGHPASS);
}

//--------------------------------------------------------------
void ofApp::update(){
    filterLowPass.setFc(fc);
    filterHighPass.setFc(fc);
    
    //Update the filter with the mouse movement
    filterLowPass.update(ofVec2f(mouseX,mouseY));
    filterHighPass.update(ofVec2f(mouseX,mouseY));
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackgroundGradient(ofColor(20), ofColor(40));
    
    //Input value
    ofSetColor(255, 255, 255,100);
    ofCircle(mouseX, mouseY, 40);
    
    
    //High pass value
    ofSetColor(30,30,255,100);
    ofPushMatrix();
    ofTranslate(ofGetWidth()*0.5, ofGetHeight()*0.5);
    ofCircle(filterHighPass.value().x, filterHighPass.value().y, 30);
    ofPopMatrix();

    
    // Low pass value
    ofSetColor(255,30,30,100);
    ofCircle(filterLowPass.value().x, filterLowPass.value().y, 30);
    
    ofSetColor(255, 255, 255);
    ofDrawBitmapString("FC: "+ofToString(fc)+" (up/down arrow to change)", ofPoint(10,20));
    
    ofDrawBitmapString("Input value", ofPoint(10,40));
    ofSetColor(255,30,30);
    ofDrawBitmapString("Lowpass value", ofPoint(10,50));
    ofSetColor(30,30,255);
    ofDrawBitmapString("Highpass value", ofPoint(10,60));

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == OF_KEY_UP){
        fc += 0.01;
    }
    if(key == OF_KEY_DOWN){
        fc -= 0.01;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

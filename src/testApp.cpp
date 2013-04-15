#include "testApp.h"
#include "biquad.h"
//--------------------------------------------------------------

//Biquad FilterX(bq_type_lowpass,0.01,0.7,0.0);
//Biquad FilterY(bq_type_lowpass,0.01,0.7,0.0);

float fc=0.01;
float Q=0.7;
float type=bq_type_lowpass;
Biquad FilterX(bq_type_bandpass,0.001,0.7,0.0);
Biquad FilterY(bq_type_bandpass,0.001,0.7,0.0);

//Biquad FilterNoise(bq_type_highpass,0.01,0.7,0.0);



void testApp::setup()
{
    ofBackground(1);
    ofEnableAlphaBlending();
    ofSetBackgroundAuto(false);
}

//--------------------------------------------------------------
void testApp::update()
{


//    FilterX.setFc((float)ofGetMouseX()/((float)ofGetWidth()*5));
//    FilterY.setFc((float)ofGetMouseX()/((float)ofGetWidth()*5));

}

//--------------------------------------------------------------
void testApp::draw(){

    glColor4f(0,0,0,0.01);
    ofRect(0,0,ofGetWidth(),ofGetHeight());
    ofTranslate(ofGetWidth()/2,ofGetHeight()/2  );

    double px=ofGetMouseX()-ofGetWidth()/2+ofRandom(-50,50);
    double py=ofGetMouseY()-ofGetHeight()/2+ofRandom(-50,50);

//    double px=ofGetMouseX()-ofGetWidth()/2;
//    double py=ofGetMouseY()-ofGetHeight()/2;
    ofSetColor(255,255,255,180);
    ofEllipse(px,py,50,50);

    ofSetColor(255,0,0,255);
    ofEllipse(FilterX.process(px),FilterY.process(py),50,50);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key)
{

    if(key=='+')
    {
        fc*=1.01;
    FilterX.setFc(fc);
    FilterY.setFc(fc);

        cout << fc << '\n';
    }

    if(key=='-')
    {
        fc*=0.99;
    FilterX.setFc(fc);
    FilterY.setFc(fc);

        cout << fc << '\n';
    }

    if(key=='a')
    {
        Q*=1.01;
    FilterX.setQ(Q);
    FilterY.setQ(Q);
        cout << Q << '\n';
    }

    if(key=='z')
    {
        Q*=0.99;
    FilterX.setQ(Q);
    FilterY.setQ(Q);
        cout << Q << '\n';
    }


    if(key=='f')
    {
        type++;
        if(type==bq_type_notch)
            type=bq_type_lowpass;
        FilterX.setType(type);
        FilterY.setType(type);
        cout << type << '\n';
    }


}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

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

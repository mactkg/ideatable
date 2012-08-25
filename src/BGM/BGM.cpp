#include "BGM.h"
BGM::BGM(ofxTuioObject * _blob):ofxTuioObject(_blob) {
    vol=0.5;
    playtime=0.0;
}

BGM::~BGM(){
}

void BGM::draw() {
    glPushMatrix();
    glTranslatef(this->getX()*ofGetWidth(),this->getY()*ofGetHeight(),0.0);
    glRotatef(this->getAngleDegrees(),0.0,1,0);
    ofFill();
    ofSetColor(0,0,120+playtime*200,130);
    ofCircle(0.0,0.0,spectrum*30.0*100);
    glPopMatrix();
}

void BGM::update(ofxTuioObject * _tuioObject) {
    ofxTuioObject::update(_tuioObject);
    vol=_tuioObject->getAngle()/(2.0*3.141592653589793238);
}

bool BGM::isRange(ofxTuioCursor * _cursor){
    return false;
}

bool BGM::isActionRange(ofxTuioCursor * _cursor){
    return false;
}

void BGM::touchAction(ofxTuioCursor * _cursor){
}

float BGM::getVolume(){
    return vol;
}

void BGM::setSpectrum(float * _spectrum){
    spectrum=_spectrum[0];
}

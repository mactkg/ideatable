#include "sample.h"
Sample::Sample(ofxTuioObject * _blob):ofxTuioObject(_blob) {
    default_angle=_blob->getAngle();
    radius=30;
}

void Sample::draw() {
    ofSetColor(0,130,130);
    glPushMatrix();
    glTranslatef(this->getX()*ofGetWidth(),
                 this->getY()*ofGetHeight(),
                 0.0);
    ofCircle(0,0,radius);
    glPopMatrix();
}

void Sample::update(ofxTuioObject * _tuioObject) {
    ofxTuioObject::update(_tuioObject);
    radius=5+abs(this->angle*5);
}


bool Sample::isInRange(ofxTuioCursor * _cursor) {
    return false;
}

bool Sample::isInRange(fingerCursor *_cursor){
    return false;
}

void Sample::touchAction(fingerCursor * _cursor){
}

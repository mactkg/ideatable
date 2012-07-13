#include "sample.h"
Sample::Sample(ofxTuioObject * _blob):ofxTuioObject(_blob) {
    default_angle=_blob->getAngle();
    r=(float)ofRandom(256);
    g=(float)ofRandom(256);
    b=(float)ofRandom(256);
}

void Sample::draw() {
    ofSetColor(r,g,b);
    glPushMatrix();
    glTranslatef(this->getX()*ofGetWidth(),
                 this->getY()*ofGetHeight(),
                 0.0);
    ofCircle(0,0,30);
    ofRect(30,-30,15,15);
    glPopMatrix();
}

void Sample::update(ofxTuioObject * _tuioObject) {
    ofxTuioObject::update(_tuioObject);
}


bool Sample::isInRange(ofxTuioCursor * _cursor) {
    if(sumdist(_cursor->getX(),_cursor->getY()<30.0))return true;
    return false;
}

void Sample::touchAction(ofxTuioCursor * _cursor){
    
}

float Sample::sumdist(float x,float y){
    return sqrt(pow(x*ofGetWidth()-this->xpos*ofGetWidth(),2)
                    +pow(y*ofGetHeight()-this->ypos*ofGetHeight(),2));
}

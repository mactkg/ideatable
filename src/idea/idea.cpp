#include "idea.h"

Idea::Idea(ofxTuioObject * o):ofxTuioObject(o) {
    radius=IDEA_DEFAULT_RADIUS;
}

Idea::Idea(){}

Idea::~Idea(){}

void Idea::draw(){
    glPushMatrix();
    glTranslatef(this->getX()*ofGetWidth()
                 ,this->getY()*ofGetHeight(),0.0);
    glRotatef(this->getAngleDegrees(),1.0,1.0,0.0);
    ofFill();
    ofSetColor(0,100,200);
    ofCircle(0,0,radius);
    ofSetColor(255,255,255);
    ofDrawBitmapString(ofToString(this->getFiducialId()),20,20);
    glPopMatrix();
}

void Idea::update(ofxTuioObject * o){
    ofxTuioObject::update(o);
    return;
}

bool Idea::isRange(ofxTuioCursor * cursor){
    return false;
}

bool Idea::isActionRange(ofxTuioCursor * cursor){
    return false;
}

void Idea::touchAction(ofxTuioCursor * cursor){

}

#include "sample.h"
Sample::Sample(ofxTuioObject * _blob):ofxTuioObject(_blob)
{
    default_angle=_blob->getAngle();
    radius=30;
}

Sample::Sample()
{
}

void Sample::draw()
{
    ofSetColor(255,130,0);
    glPushMatrix();
    glTranslatef(this->getX()*ofGetWidth(),
                 this->getY()*ofGetHeight(),
                 0.0);
    ofCircle(0,0,radius);
    glPopMatrix();
}

void Sample::update(ofxTuioObject * _tuioObject)
{
    ofxTuioObject::update(_tuioObject);
    radius=5+abs(this->angle*5);
}

void Sample::destroy()
{
}

void Sample::isRange(ofxTuioCursor * _tuioCursor)
{
}

#include "line.h"

objLine::objLine(ofxTuioObject * _object, ofxTuioCursor * _cursor) {
    tp.update(_cursor);
    from.update(_object);
    isEnd=false;
}

void objLine::draw() {
    if(isEnd==false)
        ofLine(from.getX()*ofGetWidth(),
               from.getY()*ofGetHeight(),
               tp.getX()*ofGetWidth(),
               tp.getY()*ofGetHeight());
    else
        ofLine(from.getX()*ofGetWidth(),
               from.getY()*ofGetHeight(),
               to.getX()*ofGetWidth(),
               to.getY()*ofGetHeight()
              );
}

void objLine::update(ofxTuioCursor * _cursor) {
    tp.update(_cursor);
}

void objLine::update(ofxTuioObject * _object) {
    if((*_object).getFiducialId()==from.getFiducialId()) {
        from.update(_object);
    } else if((*_object).getFiducialId()==to.getFiducialId()) {
        to.update(_object);
    }
}

void objLine::update(ofxTuioObject * _object, ofxTuioCursor *_cursor) {
    tp.update(_cursor);
    from.update(_object);
}

void objLine::lineEnd(ofxTuioObject * _object) {
    to.update(_object);
    isEnd=true;
}

int objLine::getCursorID() {
    if(isEnd==false)
        return tp.getFingerId();
    else
        return -1;
}

int objLine::getFromID() {
    return from.getFiducialId();
}

int objLine::getToID() {
    if(isEnd==true)
        return to.getFiducialId();
    else
        return -1;
}
bool touchAction(ofxTuioCursor * _cursor) {
}

#include "line.h"

line::line(ofxTuioObject * _object, ofxTuioCursor * _cursor){
    tp=*_cursor;
    from=*_object;
    isEnd=false;
}

void line::draw(){
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

void line::update(ofxTuioCursor * _cursor){
    tp.update(_cursor);
}

void line::update(ofxTuioObject * _object){
    if((*_object).getFiducialId()==from.getFiducialId()){
        from.update(_object);
    }else if((*_object).getFiducialId()==to.getFiducialId()){
        to.update(_object);
    }
}

void line::update(ofxTuioObject * _object, ofxTuioCursor *_cursor){
    tp.update(_cursor);
    from.update(_object);
}

void line::lineEnd(ofxTuioObject * _object){
    to.update(_object);
    isEnd=true;
}

int line::getCursorID(){
    if(isEnd==false)
        return tp.getFingerId();
    else 
        return -1;
}

int line::getfromID(){
    return from.getFiducialId();
}

int line::getToID(){
    if(isEnd==true)
        return to.getFiducialId();
    else
        return -1;
}



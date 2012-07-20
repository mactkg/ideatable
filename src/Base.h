#pragma once
#include "index.h"
#include "ofxTuio.h"
class Base {
private:
    //以下にオブジェクトを追加
    Sample sample;
    int index;
    int FID;
    float x,y;
public:
    Base(ofxTuioObject * _tuioObject);
    Base(){};
    ~Base(){};
    int getFiducialId();
    float getX();
    float getY();

    void draw();
    void update(ofxTuioObject * _tuioObject);
    bool isActionRange(ofxTuioCursor * _tuioCursor);
    bool isRange(ofxTuioCursor * _tuioCursor);
    void touchAction(ofxTuioCursor * _cursor);
    void destroy();
    ofxTuioObject getObject();
};

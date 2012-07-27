#pragma once
#include "index.h"
#include "ofxTuio.h"
class Base {
private:
    ofxTuioObject o;
    //以下にオブジェクトを追加
    Sample sample;
    PictureObj picture;
    BGM bgm;
    int index;
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
    ofxTuioObject getObject();
};

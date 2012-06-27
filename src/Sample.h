#pragma once
#include "ofxTuio.h"
#include "ofMain.h"
#include "fingerCursor.h"
#define SAMPLE_NUM 5
class Sample : public ofxTuioObject {
private:
    float default_angle;
    float radius;
public:
    Sample(ofxTuioObject * _blob);
    Sample() {};
    ~Sample() {};
    void draw();
    void update(ofxTuioObject * _blob);
    bool isInRange(ofxTuioCursor * _cursor);
    bool isInRange(fingerCursor * _cursor);
    void touchAction(ofxTuioCursor * _cursor);
};


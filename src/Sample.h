#pragma once
#include "ofxTuio.h"
#include "ofMain.h"
#define SAMPLE_NUM 5
class Sample : public ofxTuioObject {
private:
    float default_angle,radius;
    int r,g,b;
public:
    Sample(ofxTuioObject * _blob);
    Sample() {};
    ~Sample() {};
    void draw();
    void update(ofxTuioObject * _blob);
    bool isInRange(ofxTuioCursor * _cursor);
    void touchAction(ofxTuioCursor * _cursor);
    float sumdist(float x,float y);
};


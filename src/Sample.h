#pragma once
#include "ofxTuio.h"
#include "ofMain.h"
#define SAMPLE_NUM 5
class Sample : public ofxTuioObject{
    private:
        float default_angle;
        float radius;
    public:
        Sample(ofxTuioObject * _blob);
        Sample();
        void draw();
        void update(ofxTuioObject * _blob);
        void destroy();
        void touchAction(ofxTuioCursor * _cursor);
};


#pragma once
#ifndef PICTURE_H_INCLUDED
#define PICTURE_H_INCLUDED
#include "ofxTuio.h"
#include "ofMain.h"
#include "string.h"
#include <iostream>

class PictureObj : public ofxTuioObject
{
private:
    float sizeX,sizeY;
    ofImage image;
    void setConfig(int fiducialId);
public:
    PictureObj() {};
    ~PictureObj() {};
    PictureObj(ofxTuioObject * _object);
    void draw();
    void update(ofxTuioObject * _object);
    void touch(ofxTuioCursor * _cursor);
};



#endif // PICTURE_H_INCLUDED

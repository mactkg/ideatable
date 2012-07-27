#pragma once
#ifndef PICTURE_H_INCLUDED
#define PICTURE_H_INCLUDED
#include "ofxTuio.h"
#include "../Util/Utility.h"
#include "ofMain.h"
#include <string>
#define PICTURE_NUM 10

class PictureObj : public ofxTuioObject
{
private:
    float sizeX,sizeY,default_angle;
    ofImage image;
    void setConfig(int fiducialId);
    int image_mag;
public:
    PictureObj() {};
    ~PictureObj() {};
    PictureObj(ofxTuioObject * _object);
    void draw();
    void update(ofxTuioObject * _object);
    bool isActionRange(ofxTuioCursor * _cursor);
    bool isRange(ofxTuioCursor * _cursor);
    void touchAction(ofxTuioCursor * _cursor);
};



#endif // PICTURE_H_INCLUDED

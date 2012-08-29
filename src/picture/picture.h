#pragma once
#ifndef PICTURE_H_INCLUDED
#define PICTURE_H_INCLUDED
#include "ofxTuio.h"
#include "../Util/Utility.h"
#include "ofMain.h"
#include <string>
//default size is 50*50
#define DEFAULT_IMAGE_WIDTH 50
#define DEFAULT_IMAGE_HEIGHT 50

class PictureObj : public ofxTuioObject
{
private:
    float width,height,default_angle;
    int image_mag;
public:
    PictureObj();
    ~PictureObj() {};
    PictureObj(ofxTuioObject * _object);
    void draw();
    void update(ofxTuioObject * _object);
    bool isActionRange(ofxTuioCursor * _cursor);
    bool isRange(ofxTuioCursor * _cursor);
    void touchAction(ofxTuioCursor * _cursor);
    float getWidth();
    float getHeight();
};



#endif // PICTURE_H_INCLUDED

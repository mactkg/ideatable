#include "picture.h"

PictureObj::PictureObj(ofxTuioObject * _object):ofxTuioObject(_object)
{
    width=DEFAULT_IMAGE_WIDTH;
    height=DEFAULT_IMAGE_HEIGHT;
}
PictureObj::PictureObj(){
    width=DEFAULT_IMAGE_WIDTH;
    height=DEFAULT_IMAGE_HEIGHT;
}

void PictureObj::update(ofxTuioObject * _object)
{
    ofxTuioObject::update(_object);
    width=DEFAULT_IMAGE_WIDTH+this->getAngleDegrees();
    height=DEFAULT_IMAGE_HEIGHT+this->getAngleDegrees();
}

//touch function
bool PictureObj::isActionRange(ofxTuioCursor * _cursor) {
    return false;
}

bool PictureObj::isRange(ofxTuioCursor * _cursor) {
    return false;
}

void PictureObj::touchAction(ofxTuioCursor * _cursor) {
    //nothing todo with when touch the pictureobj
}

//config Getter
float PictureObj::getWidth(){
    return width;
}

float PictureObj::getHeight(){
    return height;
}

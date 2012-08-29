#include "video.h"
VideoObj::VideoObj(ofxTuioObject * _blob):ofxTuioObject(_blob){
}

VideoObj::VideoObj(){
    width=DEFAULT_VIDEO_WIDTH;
    height=DEFAULT_VIDEO_HEIGHT;
}

VideoObj::~VideoObj(){
}

void VideoObj::update(ofxTuioObject * _object) {
    ofxTuioObject::update(_object);
}

void VideoObj::draw() {

}

bool VideoObj::isActionRange(ofxTuioCursor * _cursor) {
    return false;
}

bool VideoObj::isRange(ofxTuioCursor * _cursor) {
    return false;
}

void VideoObj::touchAction(ofxTuioCursor * _cursor) {
}

int VideoObj::getHeight(){
    return height;
}

int VideoObj::getWidth(){
    return width;
}

void VideoObj::setWidth(int _w){
    width=_w;
}

void VideoObj::setHeight(int _h){
    height=_h;
}

void VideoObj::setSize(int _w,int _h){
    setHeight(_h);
    setWidth(_w);
}

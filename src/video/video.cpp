#include "video.h"
VideoObj::VideoObj()(ofxTuioObject * _blob):ofxTuioObject(_blob){
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

#include "video.h"
VideoPlayer::VideoPlayer(ofxTuioObject * _blob):ofxTuioObject(_blob){
    string filepath="/video/"+getFilePath(this->getFiducialId());
    player.loadMovie(filepath);
    player.idleMovie();
    player.setLoopState(OF_LOOP_NONE);
}

VideoPlayer::~VideoPlayer(){
    player.closeMovie();
}

void VideoPlayer::update(ofxTuioObject * _object) {
    ofxTuioObject::update(_object);
}

void VideoPlayer::draw() {

}

bool VideoPlayer::isActionRange(ofxTuioCursor * _cursor) {
    return false;
}

bool VideoPlayer::isRange(ofxTuioCursor * _cursor) {
    return false;
}

void VideoPlayer::touchAction(ofxTuioCursor * _cursor) {

}

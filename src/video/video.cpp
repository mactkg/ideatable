#include "video.h"
VideoPlayer::VideoPlayer(ofxTuioObject * _blob):ofxTuioObject(_blob){
    string filepath=getFilePath(this->getFiducialId());
    player.loadMovie(filepath);
    player.idleMovie();
    player.setLoopState(OF_QT_LOOP_NONE);
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

}

bool VideoPlayer::isRange(ofxTuioCursor * _cursor) {
    
}

void VideoPlayer::touchAction(ofxTuioCursor * _cursor) {

}

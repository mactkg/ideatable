#include "BGM.h"
BGM::BGM(ofxTuioObject * _blob):ofxTuioObject(_blob) {
    vol=0.0;
    angle=_blob->getAngle();
    FID=_blob->getFiducialId();
    musicname="/sounds/"+ofToString(FID)+".mp3";    //If you want to listen some musics,
    music.loadSound(musicname);                     //you rename the *.mp3 to "markerID".mp3 and D&D into /bin/data/sounds/
    music.setMultiPlay(true);
    music.setLoop(true);                            //Music is loop.
    music.setVolume(vol);                           //Default volume is 0.
    music.play();
}

BGM::~BGM(){
    music.stop();
}

void BGM::draw() {

}

void BGM::update(ofxTuioObject * _tuioObject) {
    ofxTuioObject::update(_tuioObject);
    vol=_tuioObject->getAngle()/(2.0*3.141592653589793238);
    music.setVolume(vol);
}

void BGM::touchAction(ofxTuioCursor * _cursor){

}

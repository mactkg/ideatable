#include "BGM.h"
BGM::BGM(ofxTuioObject * _blob):ofxTuioObject(_blob) {
    vol=0.0;
    musicname="/sounds/"+getFilePath(_blob->getFiducialId());    //If you want to listen some musics,
    music.loadSound(musicname);                     //you rename the *.mp3 to "markerID".mp3 and D&D into /bin/data/sounds/
    music.setMultiPlay(true);
    music.setLoop(true);                            //Music is loop.
    music.setVolume(vol);                           //Default volume is 0.
    music.play();
    playtime=0.0;
}

BGM::~BGM(){
    music.stop();
}

void BGM::draw() {
    glPushMatrix();
    glTranslatef(this->getX()*ofGetWidth(),this->getY()*ofGetHeight(),0.0);
    glRotatef(this->getAngleDegrees(),0.0,1,0);
    ofFill();
    ofSetColor(0,0,120+playtime*200,130);
    ofCircle(0.0,0.0,spectrum[0]*30.0*100);
    glPopMatrix();
}

void BGM::update(ofxTuioObject * _tuioObject) {
    ofxTuioObject::update(_tuioObject);
    vol=_tuioObject->getAngle()/(2.0*3.141592653589793238);
    music.setVolume(vol);
    playtime=music.getPosition();
    spectrum=ofSoundGetSpectrum(1);
}

bool BGM::isRange(ofxTuioCursor * _cursor){
    return false;
}

bool BGM::isActionRange(ofxTuioCursor * _cursor){
    return false;
}

void BGM::touchAction(ofxTuioCursor * _cursor){
}

#ifndef BGM_H_INCLUDED
#define BGM_H_INCLUDED
#pragma once
#include "ofxTuio.h"
#include "ofMain.h"
#include "../Util/Utility.h"
#define BGM_NUM 5
class BGM : public ofxTuioObject {
private:
    float angle,vol,playtime;
    float *spectrum;
    string musicname;
    ofSoundPlayer music;
public:
    BGM(ofxTuioObject * _blob);
    BGM() {};
    ~BGM();
    void draw();
    void update(ofxTuioObject * _blob);
    bool isRange(ofxTuioCursor * _cursor);
    bool isActionRange(ofxTuioCursor * _cursor);
    void touchAction(ofxTuioCursor * _cursor);
};
#endif // BGM_H_INCLUDED

#ifndef BGM_H_INCLUDED
#define BGM_H_INCLUDED
#pragma once
#include "ofxTuio.h"
#include "ofMain.h"
#include "../Util/Utility.h"
class BGM : public ofxTuioObject {
private:
    float angle,vol,playtime;
    float spectrum;
public:
    BGM(ofxTuioObject * _blob);
    BGM() {};
    ~BGM();
    void draw();
    void update(ofxTuioObject * _blob);
    bool isRange(ofxTuioCursor * _cursor);
    bool isActionRange(ofxTuioCursor * _cursor);
    void touchAction(ofxTuioCursor * _cursor);
    float getVolume();
    void setSpectrum(float * spectrum);
};
#endif // BGM_H_INCLUDED

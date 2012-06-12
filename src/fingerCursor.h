#ifndef FINGERCURSOR_H_INCLUDED
#define FINGERCURSOR_H_INCLUDED
#include "ofxTuio.h"
#include "string.h"
#define ACTIVE 1
#define LINE 0
#define PASSIVE -1
class fingerCursor : public ofxTuioCursor
{
public:
    fingerCursor(ofxTuioCursor * _blob):ofxTuioCursor(_blob){};
    fingerCursor(){};
    ~fingerCursor(){};
    int getState();
    string changeState(bool position);
private:
    int state;
};
#endif // FINGERCURSOR_H_INCLUDED

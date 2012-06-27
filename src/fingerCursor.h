#ifndef FINGERCURSOR_H_INCLUDED
#define FINGERCURSOR_H_INCLUDED
#include "ofxTuio.h"
#include "string.h"
#define CURSOR_ACTIVE 1
#define CURSOR_ON_LINE 0
#define CURSOR_PASSIVE -1
#define drawobj 1
#define drawline 2
#define makeline 3
#define lineend 4
#define none 0

class fingerCursor : public ofxTuioCursor {
public:
    fingerCursor(ofxTuioCursor * _cursor,bool position);
    fingerCursor() {};
    ~fingerCursor() {};
    int getState();
    int changeState(bool position);
    void setObject(ofxTuioObject * _object);
    ofxTuioObject getLatestObject();
private:
    int state;
    ofxTuioObject buf;
};
#endif // FINGERCURSOR_H_INCLUDED

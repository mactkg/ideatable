#ifndef FINGERCURSOR_H_INCLUDED
#define FINGERCURSOR_H_INCLUDED
#include "ofxTuio.h"
#include "string.h"
#define CURSOR_ACTIVE 1
#define CURSOR_ON_LINE 0
#define CURSOR_PASSIVE -1
class fingerCursor : public ofxTuioCursor {
public:
    fingerCursor(ofxTuioCursor * _cursor,bool position);
    fingerCursor() {};
    ~fingerCursor() {};
    int getState();
    string changeState(bool position);
private:
    int state;
};
#endif // FINGERCURSOR_H_INCLUDED

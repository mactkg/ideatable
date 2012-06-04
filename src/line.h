#ifndef LINE_H_INCLUDED
#define LINE_H_INCLUDED
#include "ofxTuio.h"
class line{
    public:
    line(){};
    line(ofxTuioObject * _object,ofxTuioCursor * _cursor);
    ~line(){};
    void draw();
    void update(ofxTuioCursor * _cursor);
    void update(ofxTuioObject * _object);
    void update(ofxTuioObject * _object, ofxTuioCursor * _cursor);
    void lineEnd(ofxTuioObject * _object);
    int getfromID();
    int getToID();
    int getCursorID();
    private:
    ofxTuioObject from,to;
    ofxTuioCursor tp;
    bool isEnd;
};
#endif // LINE_H_INCLUDED

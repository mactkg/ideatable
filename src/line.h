#ifndef LINE_H_INCLUDED
#define LINE_H_INCLUDED
#include "ofxTuio.h"
class line{
    public:
    line();
    line(ofxTuioObject * _object,ofxTuioCursor * _cursor);
    ~line();
    void draw();
    void update(ofxTuioCursor * _cursor);
    void update(ofxTuioObject * _object);
    private:
    ofxTuioObject from,to;
    ofxTuioCursor tp;
    bool isEnd
};
#endif // LINE_H_INCLUDED

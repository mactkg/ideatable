#ifndef IDEA_H_INCLUDED
#define IDEA_H_INCLUDED

#include "ofMain.h"
#include "ofxTuio.h"

#define IDEA_DEFAULT_RADIUS 30

class Idea : public ofxTuioObject {
    private:
    float radius;
    public:
    Idea();
    Idea(ofxTuioObject * _o);
    ~Idea();
    void draw();
    void update(ofxTuioObject * _o);
    bool isRange(ofxTuioCursor * cursor);
    bool isActionRange(ofxTuioCursor * cursor);
    void touchAction(ofxTuioCursor * cursor);
};
#endif // IDEA_H_INCLUDED

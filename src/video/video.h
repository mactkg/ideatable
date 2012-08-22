#ifndef VIDEO_H_INCLUDED
#define VIDEO_H_INCLUDED

#include "ofMain.h"
#include "ofxTuio.h"
#include "../Util/Utility.h"

class VideoObj : ofxTuioObject {
    public:
    VideoObj(ofxTuioObject * _blob);
    VideoObj();
    ~VideoObj();
    void draw();
    void update(ofxTuioObject * _blob);
    bool isRange(ofxTuioCursor * _cursor);
    bool isActionRange(ofxTuioCursor * _cursor);
    void touchAction(ofxTuioCursor * _cursor);
    private:
    int width,height;
};


#endif // VIDEO_H_INCLUDED

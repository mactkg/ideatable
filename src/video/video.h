#ifndef VIDEO_H_INCLUDED
#define VIDEO_H_INCLUDED
#include "ofMain.h"
#include "ofxTuio.h"
#include "../Util/Utility.h"
class VideoPlayer : ofxTuioObject {
    public:
    VideoPlayer(ofxTuioObject * _blob);
    ~VideoPlayer();
    void draw();
    void update(ofxTuioObject * _blob);
    bool isRange(ofxTuioCursor * _cursor);
    bool isActionRange(ofxTuioCursor * _cursor);
    void touchAction(ofxTuioCursor * _cursor);
    private:
    ofVideoPlayer player;
    int width,height;
};


#endif // VIDEO_H_INCLUDED

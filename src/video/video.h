#ifndef VIDEO_H_INCLUDED
#define VIDEO_H_INCLUDED

#include "ofMain.h"
#include "ofxTuio.h"
#include "../Util/Utility.h"
/*videos default window size is 320*240,
if you want to fix it,use setWidth and setHeight or setSize*/
#define DEFAULT_VIDEO_HEIGHT 240
#define DEFAULT_VIDEO_WIDTH 320

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
    int getWidth();
    int getHeight();
    void setHeight(int _h);
    void setWidth(int _w);
    void setSize(int _w,int _h);
    private:
    int width,height;
};


#endif // VIDEO_H_INCLUDED

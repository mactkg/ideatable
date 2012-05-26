#include "index.h"
#include "ofxTuio.h"
class Base{
    private:
    //以下にオブジェクトを追加
<<<<<<< HEAD
=======
        Sample sample;
>>>>>>> origin/master
        int index;
        int FID;
    public:
        Base(ofxTuioObject * _tuioObject);
        Base();
        int getFid();
        void draw();
        void update(ofxTuioObject * _tuioObject);
        void touchAction(ofxTuioCursor * _tuioCursor);
        void destroy();
};

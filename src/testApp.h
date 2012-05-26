#pragma once

#include "ofMain.h"
#include "ofxTuio.h"
#include "Base.h"
class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
        //オブジェクトの検知
        void objectAdded(ofxTuioObject & tuioObject);
        void objectRemoved(ofxTuioObject & tuioObject);
        void objectUpdated(ofxTuioObject & tuioObject);
        //タッチの検知
        void tuioAdded(ofxTuioCursor & tuioCursor);
        void tuioRemoved(ofxTuioCursor & tuioCursor);
        void tuioUpdated(ofxTuioCursor & tuioCursor);
    private:
        vector<Base> objects;
        vector<Base>::iterator obj_itr;
        myTuioClient tuio;
        string log;
};

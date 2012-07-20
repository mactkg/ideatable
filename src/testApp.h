#pragma once

#include "ofMain.h"
#include "ofxTuio.h"
#include "Base.h"
#include "line.h"
#include "map"
#include "string"
class testApp : public ofBaseApp {

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
    map<int,Base> objects;
    map<int,Base>::iterator obj_itr;
    map<int,int> prevStatus;
    vector<objLine> lines;
    vector<objLine>::iterator line_itr;
    myTuioClient tuio;
    string log;
    bool showLogFlag;
};

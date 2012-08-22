#pragma once

#include "ofMain.h"
#include "ofxTuio.h"

#include "line\line.h"
#include "sample\sample.h"
#include "video\video.h"
#include "BGM\BGM.h"

#include "map"
#include "string"

#define OUT_RANGE -1
#define IN_RANGE 1
#define IDEA_NUM 50
#define IMAGE_NUM 10
#define VIDEO_NUM 5
#define BGM_NUM 4
//using this for testApp::setType
#define TYPE_IDEA 0
#define TYPE_IMAGE 1
#define TYPE_BGM 2
#define TYPE_MOVIE 3
//using this for testApp::changeIndex
#define OBJ_NEGATIVE -1
#define OBJ_ACTIVE 1

#define INDEX(x,i) x##Index[i]

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
    //connect fiducialId and each Object
    void setType(int start,int end,int type);
    void setType(int pos,int type);
    //change grobal and local index
    void changeIndex(int fid,int type);
    //Object Detection
    void objectAdded(ofxTuioObject & tuioObject);
    void objectRemoved(ofxTuioObject & tuioObject);
    void objectUpdated(ofxTuioObject & tuioObject);
    
    //Touch Detection
    void tuioAdded(ofxTuioCursor & tuioCursor);
    void tuioRemoved(ofxTuioCursor & tuioCursor);
    void tuioUpdated(ofxTuioCursor & tuioCursor);

private:
    int types[100]; //FiducialIdでタイプ振り分け
    map<int,ofxTuioObject> objects;
    map<int,ofxTuioObject>::iterator obj_itr;
    map<int,int> prevStatus;
    
    int ideaIndex[IDEA_NUM];
    
    int soundIndex[BGM_NUM];
    ofSoundPlayer sounds[BGM_NUM];
    BGM bgms[BGM_NUM];
    
    int imageIndex[IMAGE_NUM];
    ofImage images[IMAGE_NUM];
    PictureObj pictobjs[IMAGE_NUM];

    int videoIndex[VIDEO_NUM];
    ofVideoPlayer players[VIDEO_NUM];
    VideoObj vobjs[VIDEO_NUM];
    
    vector<objLine> lines;
    vector<objLine>::iterator line_itr;
    myTuioClient tuio;
    string log;
};

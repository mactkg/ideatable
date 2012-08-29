#pragma once

#include "ofMain.h"
#include "ofxTuio.h"
#include "objects.h"
#include "map"
#include "string"

#define OUT_RANGE -1
#define IN_RANGE 1
//using this for testApp::changeIndex
#define OBJ_NEGATIVE -1
#define OBJ_ACTIVE 1

class testApp : public ofBaseApp {

public:
    void setup();
    void update();
    void draw();
    
    //KeyEvent listener
    void keyPressed  (int key);
    void keyReleased(int key);
    
    //MouseEvent listener
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    
    //of Other Event listener
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    //connect fiducialId and each Object
    void setType(int start,int end,int type);
    void setType(int pos,int type);
    //get index array from fiducialId
    int* getIndex(int fid);
    //change grobal and local index
    void changeIndex(int fid,int type);
    //tuioObject-Event listener
    void objectAdded(ofxTuioObject & tuioObject);
    void objectRemoved(ofxTuioObject & tuioObject);
    void objectUpdated(ofxTuioObject & tuioObject);
    
    //tuio Cursor-Event listener
    void tuioAdded(ofxTuioCursor & tuioCursor);
    void tuioRemoved(ofxTuioCursor & tuioCursor);
    void tuioUpdated(ofxTuioCursor & tuioCursor);

private:
    int types[100]; //Type Index(video,idea,bgm,image etc...)
    bool isActive[100];
    map<int,ofxTuioObject> objects;
    map<int,ofxTuioObject>::iterator obj_itr;
    map<int,int> prevStatus;
    
    int idea_Index[IDEA_NUM];
    Idea ideas[IDEA_NUM];
    
    int soundIndex[BGM_NUM];
    ofSoundPlayer sounds[BGM_NUM];
    BGM bgms[BGM_NUM];
    
    int videoIndex[VIDEO_NUM];
    ofVideoPlayer vplayers[VIDEO_NUM];
    VideoObj videos[VIDEO_NUM];
    
    int imageIndex[IMAGE_NUM];
    ofImage images[IMAGE_NUM];
    PictureObj imageobjs[IMAGE_NUM];
    
    vector<objLine> lines;
    vector<objLine>::iterator line_itr;
    myTuioClient tuio;
    string log;
};

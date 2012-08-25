#include "testApp.h"
//--------------------------------------------------------------
void testApp::setup() {
    //Add each event listener
    ofAddListener(tuio.objectAdded,this,&testApp::objectAdded);
    ofAddListener(tuio.objectRemoved,this,&testApp::objectRemoved);
    ofAddListener(tuio.objectUpdated,this,&testApp::objectUpdated);
    ofAddListener(tuio.cursorAdded,this,&testApp::tuioAdded);
    ofAddListener(tuio.cursorRemoved,this,&testApp::tuioRemoved);
    ofAddListener(tuio.cursorUpdated,this,&testApp::tuioUpdated);
    //Set framerate to 60 fps
    ofSetFrameRate(60);
    //Background color 
    ofBackground(0,0,0);
    //tuio client use 3333 port
    tuio.start(3333);
    log="";
    //init index
    memset(types,-1,100);
    int i;
    //init IdeaObjects
    for(i=0;i<IDEA_NUM;i++){
        idea_Index[i]=-1;
    }
    //init soundplayer
    for(i=0;i<BGM_NUM;i++){
        soundIndex[i]=-1;
        sounds[i].loadSound("sound/"+ofToString(i)+".mp3");
    }
    //init ImageLoader
    for(i=0;i<IMAGE_NUM;i++){
        imageIndex[i]=-1;
        images[i].loadImage("image/"+ofToString(i)+".jpg");
    }
    //init Videos
    for(i=0;i<VIDEO_NUM;i++){
        videoIndex[i]=-1;
        vplayers[i].loadMovie("videos/"+ofToString(i)+".mp4");
    }
    //init main index
    
}
//--------------------------------------------------------------
void testApp::update() {
    tuio.getMessage();
    
}

//--------------------------------------------------------------
void testApp::draw(){
    ofEnableAlphaBlending();
    ofSetColor(0,0,0,50);
    #ifdef DEBUG
    ofSetColor(255,255,255);
    ofDrawBitmapString(log,20,20);
    #endif
    ofDisableAlphaBlending();
}

//--------------------------------------------------------------
void testApp::setType(int fid,int type){
        changeIndex(fid,type);
}

void testApp::setType(int start,int end,int type){
    for(;start<=end;start++){
        changeIndex(start,type);
    }
}
//--------------------------------------------------------------
void testApp::changeIndex(int fid,int type){
    int i,max;
    int arrays[];
    bool changeflag=false;
    if(type==TYPE_IDEA){
        arrays=idea_Index;
        max=IDEA_NUM;
    }else if(type==TYPE_IMAGE){
        arrays=imageIndex;
        max=IMAGE_NUM;
    }else if(type==TYPE_BGM){
        arrays=soundIndex;
        max=BGM_NUM;
    }else if(type==TYPE_MOVIE){
        arrays=videoIndex;
        max=VIDEO_NUM;
    }
    for(i=0;i<max||changeflag;i++){
        if(arrays[i]==-1){
            arrays[i]=fid;
            changeflag=true;
        }else if(arrays[i]==fid)
            return;
    }
    
    if(!changeflag){
        index[arrays[max-1]]=-1;
        arrays[max-1]=fid;
        ofLogWarning()<<"object index is overwritting!";
    }
}
//--------------------------------------------------------------
void testApp::keyPressed(int key) {
    #ifdef DEBUG
    log="Key Pressed : keycode:"+ofToString(key);
    #endif
}

//--------------------------------------------------------------
void testApp::keyReleased(int key) {
    #ifdef DEBUG
    log="Key Released : keycode:"+ofToString(key);
    #endif
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ) {
    #ifdef DEBUG
    log="Mouse Moved: X: "+ofToString(x)
        +" Y: "+ofToString(y);
    #endif
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button) {
    #ifdef DEBUG
    log="Mouse Dragged: "+ofToString(button)
        +" X: "+ofToString(x)
        +" Y: "+ofToString(y);
    #endif
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button) {
    #ifdef DEBUG
    log="Mouse Pressed: "+ofToString(button)
        +" X: "+ofToString(x)
        +" Y: "+ofToString(y);
    #endif
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button) {
    #ifdef DEBUG
    log="Mouse Released: "+ofToString(button)+
        " X: "+ofToString(x)+
        " Y: "+ofToString(y);
    #endif
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo) {
}

void testApp::objectAdded(ofxTuioObject & tuioObject) {
    objects.insert(map<int,ofxTuioObject>::value_type(tuioObject.getFiducialId(),
                   &tuioObject));
    #ifdef DEBUG
    log="New Object: "+ofToString(tuioObject.getFiducialId())+
        " X: "+ofToString(tuioObject.getX())+
        " Y: "+ofToString(tuioObject.getY());
    ofLog()<<log;
    #endif
}

void testApp::objectRemoved(ofxTuioObject & tuioObject) {
    objects.erase(tuioObject.getFiducialId());
    for(line_itr=lines.begin();line_itr!=lines.end();++line_itr){
        if((*line_itr).getFromID()==tuioObject.getFiducialId()||
           (*line_itr).getToID()==tuioObject.getFiducialId()){
                lines.erase(line_itr);
                break;
           }
    }
    #ifdef DEBUG
    log="Object Removed: "+ofToString(tuioObject.getFiducialId())+
        " X: "+ofToString(tuioObject.getX())+
        " Y: "+ofToString(tuioObject.getY());
    ofLog()<<log;
    #endif
}

//call when TuioObject is moved
void testApp::objectUpdated(ofxTuioObject & tuioObject) {
    //TODO update objects corresponding to tuioObject's FiducialID
    for(line_itr=lines.begin();line_itr!=lines.end();line_itr++) {
        (*line_itr).update(&tuioObject);
    }
    #ifdef DEBUG
    log="Object Updated: "+ofToString(tuioObject.getFiducialId())+
        " X: "+ofToString(tuioObject.getX())+
        " Y: "+ofToString(tuioObject.getY());
    ofLog()<<log;
    #endif
}

//call when finger is moved
void testApp::tuioAdded(ofxTuioCursor & tuioCursor) {
    //TODO add function that runs when finger added 
    #ifdef DEBUG
    log="New Cursor: "+ofToString(tuioCursor.getFingerId())+
        " X: "+ofToString(tuioCursor.getX())+
        " Y: "+ofToString(tuioCursor.getY());
    ofLog()<<log;
    #endif
}

//call when finger is removed from Ideatable
void testApp::tuioRemoved(ofxTuioCursor & tuioCursor) {
    //remove line which is related to the finger
    for(line_itr=lines.begin();line_itr!=lines.end();line_itr++){
        if((*line_itr).getCursorID()==tuioCursor.getFingerId())
            lines.erase(line_itr);
    }
    prevStatus.erase(tuioCursor.getFingerId());
    #ifdef DEBUG
    log="Cursor Removed: "+ofToString(tuioCursor.getFingerId())+
        " X: "+ofToString(tuioCursor.getX())+
        " Y: "+ofToString(tuioCursor.getY());
    ofLog()<<log;
    #endif
}

void testApp::tuioUpdated(ofxTuioCursor & tuioCursor) {
    //TODO add linemake function and update object
    #ifdef DEBUG
    log="Cursor Updated: "+ofToString(tuioCursor.getFingerId())+
        " X: "+ofToString(tuioCursor.getX())+
        " Y: "+ofToString(tuioCursor.getY());
    ofLog()<<log;
    #endif
}

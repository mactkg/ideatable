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
    ofBackground(255,255,255);
    //tuio client use 3333 port
    tuio.start(3333);
    log="";
    int i;
    //init whole index
    for(i=0;i<100;i++){
        types[i]=-1;
        isActive[i]=false;
    }
    //init IdeaObjects
    for(i=0;i<IDEA_NUM;i++){
        idea_Index[i]=-1;
    }
    //init soundplayer
    for(i=0;i<BGM_NUM;i++){
        soundIndex[i]=-1;
        sounds[i].loadSound("sounds/"+ofToString(i)+".mp3");
        sounds[i].setLoop(true);
        sounds[i].setMultiPlay(true);
    }
    //init ImageLoader
    for(i=0;i<IMAGE_NUM;i++){
        imageIndex[i]=-1;
        images[i].loadImage("image/"+ofToString(i)+".png");
    }
    //init Videos
    for(i=0;i<VIDEO_NUM;i++){
        videoIndex[i]=-1;
        vplayers[i].loadMovie("videos/"+ofToString(i)+".mp4");
    }
    //fix
    setType(0,TYPE_BGM);
    setType(1,TYPE_IMAGE);
        ofSoundStreamSetup(0,1,this);
    // we don't want to be running to fast <-サンプル丸パクリ
    ofSetVerticalSync(true);
    ofSetFrameRate(60);

    //create the socket and set to send to 127.0.0.1:11999　<-サンプル丸パクリ
    udpConnection.Create();
    udpConnection.Connect("127.0.0.1",11999);
    udpConnection.SetNonBlocking(true);
}
//--------------------------------------------------------------
void testApp::update() {
    tuio.getMessage();
    
}

//--------------------------------------------------------------
void testApp::draw(){
    ofEnableAlphaBlending();
    int i;
    for(i=0;i<IMAGE_NUM;i++){
        if(imageIndex[i]!=-1&&isActive[imageIndex[i]]){
        //images[i].loadImage("image/1.png");
        images[i].draw(imageobjs[i].getX()*ofGetWidth(),
                       imageobjs[i].getY()*ofGetHeight(),
                       imageobjs[i].getHeight(),imageobjs[i].getWidth());
        ofLogWarning()<<"drawing1";
        }
        
    }
    for(i=0;i<BGM_NUM;i++){
        if(soundIndex[i]!=-1&&isActive[soundIndex[i]]){
            if(!sounds[i].getIsPlaying())
                sounds[i].play();
            bgms[i].setSpectrum(ofSoundGetSpectrum(1));
            bgms[i].draw();
        }
    }
    for(i=0;i<VIDEO_NUM;i++){
        if(videoIndex[i]!=-1&&isActive[videoIndex[i]]){
        }
    }
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
    int *array;
    bool changeflag=false,warnflag=false;
    if(types[fid]!=-1){
        array=getIndex(fid);
        while(0){
            if(array[i]==fid){
                array[i]=-1;
                break;
            }
        }
        warnflag=true;
    }
    types[fid]=type;
    switch(type){
    case TYPE_IDEA:
        array=idea_Index;max=IDEA_NUM;break;
    case TYPE_VIDEO:
        array=videoIndex;max=VIDEO_NUM;break;
    case TYPE_BGM:
        array=soundIndex;max=BGM_NUM;break;
    case TYPE_IMAGE:
        array=imageIndex;max=IMAGE_NUM;break;
    }
    for(i=0;i<max;i++){
        if(array[i]==-1){
            array[i]=fid;
            changeflag=true;
            break;
        }else if(array[i]==fid)
            break;
    }
    
    if(!changeflag){
        types[array[max-1]]=-1;
        array[max-1]=fid;
        warnflag=true;
    }
    if(warnflag)ofLogWarning()<<"Object Index is overwritting!";
}
//--------------------------------------------------------------
int* testApp::getIndex(int fid){
    switch(types[fid]){
    case TYPE_IDEA:
        return idea_Index;
    case TYPE_IMAGE:
        return imageIndex;
    case TYPE_VIDEO:
        return videoIndex;
    case TYPE_BGM:
        return soundIndex;
    }
    ofLogWarning()<<"object not found:"<<fid;
    return NULL;
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
    isActive[tuioObject.getFiducialId()]=true;
    #ifdef DEBUG
    log="New Object: "+ofToString(tuioObject.getFiducialId())+
        " X: "+ofToString(tuioObject.getX())+
        " Y: "+ofToString(tuioObject.getY());
    ofLog()<<log;
    #endif
}

void testApp::objectRemoved(ofxTuioObject & tuioObject) {
    int i;
    objects.erase(tuioObject.getFiducialId());
    isActive[tuioObject.getFiducialId()]=false;
    if(types[tuioObject.getFiducialId()]==TYPE_BGM){
        for(i=0;i<BGM_NUM;i++){
            if(soundIndex[i]==tuioObject.getFiducialId())
                if(sounds[i].getIsPlaying())
                    sounds[i].stop();
        }
    }else if(types[tuioObject.getFiducialId()]==TYPE_VIDEO){
        for(i=0;i<VIDEO_NUM;i++){
            if(videoIndex[i]==tuioObject.getFiducialId())
                if(vplayers[i].isPlaying())
                    vplayers[i].closeMovie();
        }
    }
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
    int i=0,max,*array=getIndex(tuioObject.getFiducialId());
    if(array==NULL)return;
    while(0){
        if(array[i]==tuioObject.getFiducialId())
            break;
        i++;
    }
    switch(types[tuioObject.getFiducialId()]){
    case TYPE_IDEA:
        ideas[i].update(&tuioObject);
        break;
    case TYPE_VIDEO:
        videos[i].update(&tuioObject);
        break;
    case TYPE_BGM:
        bgms[i].update(&tuioObject);
        break;
    case TYPE_IMAGE:
        imageobjs[i].update(&tuioObject);
        ofLogWarning()<<"image update";
        break;
    }
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
void testApp::audioReceived(float * input , int bufferSize, int nChannels){
    string message="";
    for (int i=0; i < bufferSize; i++){
        message+=ofToString(input[i])+"|";
    }
    int sent = udpConnection.Send(message.c_str(),message.length());
}

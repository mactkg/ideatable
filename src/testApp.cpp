#include "testApp.h"
//--------------------------------------------------------------
void testApp::setup() {
    ofAddListener(tuio.objectAdded,this,&testApp::objectAdded);
    ofAddListener(tuio.objectRemoved,this,&testApp::objectRemoved);
    ofAddListener(tuio.objectUpdated,this,&testApp::objectUpdated);
    ofAddListener(tuio.cursorAdded,this,&testApp::tuioAdded);
    ofAddListener(tuio.cursorRemoved,this,&testApp::tuioRemoved);
    ofAddListener(tuio.cursorUpdated,this,&testApp::tuioUpdated);
    //フレームレート設定
    ofSetFrameRate(60);
    //背景色を黒に
    ofBackground(0,0,0);
    //3333番ポートで通信開始
    tuio.start(3333);
    log="";
    showLogFlag=false;
}
//--------------------------------------------------------------
void testApp::update() {
    tuio.getMessage();
}

//--------------------------------------------------------------
void testApp::draw() {
    obj_itr=objects.begin();
    ofEnableAlphaBlending();
    while(obj_itr != objects.end()) {
        (*obj_itr).second.draw();
        obj_itr++;
    }
    ofSetColor(0,0,0,50);
    ofRect(0,0,ofGetWidth(),ofGetHeight());
    ofSetColor(0xffffff);
    if(showLogFlag==true)ofDrawBitmapString(log,20,20);
    ofDisableAlphaBlending();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key) {
    //'l'キーでログ表示
    if(key==108&&showLogFlag==false)showLogFlag=true;
    else if(key==108)showLogFlag=false;
    log="Key Pressed : keycode:"+ofToString(key);
}

//--------------------------------------------------------------
void testApp::keyReleased(int key) {
    log="Key Released : keycode:"+ofToString(key);
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ) {
    log="Mouse Moved: X: "+ofToString(x)
        +" Y: "+ofToString(y);
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button) {
    log="Mouse Dragged: "+ofToString(button)
        +" X: "+ofToString(x)
        +" Y: "+ofToString(y);
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button) {
    log="Mouse Pressed: "+ofToString(button)
        +" X: "+ofToString(x)
        +" Y: "+ofToString(y);
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button) {
    log="Mouse Released: "+ofToString(button)+
        " X: "+ofToString(x)+
        " Y: "+ofToString(y);
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
    const Base obj(&tuioObject);
    objects.insert(map<int,Base>::value_type(tuioObject.getFiducialId(),
                   obj));
    log="New Object: "+ofToString(tuioObject.getFiducialId())+
        " X: "+ofToString(tuioObject.getX())+
        " Y: "+ofToString(tuioObject.getY());
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
    log="Object Removed: "+ofToString(tuioObject.getFiducialId())+
        " X: "+ofToString(tuioObject.getX())+
        " Y: "+ofToString(tuioObject.getY());
}

void testApp::objectUpdated(ofxTuioObject & tuioObject) {
    objects[tuioObject.getFiducialId()].update(&tuioObject);
    for(line_itr=lines.begin();line_itr!=lines.end();line_itr++) {
        (*line_itr).update(&tuioObject);
    }
    log="Object Updated: "+ofToString(tuioObject.getFiducialId())+
        " X: "+ofToString(tuioObject.getX())+
        " Y: "+ofToString(tuioObject.getY());
}

void testApp::tuioAdded(ofxTuioCursor & tuioCursor) {
    int t=-1;
    for(obj_itr=objects.begin();obj_itr!=objects.end();obj_itr++) {
        if((*obj_itr).second.isRange(&tuioCursor)) {
            if((*obj_itr).second.isActionRange(&tuioCursor)) {
                (*obj_itr).second.touchAction(&tuioCursor);
            } else
                t=(*obj_itr).second.getFiducialId();
        }
    }
    prevStatus.insert(map<int,int>::value_type(tuioCursor.getFingerId(),
                                               t));
    log="New Cursor: "+ofToString(tuioCursor.getFingerId())+
        " X: "+ofToString(tuioCursor.getX())+
        " Y: "+ofToString(tuioCursor.getY());
}

void testApp::tuioRemoved(ofxTuioCursor & tuioCursor) {
    //lineと関連があった場合該当するLineを削除
    for(line_itr=lines.begin();line_itr!=lines.end();line_itr++){
        if((*line_itr).getCursorID()==tuioCursor.getFingerId())
            lines.erase(line_itr);
    }
    prevStatus.erase(tuioCursor.getFingerId());
    log="Cursor Removed: "+ofToString(tuioCursor.getFingerId())+
        " X: "+ofToString(tuioCursor.getX())+
        " Y: "+ofToString(tuioCursor.getY());
}

void testApp::tuioUpdated(ofxTuioCursor & tuioCursor) {
    bool lineflag=false;
    for(line_itr=lines.begin();line_itr!=lines.end();line_itr++) {
        if((*line_itr).getCursorID()==tuioCursor.getFingerId()){
            (*line_itr).update(&tuioCursor);
            lineflag=true;
        }
    }
    for(obj_itr=objects.begin();obj_itr!=objects.end();obj_itr++) {
        if((*obj_itr).second.isRange(&tuioCursor)) {
            if(lineflag)(*line_itr).lineEnd(&(*obj_itr).second.getObject());
            (*obj_itr).second.touchAction(&tuioCursor);
        }
    }
    log="Cursor Updated: "+ofToString(tuioCursor.getFingerId())+
        " X: "+ofToString(tuioCursor.getX())+
        " Y: "+ofToString(tuioCursor.getY());
}

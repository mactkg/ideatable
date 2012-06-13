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
}
//--------------------------------------------------------------
void testApp::update() {
    tuio.getMessage();
}

//--------------------------------------------------------------
void testApp::draw() {
    obj_itr=objects.begin();
    while(obj_itr != objects.end()) {
        (*obj_itr).second.draw();
        obj_itr++;
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void testApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ) {

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button) {

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
}

void testApp::objectRemoved(ofxTuioObject & tuioObject) {
    objects.erase(tuioObject.getFiducialId());
}

void testApp::objectUpdated(ofxTuioObject & tuioObject) {
    objects[tuioObject.getFiducialId()].update(&tuioObject);
    for(line_itr=lines.begin();line_itr!=lines.end();line_itr++) {
        (*line_itr).update(&tuioObject);
    }
}

void testApp::tuioAdded(ofxTuioCursor & tuioCursor) {
    bool fingerFlag=false;
    for(obj_itr=objects.begin();obj_itr!=objects.end();obj_itr++){
        if((*obj_itr).second.touchAction(&tuioCursor)==true){
            fingerFlag=true;
            break;
        }
    }
    fingerCursor f(&tuioCursor,fingerFlag);
    cursors.insert(map<int,fingerCursor>::value_type(tuioCursor.getFingerId(),
                   f));
}

void testApp::tuioRemoved(ofxTuioCursor & tuioCursor) {
    //lineと関連があった場合該当するLineを削除
        for(line_itr=lines.begin();line_itr!=lines.end();line_itr++){
            if((*line_itr).getCursorID()==tuioCursor.getFingerId())
                lines.erase(line_itr);
        }
    cursors.erase(tuioCursor.getFingerId());
}

void testApp::tuioUpdated(ofxTuioCursor & tuioCursor) {
    cursors[tuioCursor.getFingerId()].update(&tuioCursor);
}

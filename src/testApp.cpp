#include "testApp.h"
//--------------------------------------------------------------
void testApp::setup(){
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
void testApp::update(){
    tuio.getMessage();
}

//--------------------------------------------------------------
void testApp::draw(){
    obj_itr=objects.begin();
    while(obj_itr != objects.end()){
        obj_itr->draw();
        obj_itr++;
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){
}

void testApp::objectAdded(ofxTuioObject & tuioObject){
    const Base obj(&tuioObject);
    objects.push_back(obj);
}

void testApp::objectRemoved(ofxTuioObject & tuioObject){
    obj_itr=objects.begin();
    while(obj_itr!=objects.end()){
        if(obj_itr->getFid()==tuioObject.getFiducialId()){
            obj_itr->destroy();
            objects.erase(obj_itr);
            break;
        }
        obj_itr++;
    }
}

void testApp::objectUpdated(ofxTuioObject & tuioObject){
    obj_itr=objects.begin();
    while(obj_itr!=objects.end()){
        if(obj_itr->getFid()==tuioObject.getFiducialId()){
            obj_itr->update(&tuioObject);
        }
        obj_itr++;
    }
}

void testApp::tuioAdded(ofxTuioCursor & tuioCursor){
}

void testApp::tuioRemoved(ofxTuioCursor & tuioCursor){

}

void testApp::tuioUpdated(ofxTuioCursor & tuioCursor){

}

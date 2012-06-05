#include "testApp.h"
//--------------------------------------------------------------
void testApp::setup()
{
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
void testApp::update()
{
    tuio.getMessage();
}

//--------------------------------------------------------------
void testApp::draw()
{
    obj_itr=objects.begin();
    while(obj_itr != objects.end())
    {
        (*obj_itr).second.draw();
        obj_itr++;
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key)
{

}

//--------------------------------------------------------------
void testApp::keyReleased(int key)
{

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y )
{

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button)
{

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button)
{

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button)
{

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h)
{

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg)
{

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo)
{
}

void testApp::objectAdded(ofxTuioObject & tuioObject)
{
    const Base obj(&tuioObject);
    objects.insert(map<int,Base>::value_type(tuioObject.getFiducialId(),
                   obj));
}

void testApp::objectRemoved(ofxTuioObject & tuioObject)
{
    objects[tuioObject.getFiducialId()].destroy();
    objects.erase(tuioObject.getFiducialId());
}

void testApp::objectUpdated(ofxTuioObject & tuioObject)
{
    objects[tuioObject.getFiducialId()].update(&tuioObject);
}

void testApp::tuioAdded(ofxTuioCursor & tuioCursor)
{
    cursors.insert(map<int,ofxTuioCursor>::value_type(tuioCursor.getFingerId(),
                   &tuioCursor));
}

void testApp::tuioRemoved(ofxTuioCursor & tuioCursor)
{
    cursors.erase(tuioCursor.getFingerId());
}

void testApp::tuioUpdated(ofxTuioCursor & tuioCursor)
{
    cursors[tuioCursor.getFingerId()].update(&tuioCursor);
}

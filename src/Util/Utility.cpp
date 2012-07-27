#include "Utility.h"
string getFilePath(int _fid)
{
    string s;
    ifstream f(ofToString(_fid).c_str());
    if(!f) {
        return "";
    }
    f>>s;
    return s;
}

bool boxRange(float xpos,float ypos,float x,float y,int width,int height){
    return boxRange(xpos*ofGetWidth(),ypos*ofGetHeight(),
                    x*ofGetWidth(),y*ofGetHeight(),width,height);
}

bool boxRange(float xpos,float ypos,int x,int y,int width,int height) {
    return boxRange(xpos*ofGetWidth(),ypos*ofGetHeight(),
                    x,y,width,height);
}

bool boxRange(int xpos,int ypos,int x,int y,int width,int height) {
    if(xpos>x&&xpos<x+width&&
       ypos>y&&ypos<y+height) return true;
       return false;
}

bool circleRange(float xpos,float ypos,float x,float y,float radius) {
    ypos=ypos*ofGetHeight();
    xpos=xpos*ofGetWidth();
    float xdist=x-xpos;float ydist=y-ypos;
    if(xdist*xdist+ydist*ydist<radius*radius)
        return false;
    return true;
}

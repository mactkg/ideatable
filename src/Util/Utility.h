#ifndef UTILITY_H_INCLUDED
#define UTILITY_H_INCLUDED
#include "ofMain.h"
#include <string>
#include <iostream>
using namespace std;
string getFilePath(int _fid);
bool boxRange(float xpos,float ypos,float x,float y,int width,int height);
bool boxRange(float xpos,float ypos,int x,int y,int width,int height);
bool boxRange(int xpos,int ypos,int x,int y,int width,int height);
bool circleRange(float xpos,float ypos,float x,float y,float range);
#endif // FILEUTILITY_H_INCLUDED

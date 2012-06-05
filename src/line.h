#ifndef LINE_H_INCLUDED
#define LINE_H_INCLUDED
#include "ofxTuio.h"
//オブジェクトとオブジェクトをつなぐ名状しがたいパスのようなもの.h
class Line{
    public:
    //こんすとらくたぁ
        line(){};
        line(ofxTuioObject * _object,ofxTuioCursor * _cursor);
        ~line(){};
    //描画はこれだけ呼べばおｋ
        void draw();
    //関連するObject,Cursorが変更されたら必ず呼ぶ
        void update(ofxTuioCursor * _cursor);
        void update(ofxTuioObject * _object);
        void update(ofxTuioObject * _object, ofxTuioCursor * _cursor);
    //pathの開通
        void lineEnd(ofxTuioObject * _object);
    //pathの消去、アクションの検知
        bool touchAction(ofxTuioCursor * _cursor);
    //好きにして…
        int getfromID();
        int getToID();
        int getCursorID();
    private:
    ofxTuioObject from,to;
    ofxTuioCursor tp;
    bool isEnd;
};
#endif // LINE_H_INCLUDED

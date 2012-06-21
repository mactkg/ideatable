#include "fingerCursor.h"

fingerCursor::fingerCursor(ofxTuioCursor * _cursor,bool position):ofxTuioCursor(_cursor){
    if(position==true)
        state=CURSOR_ACTIVE;
    else
        state=CURSOR_PASSIVE;
}

int fingerCursor::getState() {
    return state;
}

int fingerCursor::changeState(bool position) {
    if(state==CURSOR_ACTIVE) {
        if(position==false) {
            state=CURSOR_ON_LINE;
            return makeline;
        }
        return drawobj;
    }

    if(state==CURSOR_ON_LINE) {
        if(position==true) {
            state=CURSOR_ACTIVE;
            return lineend;
        }
        return drawline;
    }

    if(state==CURSOR_PASSIVE) {
        if(position==true) {
            state=CURSOR_ACTIVE;
            return drawobj;
        }
        return none;
    }
}

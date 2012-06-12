#include "fingerCursor.h"

int fingerCursor::getState()
{
    return state;
}

string fingerCursor::changeState(bool position)
{
    if(state==ACTIVE){
        if(position==true){
            return "drawobj";
        }else{
            state=LINE;
            return "makeline";
        }
    }
    
    if(state==LINE){
        if(position==true){
            state=ACTIVE;
            return "lineend";
        }else{
            return "drawline";
        }
    }
    
    if(state==PASSIVE){
        if(position==true){
            state=ACTIVE;
            return "drawobj";
        }else{
            return "none";
        }
    }
}

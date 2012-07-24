#ifndef FILEUTILITY_H_INCLUDED
#define FILEUTILITY_H_INCLUDED
#include <iostream>
#include "string.h"
string getFilePath(int _fid)
{
    string s;
    ifstream f(ofToString(_fid).c_str());
    if(!f) {
        return "";
    }
    f>>s;
    return s;
};
#endif // FILEUTILITY_H_INCLUDED

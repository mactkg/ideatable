#include "fileUtility.h"
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

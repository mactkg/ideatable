#include "picture.h"

PictureObj::PictureObj(ofxTuioObject * _object):ofxTuioObject(_object)
{
    default_angle=_object->getAngleDegrees(); //初期角度を所得するにはこれでいいん？
    setConfig(_object->getFiducialId());
}

/*idごとのコンフィグファイルを読み込み、データ抽出.
コンフィグファイルはbin/data/image/以下においておこう!!
*/
void PictureObj::setConfig(int fiducialId){
    
}

void PictureObj::update(ofxTuioObject * _object)
{
    ofxTuioObject::update(_object);
    image_mag=(default_angle-getAngleDegrees())/360;//初期角度との角度差をが倍率に比例する
}

bool PictureObj::isActionRange(ofxTuioCursor * _cursor) {
    if(_cursor->getX()>this->getX()&&_cursor->getY()>this->getY()&&
       _cursor->getX()<this->getX()+sizeX/ofGetWidth()&&_cursor->getY()<this->getY()+sizeY/ofGetHeight())
       return true;
    return false;
}

bool PictureObj::isRange(ofxTuioCursor * _cursor) {
    return isActionRange(_cursor);
}

void PictureObj::touchAction(ofxTuioCursor * _cursor) {
}

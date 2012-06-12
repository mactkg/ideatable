#include "picture.h"

PictureObj::PictureObj(ofxTuioObject * _object):ofxTuioObject(_object)
{
    setConfig(_object->getFiducialId());
}

/*idごとのコンフィグファイルを読み込み、データ抽出.
コンフィグファイルはbin/data/image/以下においておこう!!
*/
void PictureObj::setConfig(int fiducialId)
{
//    image.loadImage(getFilePath(fiducialId));
}

void PictureObj::draw()
{
    
}

void PictureObj::update(ofxTuioObject * _object)
{
    
}

void PictureObj::touch(ofxTuioCursor * _cursor)
{
    
}

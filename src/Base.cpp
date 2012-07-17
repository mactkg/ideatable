#include "Base.h"
/*TuioObjectのラッパーです。
書き方はsrc/Sample.cppを参考にしてくだしあ
*/
Base::Base(ofxTuioObject * _tuioObject) {
    //オブジェクトのIDで条件分岐
    x=_tuioObject->getX();
    y=_tuioObject->getY();
    if(_tuioObject->getFiducialId()<SAMPLE_NUM) {
        FID=_tuioObject->getFiducialId();
        sample.update(_tuioObject);
        index=1;//上から順番に番号をふる
    }
}

//マーカーIDの取得
int Base::getFiducialId() {
    return FID;
}

//描画処理
void Base::draw() {
    //indexに振り分けた番号でそのオブジェクトのdraw()を呼ぶ
    switch(index) {
    case 1:
        sample.draw();
        break;
    }
}

//状態の更新
void Base::update(ofxTuioObject * _tuioObject) {
    x=_tuioObject->getX();
    y=_tuioObject->getY();
    //draw()と同様に
    switch(index) {
    case 1:
        sample.update(_tuioObject);
        break;
    }
}

//X座標の取得
float Base::getX() {
    return x;
}

//Y座標の取得
float Base::getY() {
    return y;
}

//タッチ判定
bool Base::isActionRange(ofxTuioCursor * _tuioCursor) {
    switch(index) {
    case 1:
        return sample.isActionRange(_tuioCursor);
    }
}

bool Base::isRange(ofxTuioCursor * _tuioCursor) {
    switch(index) {
        case 1:
            return sample.isRange(_tuioCursor);
    }
}

void Base::touchAction(ofxTuioCursor * _cursor){
    switch(index) {
    case 1:
        sample.touchAction(_cursor);
    }
}

ofxTuioObject Base::getObject(){
    switch(index){
        case 1:
            return ofxTuioObject(sample.getSessionId(),
                                 sample.getFiducialId(),
                                 sample.getX(),
                                 sample.getY(),
                                 sample.getAngle());
    }
}

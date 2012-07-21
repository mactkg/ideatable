#include "Base.h"
/*TuioObjectのラッパーです。
書き方はsrc/Sample.cppを参考にしてくだしあ
*/
Base::Base(ofxTuioObject * _tuioObject) {
    //オブジェクトのIDで条件分岐
    o.update(_tuioObject);
    if(_tuioObject->getFiducialId()<=SAMPLE_NUM) {
        sample.update(_tuioObject);
        index=1;//上から順番に番号をふる
    } else if (SAMPLE_NUM<_tuioObject->getFiducialId()&&
               _tuioObject->getFiducialId()<=SAMPLE_NUM+BGM_NUM) {
        bgm.update(_tuioObject);
        index=2;
    }
}

//マーカーIDの取得
int Base::getFiducialId() {
    return o.getFiducialId();
}

//描画処理
void Base::draw() {
    //indexに振り分けた番号でそのオブジェクトのdraw()を呼ぶ
    switch(index) {
    case 1:
        sample.draw();
        break;
    case 2:
        bgm.draw();
        break;
    }
}

//状態の更新
void Base::update(ofxTuioObject * _tuioObject) {
    o.update(_tuioObject);
    //draw()と同様に
    switch(index) {
    case 1:
        sample.update(_tuioObject);
        break;
    case 2:
        bgm.update(_tuioObject);
        break;
    }
}

//X座標の取得
float Base::getX() {
    return o.getX();
}

//Y座標の取得
float Base::getY() {
    return o.getY();
}

//タッチ判定
bool Base::isActionRange(ofxTuioCursor * _tuioCursor) {
    switch(index) {
    case 1:
        return sample.isActionRange(_tuioCursor);
    case 2:
        return bgm.isActionRange(_tuioCursor);
    }
}

bool Base::isRange(ofxTuioCursor * _tuioCursor) {
    switch(index) {
        case 1:
            return sample.isRange(_tuioCursor);
        case 2:
            return bgm.isRange(_tuioCursor);
    }
}

void Base::touchAction(ofxTuioCursor * _cursor){
    switch(index) {
    case 1:
        sample.touchAction(_cursor);
    }
}

ofxTuioObject Base::getObject() {
    return o;
}
